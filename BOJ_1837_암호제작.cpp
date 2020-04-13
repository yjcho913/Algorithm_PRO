// ************************************************************************************* //
// BOJ_1837_암호제작.cpp
// 정수론
// ************************************************************************************* //
#include <iostream>
#include <string.h>
using namespace std;

char strP[110];
int K;
char notPrime[1000001];

int zeroRemainder(int q){
    int pos = 0;
    int pLen = strlen(strP);
    int p = 0;
    
    for(pos = 0; pos < pLen; pos++){
        p *= 10;
        p += strP[pos] - '0';
        p %= q;
    }
    
    return (p == 0) ? 1 : 0;
}

void getSol(){
    int i, j;

    if(zeroRemainder(2) == 1){
        if(K == 2) cout << "GOOD\n";
        else cout << "BAD 2\n";
        return;
    }

    for(i=3; i < K; i+=2){
        if(notPrime[i]) continue;
        if(zeroRemainder(i) == 1){
            cout << "BAD " << i << "\n";
            return;
        }
        
        if(1LL * i * i >= K) continue;
        for(j=i*i; j < K; j += (i<<1)){
            notPrime[j] = 1;
        }
    }
    
    cout << "GOOD\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> strP >> K;
    getSol();
}