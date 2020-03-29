// 다 익스트라
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX (500)
#define MMAX (10000)
#define INF (500000)
#define INFINF (1000000)

int N, M;
int S, D;
typedef pair<int, int> pii;
vector<pii> linkList[NMAX + 10];
vector<int> prevList[NMAX + 10];
int cost[NMAX + 10];
priority_queue<pii, vector<pii>, greater<pii> > pq;
queue<int> que;

int getSol(int t){
    int U, V, P;
    int i;
    pii out;
    int tmp;
    int iout;
    vector<pii>::iterator iter;

    // 초기화
    for(i=0; i<N; i++){
        cost[i] = INFINF;
        linkList[i].clear();
        prevList[i].clear();
    }

    // 입력
    cin >> S >> D;
    while(M--){
        cin >> U >> V >> P;
        linkList[U].push_back(make_pair(P, V));
    }
    
    // 다익스트라 - 최단경로
    cost[S] = INF;
    pq.push(make_pair(0, S));

    while(!pq.empty()){
        out = pq.top(); pq.pop();

        if(cost[out.second] < out.first) continue;

        for(pii vertex : linkList[out.second]){
            tmp = cost[out.second] + vertex.first;
            if(tmp < cost[vertex.second]){
                cost[vertex.second] = tmp;
                pq.push(make_pair(tmp, vertex.second));
                prevList[vertex.second].clear();
                prevList[vertex.second].push_back(out.second);
            }
            else if(tmp == cost[vertex.second]){
                pq.push(make_pair(tmp, vertex.second));
                prevList[vertex.second].push_back(out.second);
            }
        }
    }
    if(cost[D] == INFINF) return -1;

    // 최단 경로 걸러내기
    que.push(D);
    while(!que.empty()){
        iout = que.front(); que.pop();

        for(int next : prevList[iout]){
            for(iter = linkList[next].begin();;iter++){
                if(iter->second == iout){
                    iter->first = INFINF;
                    break;
                }
            }
            if(next == S) continue;
            que.push(next);
        }
    }

    // 다익스트라 - 거의 최단 경로
    cost[S] = 0;
    pq.push(make_pair(0, S));

    while(!pq.empty()){
        out = pq.top(); pq.pop();

        if(cost[out.second] < out.first) continue;

        for(pii vertex : linkList[out.second]){
            tmp = cost[out.second] + vertex.first;
            if(tmp < cost[vertex.second]){
                cost[vertex.second] = tmp;
                pq.push(make_pair(tmp, vertex.second));
            }
        }
    }
    return cost[D] > INF ? -1 : cost[D];
}

int main(){
    int t = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1){
        t++;
        cin >> N >> M;
        if(N == 0 && M == 0) return 0;
        cout << getSol(t) << "\n";
    }
}