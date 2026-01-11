#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N;
    scanf("%d",&N);

    int* arr = (int*)calloc(N,sizeof(int));

    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }

    for(int j=0;j<N-1;j++){
        int max = arr[j];
        for(int k=j+1;k<N;k++){
            if(max<arr[k]){
                printf("%d ",arr[k]);
                break;
            }
            else if(k==N-1){
                printf("-1 ");
            }
        }
    }
    printf("-1");
    free(arr);
}