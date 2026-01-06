#include<stdio.h>


int min(int a,int b){
    return a>b ? b : a;
}

int main(void){
    int N;
    scanf("%d",&N);

    int opt[N+1];
    opt[1]=0;
    for(int i=2;i<=N;i++){
        // 1로 빼는 경우
        opt[i]= opt[i-1] + 1;

        if(i % 2 == 0){
            opt[i] = min(opt[i],opt[i/2]+1);
        }

         if(i % 3 == 0){
            opt[i] = min(opt[i],opt[i/3]+1);
        }
    }

    printf("%d",opt[N]);

}