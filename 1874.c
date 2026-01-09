#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N;
    scanf("%d",&N);

    int stack[N+1]; // 스택
    char pp[4*N+1]; // + -를 담을 배열

    int top=0; // 다음 수를 넣을 위치를 표시
    int digit=1; // 스택에 넣을 다음 숫자
    int pp_index=0; // pp에 값을 넣을 인덱스

    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);

        while(digit<=num){
            pp[pp_index++]='+';
            pp[pp_index++]='\n';

            stack[top++] = digit;
            digit++;
        }
        
        // top은 다음 수를 넣을 위치를 표시하기 때문에 top-1을 해서 값을 확인함
        if(top>0 && stack[top-1]==num){ 
            pp[pp_index++]='-';
            pp[pp_index++]='\n';
            top--;
        }

        else{ //가장 위의 수보다 클 때
            printf("NO");
            return 0;
        }
    }

    pp[pp_index]='\0';

    printf("%s",pp);
}