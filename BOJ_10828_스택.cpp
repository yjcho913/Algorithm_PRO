#include <stdio.h>

int N;
int stack[10010];
int PT;

void getSol(){
    char order[7];
    int num;

    while(N--){
        scanf("%s", order);
        if(order[0] == 'p'){
            // push
            if(order[1] == 'u') {
                scanf("%d", &num);
                stack[PT++] = num;
            }
            // pop
            else {
                printf("%d\n", PT==0 ? -1:stack[--PT]);
            }
        }
        // size
        else if(order[0] == 's') printf("%d\n", PT);
        // empty
        else if(order[0] == 'e') printf("%d\n", PT == 0 ? 1 : 0);
        // top
        else printf("%d\n", PT==0 ? -1:stack[PT - 1]);
    }
}

int main(){
    scanf("%d", &N);
    getSol();
}