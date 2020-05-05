// ************************************************************************************* //
// BOJ_14003_가장긴증가하는부분수열5.cpp
// DP - LIS
// ************************************************************************************* //
#include <iostream>
using namespace std;
#include <stack>

int N;
int arr[1000100];
int lens[1000100];
int incList[1000100];
stack<int> ST;
int sol = 1;

int getPosition(int goal, int r){
    int m;
    int l = 1;

    if(goal <= incList[l]) return l;
    if(goal > incList[r]) return r+1;

    while(l <= r){
        m = (l + r)/2;
        if(incList[m] < goal){
            l = m + 1;
        }
        else if(incList[m] > goal){
            r = m - 1;
        }
        else return m;
    }

    return l;
}

void getLength(){
    int i;
    int pos;

    cin >> arr[0];
    incList[1] = arr[0];
    lens[0] = 1;

    for(i=1; i<N; i++){
        cin >> arr[i];
        
        pos = getPosition(arr[i], sol);
        if(pos > sol) sol = pos;
        incList[pos] = arr[i];
        lens[i] = pos;
    }
}

void printSol(){
    int i;
    int j = 0;

    for(i=N-1; sol > 0; i--){
        if(lens[i] == sol){
            sol--;
            ST.push(arr[i]);
        }
    }

    while(!ST.empty()){
        cout << ST.top() << " ";
        ST.pop();
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    getLength();
    cout << sol << "\n";
    printSol();
}