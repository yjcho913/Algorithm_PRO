// 다 익스트라
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NMAX (800)
#define INF (200000100)

int N, E;
typedef pair<int, int> pii;
vector<pii> linkList[NMAX + 10];
priority_queue<pii, vector<pii>, greater<pii> > pq; 
int n1, n2;
int cost[NMAX + 10];

void input(){
    int a, b, c;

    cin >> N >> E;
    while(E--){
        cin >> a >> b >> c;
        linkList[a].push_back(make_pair(c, b));
        linkList[b].push_back(make_pair(c, a));
    }
    cin >> n1 >> n2;
}

void dijkstra(int s){
    pii out;
    int tmp;

    pq.push(make_pair(cost[s], s));
    
    while(!pq.empty()){
        out = pq.top(); pq.pop();
        if(cost[out.second] < out.first) continue;

        for(pii next: linkList[out.second]){
            tmp = next.first + cost[out.second];
            if(tmp < cost[next.second]){
                cost[next.second] = tmp;
                pq.push(make_pair(tmp, next.second));
            }
        }
    }
}

int getSol(){
    int i;
    int n1n2, n2n1;

    // 1번이 시작점인 다익스트라
    cost[1] = (INF<<1);
    for(i=2; i<=N; i++){
        cost[i] = (INF<<2);
    }
    dijkstra(1);

    // 1-n1 & 1-n2 경로 확인
    n1n2 = cost[n1] - (INF<<1);
    n2n1 = cost[n2] - (INF<<1);
    if(n1n2 == (INF<<2) && n2n1 == (INF<<2)) return -1;

    // N번이 시작점인 다익스트라
    cost[N] = INF;
    dijkstra(N);

    // n1-N & n2-N 경로 확인
    n1n2 += cost[n2] - INF;
    n2n1 += cost[n1] - INF;
    if(n1n2 >= INF || n2n1 >= INF) return -1;

    // n1번이 시작점인 다익스트라
    cost[n1] = 0;
    dijkstra(n1);

    // n1-n2 경로 존재하는지 확인 & return
    if(cost[n2] >= INF) return -1;
    return ((n1n2 < n2n1) ? n1n2 : n2n1) + cost[n2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << getSol() << "\n";
}