// 정수론
#include <iostream>
#include <string.h>
using namespace std;

char instr[100100];
int nums[10];

void getSol(){
    int i, j;
    int sum = 0;
    int len = strlen(instr);
    int pos = 0;

    for(i=0; i<len; i++){
        nums[instr[i] - '0']++;
    }

    for(i=1; i<10; i++){
        sum += i * nums[i];
    }

    if(nums[0] == 0 || sum%3 != 0) {
        cout << "-1\n";
        return;
    }

    for(i=9; i>=0; i--){
        for(j=0; j<nums[i]; j++){
            instr[pos++] = i + '0';
        }
    }
    cout << instr << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> instr;
    getSol();
}