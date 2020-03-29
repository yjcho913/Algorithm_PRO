#include <iostream>
using namespace std;
#define PMAX (100000)
#define GMAX (100000)

int G, P;
int planes[PMAX + 10];
int gates[GMAX + 10];

void input(){
    int i;

    cin >> G >> P;
    for(i=1; i<=P; i++){
        cin >> planes[i];
    }
}

int findGate(int g){
    if(gates[g] == g) return g;
    return gates[g] = findGate(gates[g]);
}

void unionGate(int g){
    gates[g] = gates[gates[g] - 1];
    
}
int getSol(){
    int i, j;
    int root;

    for(i=1; i<=G; i++) gates[i] = i;

    for(i=1; i<=P; i++){
        root = findGate(planes[i]);
        if(root == 0) break;
        gates[root] = gates[root - 1];
    }

    return i-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << getSol() << "\n";
}