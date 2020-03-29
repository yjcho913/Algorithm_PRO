// ************************************************************************************* //
//BOJ_10775_공항.cpp
// find-union
// ************************************************************************************* //
#include <iostream>
using namespace std;
#define GMAX (100000)

int G, P;
int gates[GMAX + 10];

int findGate(int g){
    if(gates[g] == g) return g;
    return gates[g] = findGate(gates[g]);
}

int getSol(){
    int i, j;
    int root;
    int plane;

    for(i=1; i<=G; i++) gates[i] = i;

    for(i=1; i<=P; i++){
        cin >> plane;
        root = findGate(plane);
        if(root == 0) break;
        gates[root] = gates[root - 1];
    }

    return i-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> G >> P;
    cout << getSol() << "\n";
}