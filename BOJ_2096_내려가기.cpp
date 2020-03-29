// 이중배열보다 일차원배열이 훨씬 빠름 (접근 횟수 감소)
// arr[100100][3] ---> arr[3]
#include <stdio.h>
#define MAX(x, y) ((x)>(y) ? (x): (y))
#define MIN(x, y) ((x)<(y) ? (x): (y))

int N;
int arr[3];
int mnarr[3];
int mxarr[3];
int mx, mn;

void getSol(){
    int i;

    scanf("%d %d %d %d", &N, &arr[0], &arr[1], &arr[2]);
    for(i=0; i<3; i++){
        mxarr[i] = mnarr[i] = arr[i];
    }

    for(i=1; i<N; i++){
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        // 최대
        mxarr[0] = MAX(mxarr[0], mxarr[1]);
        mxarr[2] = MAX(mxarr[1], mxarr[2]);
        mxarr[1] = MAX(mxarr[0], mxarr[2]) + arr[1];
        mxarr[0] += arr[0];
        mxarr[2] += arr[2];
        // 최소
        mnarr[0] = MIN(mnarr[0], mnarr[1]);
        mnarr[2] = MIN(mnarr[1], mnarr[2]);
        mnarr[1] = MIN(mnarr[0], mnarr[2]) + arr[1];
        mnarr[0] += arr[0];
        mnarr[2] += arr[2];
    }
    mx = MAX(mxarr[0], MAX(mxarr[1], mxarr[2]));
    mn = MIN(mnarr[0], MIN(mnarr[1], mnarr[2]));
}

int main(){
    getSol();
    printf("%d %d\n", mx, mn);
}