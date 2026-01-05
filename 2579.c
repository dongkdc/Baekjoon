#include<stdio.h>

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(void){
   
    int N;
    scanf("%d",&N);

    int stair[N];
    for(int i=0;i<N;i++){
        scanf("%d",&stair[i]);
    }

    if(N<3){
        if(N==1) printf("%d",stair[0]);
        else printf("%d",stair[0]+stair[1]);
        return 0;
    }

    int op[N];
   
    op[0] = stair[0];
    op[1] = stair[0] + stair[1];
    op[2] = max(stair[0]+stair[2],stair[1]+stair[2]);
    
    for(int i=3;i<N;i++){
        op[i] = max(op[i-3]+stair[i-1]+stair[i],op[i-2]+stair[i]);
    }
    printf("%d",op[N-1]);
}