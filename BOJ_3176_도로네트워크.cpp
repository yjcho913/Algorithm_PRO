// LCA
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define TWOMAX (16)
#define NMAX (100000)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int P[TWOMAX + 1][NMAX + 100];
int minDist[TWOMAX + 1][NMAX + 100];
int maxDist[TWOMAX + 1][NMAX + 100];
int depth[NMAX + 100];
int N, K;
typedef struct st{
    int next, d;
}CITY;
vector<CITY> connectList[NMAX + 1];
queue<int> que;
int twoSquare[TWOMAX + 1];

void input(){
    int n1, n2, d;
    int i, j;
    int out;
    int p;
    
    cin >> N;
    for(i=1; i<N; i++){
        cin >> n1 >> n2 >> d;
        connectList[n1].push_back((CITY){n2, d});
        connectList[n2].push_back((CITY){n1, d});
    }

    P[0][1] = 1;
    depth[1] = 0;
    que.push(1);

    while(!que.empty()){
        out = que.front(); que.pop();

        for(CITY city : connectList[out]){
            if(P[0][city.next]) continue;
            P[0][city.next] = out;
            minDist[0][city.next] = maxDist[0][city.next] = city.d;
            depth[city.next] = depth[out] + 1;
            que.push(city.next);
        }
    }
    
    minDist[0][1] = 1000000;
    for(i=1; i<=TWOMAX; i++){
        for(j=2; j<=N; j++){
            p = P[i-1][j];
            minDist[i][j] = MIN(minDist[i-1][j], minDist[i-1][p]);
            maxDist[i][j] = MAX(maxDist[i-1][j], maxDist[i-1][p]);
            P[i][j] = P[i-1][p];
        }
    }
}

void makeTwoSquare(){
    int i;

    twoSquare[0] = 1;
    for(i=1; i<=TWOMAX; i++){
        twoSquare[i] = twoSquare[i-1]<<1;
    }
}

void getSol(){
    int a, b, tmp;
    int diff, i;
    int minSol, maxSol;

    cin >> K;

    while(K--){
        cin >> a >> b;
        minSol = 1000000;
        maxSol = 0;

        if(depth[b] > depth[a]){
            tmp = a;
            a = b;
            b = tmp;
        }

        diff = depth[a] - depth[b];
        for(i=TWOMAX; i>=0; i--){
            if(diff == 0) break;
            if(twoSquare[i] <= diff){
                if(minDist[i][a] < minSol) minSol = minDist[i][a];
                if(maxDist[i][a] > maxSol) maxSol = maxDist[i][a];
                diff -= twoSquare[i];
                a = P[i][a];
            }
        }
        if(a == b){
            cout << minSol << ' ' << maxSol << '\n';
            continue;
        }

        for(i=TWOMAX; i>=0; i--){
            if(twoSquare[i] <= depth[a]){
                if(P[i][a] != P[i][b]){
                    tmp = MIN(minDist[i][a], minDist[i][b]);
                    if(tmp < minSol) minSol = tmp;
                    tmp = MAX(maxDist[i][a], maxDist[i][b]);
                    if(tmp > maxSol) maxSol = tmp;
                    a = P[i][a];
                    b = P[i][b];
                }
            }
        }

        tmp = MIN(minDist[0][a], minDist[0][b]);
        if(tmp < minSol) minSol = tmp;
        tmp = MAX(maxDist[0][a], maxDist[0][b]);
        if(tmp > maxSol) maxSol = tmp;
        cout << minSol << ' ' << maxSol << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    makeTwoSquare();
    getSol();
}