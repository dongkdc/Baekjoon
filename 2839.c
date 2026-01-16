#include<stdio.h>

int main(void){
    int N,cnt=0;
    scanf("%d",&N);
        
    // 3kg를 제일 최소로 사용해서 찾는 방법
    while(1){
        if(N%5==0){ 
             cnt+=N/5;
             printf("%d",cnt);
             break;
        }

         N-=3;
         cnt++;  
         if(N<0){
            printf("-1");
            break;
        }
    }
}