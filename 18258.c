#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pop(int* que,int cnt){
    int temp;
   
    // 제일 앞의 값 제거 및 출력
    temp = que[0];
    for(int i=1;i<cnt;i++){
        que[i-1] = que[i];
    }
    return temp;
}

int main(void){
    int N;
    scanf("%d",&N);
    
    // N의 최대크기가 크기때문에 동적할당으로 선언
    // 입력되는 값은 1이상이므로 0으로 초기화를 위한 calloc 이용
    int* que = (int*)calloc(N,sizeof(int));

    char instruction[20];
    
    int cnt=0;
    for(int i=0;i<N;i++){
        scanf("%s",instruction);
        
        if(strcmp(instruction,"push")==0){
            scanf("%d",&que[cnt]);
            cnt++;
        }

        else if(strcmp(instruction,"pop")==0){
            if(cnt == 0){
                printf("-1\n");
            }
            else{
                printf("%d\n",pop(que,cnt));
                cnt--;
            }
            
        }
        
        else if(strcmp(instruction,"size")==0){
            printf("%d\n",cnt);
        }

        else if(strcmp(instruction,"empty")==0){
            if(cnt==0){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }

        else if(strcmp(instruction,"front")==0){
            if(cnt==0){
                printf("-1\n");
            }
            else{
                printf("%d\n",que[0]);
            }
        }

        else if(strcmp(instruction,"back")==0){
            if(cnt==0){
                printf("-1\n");
            }
            else{
                printf("%d\n",que[cnt-1]);
            }
        }
    }
    free(que);
}