#include <stdio.h>
#include <algorithm>
using namespace std;

int A[4010], B[4010], C[4010], D[4010];
int sumAB[16000100], sumCD[16000100];
int N;

void input(){
    int i;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }
}

long long getSol(){
    long long ans = 0;
    int tmp = 0;
    int tsum;
    int i, j, k;
    long long ti, tj;
    
    // 합 배열 만들기
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            sumAB[tmp] = A[i] + B[j];
            sumCD[tmp++] = C[i] + D[j];
        }
    }

    // 오름차순 정렬
    sort(sumAB, sumAB + tmp);
    sort(sumCD, sumCD + tmp);

    // 탐색하며 합이 0인 개수 찾기
    for(i = 0, j = tmp-1; (i<tmp)&&(j>=0);){
        tsum = sumAB[i] + sumCD[j];
        if(tsum == 0) {
            ti = tj = 1;
            for(k=i+1;;k++){
                if(sumAB[i] != sumAB[k] || k >= tmp) break;
                ti++;
            }
            for(k=j-1;;k--){
                if(sumCD[j] != sumCD[k] || k < 0) break;
                tj++;
            }
            i+=ti;
            j-=tj;
            ans+=ti*tj;
        }
        else if(tsum < 0) i++;
        else j--;
    }

    return ans;
}

int main(){
    input();
    printf("%lld\n", getSol());
}
