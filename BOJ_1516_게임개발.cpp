// 위상정렬
#include <stdio.h>
#include <vector>
using namespace std;

int N;
int inDegree[510];
vector<int> linkList[510];
int QUE[510];
int t[510];
int ans[510];
int WP, RP;

void input(){
    int num;
    int i;

    scanf("%d", &N);
    // 벡터 & indgree배열 초기화 필요

    for(i=1; i<=N; i++){
        scanf("%d %d", &t[i], &num);
        while(num != -1){
            linkList[num].push_back(i);
            inDegree[i]++;
            scanf("%d", &num);
        }
    }
}

int max(int x, int y){return x>y ? x: y;}

void getSol(){
    int i;
    int out;

    for(i=1; i<=N; i++){
        if(!inDegree[i]) QUE[WP++] = i;
    }

    ans[QUE[RP]] = t[QUE[RP]];
    while(WP > RP){
        out = QUE[RP++];

        for(int next : linkList[out]){
            ans[next] = max(ans[next], ans[out] + t[next]);
            if(!--inDegree[next]) QUE[WP++] = next;
        }
    }

    for(i=1; i<=N; i++) printf("%d\n", ans[i]);
}

int main(){
    input();
    getSol();
}