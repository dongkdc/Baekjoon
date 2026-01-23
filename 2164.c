#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N,cnt;
    scanf("%d",&N);

    int* que = (int*)malloc(sizeof(int)*N*2);

    for(int i=0;i<N;i++){
        que[i] = i+1;
    }
    int back = N-1;
    int front = 0;

    cnt = N;
    while(cnt!=1){
        int temp;

        // pop (제일 위 카드)
        front++;
        // 두 번째 카드 저장
        temp = que[front];
        front++;
        // push
        que[++back] = temp;
        cnt--;
    }
    
    printf("%d",que[front]);
    free(que);
}