// 플로이드-워샬
#if 0
#include <stdio.h>
#define INF (510)

int N, M;
int D[510][510];

void input(){
    int n1, n2;
    int i, j;

    scanf("%d %d", &N, &M);
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            D[i][j] = INF;
        }
    }

    while(M--){
        scanf("%d %d", &n1, &n2);
        D[n1][n2] = 1;
    }
}

int getSol(){
    int k, i, j;
    int tmp;
    int ans = 0;

    for(k=1; k<=N; k++){
        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){
                tmp = D[i][k] + D[k][j];
                if(tmp < D[i][j]) D[i][j] = tmp;
            }
        }
    }

    // check
    for(i=1; i<=N; i++){
        tmp = 0;
        for(j=1; j<=N; j++){
            if(D[i][j] < INF || D[j][i] < INF) tmp++;
        }
        if(tmp == N-1) ans++;
    }
    return ans;
}

int main(){
    input();
    printf("%d\n", getSol());
}
#endif

// bfs
// 가중치가 1일때는 가장 빠름
#if 01
#include <stdio.h>
#include <vector>
using namespace std;
#define INF (510)

int N, M;
int D[510][510];
vector<int> linkList[510];
int QUE[510];
int WP, RP;

void input(){
    int n1, n2;
    int i, j;

    scanf("%d %d", &N, &M);
    while(M--){
        scanf("%d %d", &n1, &n2);
        linkList[n1].push_back(n2);
    }
}

int getSol(){
    int k, i, j;
    int out;
    int tmp;
    int ans = 0;

    for(k=1; k<=N; k++){
        WP = RP = 0;
        QUE[WP++] = k;
        
        while(WP > RP){
            out = QUE[RP++];
            
            for(int next : linkList[out]){
                if(D[k][next]) continue;
                D[k][next] = 1;
                QUE[WP++] = next;
            }
        }
    }
    
    // check
    for(i=1; i<=N; i++){
        tmp = 0;
        for(j=1; j<=N; j++){
            if(D[i][j] || D[j][i]) tmp++;
        }
        if(tmp + 1 == N) ans++;
    }
    return ans;
}

int main(){
    input();
    printf("%d\n", getSol());
}
#endif