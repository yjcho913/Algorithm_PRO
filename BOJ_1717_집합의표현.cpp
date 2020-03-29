// find-union
#include <stdio.h>

int n, m;
int parent[1000010];

int findRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}

void myUnion(int a, int b){
    parent[findRoot(parent[a])] = findRoot(parent[b]);
}

void getSol(){
    int order, a, b;
    int i;

    for(i = 0; i <= n; i++) parent[i] = i;
    while(m--){
        scanf("%d %d %d", &order, &a, &b);
        // union
        if(order == 0) myUnion(a, b);
        else printf("%s\n", findRoot(a) == findRoot(b) ? "YES" : "NO");
    }
}

int main(){
    scanf("%d %d", &n, &m);
    getSol();
}