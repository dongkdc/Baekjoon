#include<stdio.h>
int main(void){
    int test;
    scanf("%d",&test);

    for(int i=0;i<test;i++){ // tsetcase만큼 반복
        int N,M;
        scanf("%d %d",&N,&M);

        // 한 번 반복에 값 구하기2
         long long P=1;
         for(int j=1;j<=N;j++){
            P*=M+1-j;
            P/=j;
         }

         printf("%lld\n",P);
    }
}