// 플로이드-워셜 알고리즘
#include <iostream>
using namespace std;
#define NMAX (100)
#define INF (10000100)

int N, M;
int cost[NMAX + 10][NMAX + 10];

void input(){
    int i, j, c;

    cin >> N >> M;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            cost[i][j] = INF;
        }
        cost[i][i] = 0;
    }

    while(M--){
        cin >> i >> j >> c;
        if(c < cost[i][j]) cost[i][j] = c;
    }
}

void getSol(){
    int i, j, k;
    int tmp;

    for(k=1; k<=N; k++){
        for(i=1; i<=N; i++){
            if(cost[i][k] == INF) continue;
            for(j=1; j<=N; j++){
                tmp = cost[i][k] + cost[k][j];
                if(tmp < cost[i][j]) cost[i][j] = tmp;
            }
        }
    }

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(cost[i][j] == INF) cout << 0 << ' ';
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    getSol();
}