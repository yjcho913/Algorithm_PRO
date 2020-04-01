// ************************************************************************************* //
// BOJ_1644_소수의연속합.cpp
// 정수론 & 투포인터
// ************************************************************************************* //
#include <iostream>
using namespace std;

int N;
int primeNums[2000000];
int notPrime[4000000];

int getSol(){
    int len = 0;
    int sol = 0;
    int i, j;
    int sum = 0;

    cin >> N;
    notPrime[2] = 1;
    primeNums[len++] = 2;

    for(i=3; i <= N; i+=2){
        if(notPrime[i]) continue;
        primeNums[len++] = i;
        
        if(1LL * i*i > N) continue;
        for(j=i*i; j<=N; j+= (i<<1)){
            notPrime[j] = 1;
        }
    }

    for(i=0, j=-1; j < len;){
        if(sum < N) sum += primeNums[++j];
        else if(sum > N) sum -= primeNums[i++];
        else{
            sol++;
            sum += primeNums[++j];
            sum -= primeNums[i++];
        }
    }

    return sol;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << getSol() << "\n";
}