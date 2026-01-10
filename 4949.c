#include<stdio.h>
#include<string.h>

int main(void){

    while(1){
        char arr[105]; // \0포함
        char stack[105]; // 균형을 확인하기 위한 스택
        int idx=0; // stack에 다음 값이 들어갈 인덱스
        int len=0; // 문자열의 길이
        int result = 1;

        fgets(arr,sizeof(arr),stdin);
        
        // 종료조건
        if(arr[0]=='.') break; 
        
        // \n 지우기
        len=strlen(arr)-1;
        arr[len]='\0'; 
        
        for(int i=0;i<len;i++){
            // 열린괄호가 들어온 경우는 무조건 push
            if(arr[i]=='(' || arr[i]=='['){
                stack[idx++] = arr[i];
            }

            else if(arr[i]==')'){
                // 닫힌 괄호가 짝이 안 맞는 경우
                // (스택에 처음으로 들어온 경우 || 동일한 열린 괄호가 아닌 경우)
                if(idx==0 || stack[idx-1] != '('){
                    result = 0;
                    break;
                }

                // 동일한 열린 괄호인 경우
                else if(stack[idx-1] == '('){
                    idx--;
                }
            }

            else if(arr[i]==']'){
                // 닫힌 괄호가 짝이 안 맞는 경우
                // (스택에 처음으로 들어온 경우 || 동일한 열린 괄호가 아닌 경우)
                if(idx==0 || stack[idx-1] != '['){
                    result = 0;
                    break;
                }

                // 동일한 열린 괄호인 경우
                else if(stack[idx-1] == '['){
                    idx--;
                }
            }
        }
        // 닫힌 괄호가 짝이 안 맞는 경우 || 스택에 닫힌 괄호만 들어가 있는 경우
        if(result == 0 || idx != 0) printf("no\n");
        
        // 짝이 맞는 경우 && 스택에 아무것도 안 들어가 있는 경우
        else if(result && idx==0) printf("yes\n"); 
    }
}
