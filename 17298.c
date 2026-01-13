#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N;
    scanf("%d",&N);

    int* arr = (int*)calloc(N,sizeof(int)); // 수열
    int* stack = (int*)calloc(N,sizeof(int)); // 스택
    int* result = (int*)calloc(N,sizeof(int)); // 결과
    int top=0; // 스택의 값이 들어있는 제일 위 인덱스 

    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        result[i] = -1; // 정답배열 -1으로 초기화
    }

    stack[top] = 0; // 첫 번째 값은 비교대상이 없음

    for(int j=1;j<N;j++){
        // 현재 숫자(arr[j])가 top의 값보다 크다면 (오큰수 발견)
        if(arr[stack[top]]<arr[j]){
           while(arr[stack[top]]<arr[j]){ //자신보다 큰 수가 있다면 중단
                result[stack[top--]] = arr[j]; // POP 결과를 기록하고 제거
                if(top == -1) break; // 스택에 아무것도 없으면 중단
           }
           stack[++top] = j; // 자기자신을 스택에 추가
        }

        else{
            stack[++top] = j; // PUSH 나중에 자신의 오큰수를 찾기 위해 대기
        }
    }
    
    for(int i=0;i<N;i++){
        printf("%d ",result[i]);
    }

    free(result);
    free(stack);
    free(arr);
}