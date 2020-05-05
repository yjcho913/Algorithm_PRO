// ************************************************************************************* //
// BOJ_1160_RandomNumberGenerator.cpp
// DP
// 첫째 줄에 6개의 정수 m, a, c, X0, n, g (m, a, c, X0, n ≤ 10e+18, g ≤ 10e+8)가 차례대로 주어진다. a, c, X0는 음이 아닌 정수이고 m, n, g는 양의 정수이다.
// ************************************************************************************* //
#include <iostream>
using namespace std;

long long m, a, c, n, g;
long long x0;
long long an = 1;
long long a2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> a >> c >> x0 >> n >> g;

    // a^n 구하기
    a %= m;
    c %= m;
    a2 = a;
    while(n){
        if(n&1){
            an *= a2;
            an %= m;
        }
        a2 *= a2;
        a2 %= m;
        n >>= 1;
    }

    cout << ((((an%g) * (x0%g)) + (c * (an - 1) / (a-1)) % m) % g << "\n";
}