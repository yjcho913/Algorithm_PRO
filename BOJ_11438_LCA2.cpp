// LCA
#include <stdio.h>
#include <queue>
using namespace std;
#define TWOMAX (16)
#define NMAX (100000)

int N, M;
int P[TWOMAX + 1][NMAX + 10];
int twoSquare[TWOMAX + 1];
int depth[NMAX + 10];
typedef struct st{
    int first, second;
}PAIR;

void input(){
    int n1, n2;
    int i, j;
    queue<PAIR> q;
    PAIR p;

    P[0][1] = 1;
    depth[1] = 0;
    scanf("%d", &N);
    for(i=1; i<N; i++){
        scanf("%d %d", &n1, &n2);
        if(P[0][n1]) {
            P[0][n2] = n1;
            depth[n2] = depth[n1] + 1;
        }
        else if(P[0][n2]) {
            P[0][n1] = n2;
            depth[n1] = depth[n2] + 1;
        }
        else q.push((PAIR){n1, n2});
    }

    while(!q.empty()){
        p = q.front(); q.pop();
        if(P[0][p.first]) {
            P[0][p.second] = p.first;
            depth[p.second] = depth[p.first] + 1;
        }
        else if(P[0][p.second]){
            P[0][p.first] = p.second;
            depth[p.first] = depth[p.second] + 1;
        }
        else q.push(p);
    }

    for(i=1; i<=TWOMAX; i++){
        for(j=2; j<=N; j++){
            P[i][j] = P[i-1][P[i-1][j]];
        }
    }
}

void makeTwoSquare(){
    int i;

    twoSquare[0] = 1;
    for(i=1; i<=TWOMAX; i++){
        twoSquare[i] = (twoSquare[i-1]<<1);
    }
}

void getSol(){
    int a, b;
    int tmp;
    int diff;
    int i;

    scanf("%d", &M);
    while(M--){
        scanf("%d %d", &a, &b);
        
        // 크기 비교
        if(depth[b] > depth[a]){
            tmp = a;
            a = b;
            b = tmp;
        }

        // depth 맞추기
        diff = depth[a] - depth[b];
        for(i=TWOMAX; i>=0; i--){
            if(diff == 0) break;
            if(twoSquare[i] <= diff) {
                diff -= twoSquare[i];
                a = P[i][a];
            }
        }
        if(a == b){
            printf("%d\n", a);
            continue;
        }

        // lca 찾기
        for(i=TWOMAX; i>=0; i--){
            if(twoSquare[i] <= depth[a]){
                if(P[i][a] != P[i][b]){
                    a = P[i][a];
                    b = P[i][b];
                }
            }
        }
        
        printf("%d\n", P[0][a]);
    }
}

int main(){
    input();
    makeTwoSquare();
    getSol();
}