#include<stdio.h>
#include<stdlib.h>

int main(void){

    int N;
    scanf("%d",&N);

    int arr[N];
    //int count[1000001]={0};
    int* count = (int*)calloc(1000001,sizeof(int));
    
    for(int i=0;i<N;i++){ 
        scanf("%d",&arr[i]);
        count[arr[i]] = 1;
    }
   
    for(int i=0;i<=N;i++){
        if(count[i]==1){
            printf("%d\n",i);
        }
    }
}