// 정수론
#include <iostream>
using namespace std;

int n;

int getSol(){
    int res = 0;
    int res10 = 0;
    int restmp;
    int cnt = 0;

    // 1로 나누기
    if(n == 1) return 1;
    res = cnt = 1;

    // 10으로 나누기
    res10 = restmp = 10 % n;
    res += res10;
    cnt++;

    while(res != 0){
        restmp = (restmp * res10) % n;
        res = (restmp + res) % n;
        cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1){
        cin >> n;
        if(cin.eof()) break;
        cout << getSol() << "\n";
    }
}