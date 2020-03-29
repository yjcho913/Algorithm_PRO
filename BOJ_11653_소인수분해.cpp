// 정수론
#include <iostream>
using namespace std;

int n;

int main(){
    int i;

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(i=2; i*i <= n;){
        if(n%i == 0) {
            cout << i << "\n";
            n /= i;
        }
        else i++;
    }

    if(n > 1) cout << n << "\n";
}