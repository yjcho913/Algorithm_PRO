// 정수론
#include <iostream>
using namespace std;

int N, K;
int visited[1001];

int getSol(){
    int pos;
    int i, j;

    if(K <= N/2) return 2*K;
    
    pos = N/2;
    for(i=3;;i+=2){
        if(visited[i]) continue;

        visited[i] = 1;
        if((++pos) == K) return i;

        for(j=i*3; j<=N; j+=(i<<1)){
            if(visited[j]) continue;
            visited[j] = 1;
            if((++pos) == K) return j;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    cout << getSol() << "\n";
}