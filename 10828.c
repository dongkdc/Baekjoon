#include<stdio.h>
#include<string.h>

int main(void){
    int N;
    scanf("%d",&N);

    int stack[100001]={0};
    int top_index=0; // 다음 수가 들어갈 위치

    for(int i=0;i<N;i++){

        char command[10];
        scanf("%s",command);
        
        if(strcmp(command,"push")==0){
            int num;
            scanf("%d",&num);
            stack[top_index++] = num;
        }

        else if(strcmp(command,"pop")==0){
            if(top_index==0) printf("-1\n");
            
            else{
                printf("%d\n",stack[top_index-1]);
                top_index--;
            } 
        }

        else if(strcmp(command,"size")==0){
            printf("%d\n",top_index);
        }

        else if(strcmp(command,"empty")==0){
            if(top_index==0){
                printf("1\n");
            }

            else{
                printf("0\n");
            }
        }

        else if(strcmp(command,"top")==0){
            if(top_index==0){
                printf("-1\n");
            }

            else{
                printf("%d\n",stack[top_index-1]);
            }
        }   
    }
}