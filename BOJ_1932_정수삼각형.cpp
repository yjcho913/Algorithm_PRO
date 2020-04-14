// ************************************************************************************* //
// BOJ_1932_정수삼각형.cpp
// DP
// ************************************************************************************* //
#include <iostream>
using namespace std;
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int n;
int triangle[510][510];

void input(){
    int i, j;

    cin >> n;
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            cin >> triangle[i][j];
        }
    }
}

int getSol(){
    int i, j;

    for(i=n-1; i>0; i--){
        for(j=1; j<=i; j++){
            triangle[i][j] += MAX(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    return triangle[1][1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << getSol() << "\n";
}