// ************************************************************************************* //
// BOJ_11659_구간합구하기4.cpp
// DP
// ************************************************************************************* //
#include <iostream>
using namespace std;
#define NMAX (100000)

int N, M;
int cumSum[NMAX + 10];

void input(){
    int i;

    cin >> N >> M;
    
    for(i=1; i<=N; i++){
        cin >> cumSum[i];
        cumSum[i] += cumSum[i-1];
    }
}

void getSol(){
    int s, e;

    while(M--){
        cin >> s >> e;
        cout << cumSum[e] - cumSum[s - 1] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    getSol();
}