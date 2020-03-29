#include <stdio.h>

long long x, y;
long long z;
long long ans;
int tmp;

int main(){
    scanf("%lld %lld", &x, &y);
    
    z = y*100/x;
    if(z >= 99) ans = -1;
    else{
        ans = x + z*x - 100 * y;
        tmp = 99 - z;
        ans = (ans % tmp == 0) ? ans / tmp : ans / tmp + 1;
    }
    printf("%lld\n", ans);
}