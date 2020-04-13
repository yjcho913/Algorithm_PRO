// ************************************************************************************* //
// BOJ_6588_골드바흐의추측.cpp
// 정수론
// ************************************************************************************* //
#include <iostream>
using namespace std;
#define MAX (1000000)

int notPrime[MAX + 1];

void getPrimeNums(){
    int i, j;

    notPrime[1] = 1;
    for(i=3; i<=MAX; i+=2){
        if(notPrime[i] || 1LL * i * i > MAX) continue;

        for(j=i*i; j<=MAX; j+=(i<<1)){
            notPrime[j] = 1;
        }
    }
}

void getSol(){
    int n;
    int lim;
    int i;

    while(1){
        cin >> n;
        if(!n) return;

        lim = (n >> 1);
        for(i=3; i<=lim; i+=2){
            if(!notPrime[i] && !notPrime[n-i]){
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimeNums();
    getSol();
}