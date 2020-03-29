// binary search
#include <iostream>
using namespace std;
#define KMAX (10000)

int K;
long long N;
long long lines[KMAX + 10];
long long maxLine;

void input(){
    int i;

    cin >> K >> N;
    for(i=0; i<K; i++){
        cin >> lines[i];
        if(lines[i] > maxLine) maxLine = lines[i];
    }
}

int binarySearch(){
    long long s = 1;
    long long e = maxLine + 1;
    long long m;
    long long tmp;
    int i;
    int sol = 1;

    while(s <= e){
        m = (s + e) / 2;
        tmp = 0;
        for(i=0; i<K; i++) tmp += lines[i]/m;
        if(tmp < N) e = m - 1;
        else {
            s = m + 1;
            sol = m;
        }
    }

    return sol;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << binarySearch() << "\n";
}