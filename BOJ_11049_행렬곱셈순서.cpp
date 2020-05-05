// ************************************************************************************* //
// BOJ_11049_행렬곱셈순서.cpp
// DP
// ************************************************************************************* //
#include <iostream>
#include <limits.h>
using namespace std;
#define NMAX (500)

int N;
int rows[NMAX + 10];
int cols[NMAX + 10];
int D[NMAX + 10][NMAX + 10];

void input(){
    int i;

    cin >> N;
    for(i = 0; i < N; i++){
        cin >> rows[i];
        cin >> cols[i];
    }
}

int getSol(){
    int i, j, k;
    int tmp;

    for(i=0; i<N-1; i++) D[i][i + 1] = rows[i] * cols[i] * cols[i + 1];

    for(j = 2; j < N; j++){
        for(i = 0; i + j < N; i++){
            D[i][i + j] = INT_MAX;
            for(k = i; k < i + j; k++){
                tmp = D[i][k] + D[k + 1][i + j] + rows[i] * rows[k + 1] * cols[i + j];
                if(D[i][i + j] > tmp) D[i][i + j] = tmp;
            }
        }
    }

    return D[0][N-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << getSol() << "\n";
}