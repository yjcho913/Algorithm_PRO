#include <stdio.h>

int N, S;
int nums[100100];

void input(){
    int i;
    
    scanf("%d %d", &N, &S);
    for(i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }
}

int getSol(){
    int ans = 100100;
    int s = 0;
    int e = -1;
    int sum = 0;
    
    while(e < N){
        if(e-s+1 >= ans) sum -= nums[s++];
        else if(sum >= S){
            ans = e-s+1;
            sum -= nums[s++];
        }
        else sum += nums[++e];
    }

    return (ans > 100000) ? 0 : ans;
}

int main(){
    input();
    printf("%d\n", getSol());
}