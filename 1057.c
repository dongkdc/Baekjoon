#include<stdio.h>
int main(void){
    int N,x,y,cnt=0;
    
    scanf("%d %d %d",&N,&x,&y);

    while(x!=y){

        x=(x+1)/2; // 4 2 1 1
        y=(y+1)/2; // 5 3 2 1
        cnt++;
    }

    printf("%d",cnt);
}