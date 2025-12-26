#include<stdio.h>
unsigned long long f(int a,int b){
    if(a==b){
        return a;
    }
    return a*f(a-1,b);
}

int main(void){
    int test;
    scanf("%d",&test);

    for(int i=0;i<test;i++){ // tsetcase만큼 반복
        int N,M;
        scanf("%d %d",&N,&M);

        //분자 구하기
        int start,end;
        start=M;
        end=M-N+1;
        unsigned long long num=f(start,end);
        
        //분모 구하기
        unsigned long long den=f(N,1);
        
        //조합  
        int P = num/den;
        printf("%d\n",P);
    }
}