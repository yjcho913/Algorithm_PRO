// ************************************************************************************* //
// BOJ_2579_계단오르기.cpp
// DP
// ************************************************************************************* //
#include <iostream>
using namespace std;
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int N;
int score[2][310];

int getSol(){
    int i;
    int cur;

    cin >> N >> score[0][1];
    
    for(i=2; i<=N; i++){
        cin >> cur;
        score[0][i] = MAX(score[0][i-2], score[1][i-2]) + cur;
        score[1][i] = score[0][i-1] + cur;
    }

    return MAX(score[0][N], score[1][N]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cout << getSol() << "\n";
}