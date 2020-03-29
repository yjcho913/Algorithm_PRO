// MST(최소 스패닝 트리)
// 크루츠칼 알고리즘
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
typedef struct st{
    int s, e, cost;
}EDGE;
EDGE edgeList[100010];
int parent[1010];

bool comp(const EDGE& a, const EDGE& b){
    return a.cost < b.cost;
}

void input(){
    int i;
    int a, b, c;

    scanf("%d %d", &N, &M);
    for(i=0; i<M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edgeList[i] = (EDGE){a, b, c};
    }
    sort(edgeList, edgeList + M, comp);
}

int findRoot(int x){
    if(x == parent[x]) return x;
    return parent[x] = findRoot(parent[x]);
}

void myUnion(int a, int b){
    parent[findRoot(parent[a])] = findRoot(parent[b]);
}

int getSol(){
    int i;
    int ans = 0;
    int s, e;
    int cnt = 0;

    for(i=1; i<=N; i++) parent[i] = i;

    for(i=0; i<M; i++){
        s = edgeList[i].s;
        e = edgeList[i].e;
        if(findRoot(s) == findRoot(e)) continue;
        myUnion(s, e);
        ans += edgeList[i].cost;
        if((++cnt) >= N - 1) break; 
    }

    return ans;
}

int main(){
    input();
    printf("%d\n", getSol());
}