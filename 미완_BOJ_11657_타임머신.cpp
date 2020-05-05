// 벨만-포드 알고리즘
#include <iostream>
using namespace std;
#define NMAX (500)
#define MMAX (6000)
#define START (0)
#define END (1)
#define TIME (2)
#define INF (60000100)

int N, M;
int linkArr[MMAX + 10][3];
int cost[NMAX + 10];

void input(){
    int i;

    cin >> N >> M;

    for(i=0; i<M; i++){
        cin >> linkArr[i][START] >> linkArr[i][END] >> linkArr[i][TIME];
    }
}

void getSol(){
    int i;
    int tmp;
    int prev;
    int tot = N-1;

    for(i=2; i<=N; i++){
        cost[i] = INF;
    }
    
    while(tot--){
        for(i=0; i<M; i++){
            prev = cost[linkArr[i][START]];
            if(prev == INF) continue;

            tmp = prev + linkArr[i][TIME];
            if(tmp < cost[linkArr[i][END]]){
                cost[linkArr[i][END]] = tmp;
            }
        }
    }

    for(i=0; i<M; i++){
        prev = cost[linkArr[i][START]];
        if(prev == INF) continue;

        tmp = prev + linkArr[i][TIME];
        if(tmp < cost[linkArr[i][END]]){
            cout << -1 << "\n";
            return;
        }
    }
    
    for(i=2; i<=N; i++){
        cout << ((cost[i] == INF) ? -1 : cost[i]) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    getSol();
}