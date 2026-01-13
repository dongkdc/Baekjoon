#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N;
    scanf("%d",&N);

    int* height = (int*) calloc(N,sizeof(int)); // 높이를 담을 배열
    int* stack = (int*) calloc(N,sizeof(int)); // 아직 송신 못 한 타워
    int* result = (int*) calloc(N,sizeof(int)); // 수신받은 타워를 저장
    int top=-1; // 스택의 위

    for(int i=0;i<N;i++){
        scanf("%d",&height[i]);
    }

    for(int j=N-1;j>=0;j--){ // 뒤에서부터 왼쪽으로
        if(top==-1) stack[++top] = j; // 비교할 값이 없는 경우 PUSH

        else{
            if(height[stack[top]]<height[j]){ 
                while(top>=0 && height[stack[top]]<height[j]){
                    result[stack[top--]] = j+1; // POP & 결과 저장
                }
                stack[++top] = j; // PUSH
            } 

            else{
                stack[++top] = j; // PUSH
            }   
        }
    }
    
    for(int i=0;i<N;i++){
        printf("%d ",result[i]); 
    }
}   