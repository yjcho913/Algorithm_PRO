#include <stdio.h>

int N;
long long a1, a2, a3;

int main(){
    scanf("%d", &N);

    // get solution
    a1 = a2 = a3 = 1;

    while(N>2){
        a3 = a1+a2;
        a1 = a2;
        a2 = a3;
        N--;
    }
    printf("%lld\n", a3);
}