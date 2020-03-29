#include <stdio.h>

int N;
int QUE[10010];
int WP, RP;

/*
명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

void getSol(){
    char order[6];
    int num;

    while(N--){
        scanf("%s", order);
        if(order[0] == 'p'){
            // push
            if(order[1] == 'u'){
                scanf("%d", &num);
                QUE[WP++] = num;
            }
            // pop
            else printf("%d\n", WP == RP ? -1 : QUE[RP++]);
        }
        // size
        else if(order[0] == 's') printf("%d\n", WP - RP);
        // empty
        else if(order[0] == 'e') printf("%d\n", WP == RP ? 1 : 0);
        // back
        else if(order[0] == 'b') printf("%d\n", WP == RP ? -1 : QUE[WP - 1]);
        // front
        else printf("%d\n", WP == RP ? -1 : QUE[RP]);
    }
}

int main(){
    scanf("%d", &N);
    getSol();
}