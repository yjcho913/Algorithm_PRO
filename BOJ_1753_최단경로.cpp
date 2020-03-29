// 다 익스트라
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define VMAX (20000)
#define INF (200010)

int V, E, K;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq;
vector<pi> linkList[VMAX + 10];
int cost[VMAX + 10];

void input(){
    int u, v, w;

    cin >> V >> E >> K;
    while(E--){
        cin >> u >> v >> w;
        linkList[u].push_back(make_pair(w, v));
    }
}

void getSol(){
    int i;
    pi out;
    int tmp;

    for(i=1; i<=V; i++){
        cost[i] = INF;
    }
    cost[K] = 0;
    pq.push(make_pair(0, K));

    while(!pq.empty()){
        out = pq.top(); pq.pop();
        if(cost[out.second] < out.first) continue;

        for(pi vertex : linkList[out.second]){
            tmp = cost[out.second] + vertex.first;
            if(tmp < cost[vertex.second]){
                cost[vertex.second] = tmp;
                pq.push(make_pair(tmp, vertex.second));
            }
        }
    }

    for(i=1; i<=V; i++){
        if(cost[i] == INF) cout << "INF" << "\n";
        else cout << cost[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    getSol();
}