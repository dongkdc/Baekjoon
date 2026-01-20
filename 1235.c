#include<stdio.h>
#include<stdlib.h>

int main(){
    int N,num=10,cnt=0;
    scanf("%d",&N);
    int* ID = (int*)malloc(N*sizeof(int));
    
    for(int i=0;i<N;i++){
        scanf("%d",&ID[i]);
    }

    while(1){
        int* cp = (int*)malloc(N*sizeof(int));
        int status = 0;
        for(int i=0;i<N;i++){ // 학생 끼리 비교
            if(status == 0){
                cp[i] = ID[i] % num;
                for(int j=i-1;j>=0;j--){
                    if(cp[i] == cp[j]){
                        status = 1;
                        break;
                    }
                }
            }
        }
        if(status == 0) break;
        cnt++;
        num*=10;
        free(cp);
    }

    printf("%d",cnt+1);

    free(ID);
}