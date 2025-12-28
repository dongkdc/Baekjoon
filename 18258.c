#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pop(int* que,int first){
    // 제일 앞의 값 제거 및 출력
    printf("%d\n",que[first]);
    que[first] = 0; 
}

int main(void){
    int N;
    scanf("%d",&N);
    
    // N의 최대크기가 크기때문에 동적할당으로 선언
    // 입력되는 값은 1이상이므로 0으로 초기화를 위한 calloc 이용
    int* que = (int*)calloc(N,sizeof(int));

    char instruction[20];
    
    int location=0; // 현재 que의 크기 (0포함)
    int first=0; // 제일 앞 인덱스를 가르키는 변수 (0제외)
    int cnt=0;
    for(int i=0;i<N;i++){
        scanf("%s",instruction);
        
        if(strcmp(instruction,"push")==0){
            scanf("%d",&que[location]);
            cnt++;
            location++;
        }

        else if(strcmp(instruction,"pop")==0){
            // 아무것도 없는 경우
            if(cnt == 0){
                printf("-1\n");
            }

            else{
                pop(que,first);
                cnt--;
                first++;
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
                printf("%d\n",que[first]);
            }
        }

        else if(strcmp(instruction,"back")==0){
            if(cnt==0){
                printf("-1\n");
            }
            else{
                printf("%d\n",que[location-1]);
            }
        }
    }
    free(que);
}