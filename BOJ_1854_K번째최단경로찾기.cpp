// 다 익스트라
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX (1000)
#define KMAX (100)
#define SIZE (0)

int N, M, K;
typedef pair<int, int> pii;
vector<pii> linkList[NMAX + 10];
priority_queue<pii, vector<pii>, greater<pii> > pq;
priority_queue<int> cost[NMAX + 10];

void input(){
    int a, b, c;

    cin >> N >> M >> K;

    while(M--){
        cin >> a >> b >> c;
        linkList[a].push_back(make_pair(c, b));
    }
}

void getSol(){
    pii out;
    int i;
    int tmp;

    pq.push(make_pair(0, 1));
    cost[1].push(0);

    while(!pq.empty()){
        out = pq.top(); pq.pop();

        for(pii next : linkList[out.second]){
            tmp = next.first + out.first;
            if(cost[next.second].size() < K) {
                cost[next.second].push(tmp);
            } else if(tmp < cost[next.second].top()){
                cost[next.second].pop();
                cost[next.second].push(tmp);
            } else continue;

            pq.push(make_pair(tmp, next.second));
        }
    }

    for(i=1; i<=N; i++){
        if(cost[i].size() < K) cout << -1 << "\n";
        else cout << cost[i].top() << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    getSol();
}