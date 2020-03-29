// 위상정렬
#include <stdio.h>
#include <vector>
using namespace std;

int N, M;
int inDegree[32010];
vector<int> linkList[32010];
int QUE[32010];
int WP, RP;

void input(){
    int a, b;
    int i;

    scanf("%d %d", &N, &M);
    // 벡터 & indgree배열 초기화 필요

    while(M--){
        scanf("%d %d", &a, &b);
        linkList[a].push_back(b);
        inDegree[b]++;
    }
}

void getSol(){
    int i;
    int out;
    int tmp;

    for(i=1; i<=N; i++){
        if(!inDegree[i]) QUE[WP++] = i;
    }

    while(WP > RP){
        out = QUE[RP++];
        printf("%d ", out);

        for(int next : linkList[out]){
            if(!--inDegree[next]) QUE[WP++] = next;
        }
    }
    printf("\n");
}

int main(){
    input();
    getSol();
}