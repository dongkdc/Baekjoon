#include<stdio.h>
int main(void){

    int N;
    scanf("%d",&N);

    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    int temp[N];
    for(int i=0;i<N;i++){
        int min = 1000001;
        int idx=0;
        for(int j=0;j<N;j++){
            if(arr[j]<min && arr[j]!=1000001){
                min = arr[j];
                idx=j;
            }
        }
        arr[idx]=1000001;
        temp[i]=min;
    }
    for(int i=0;i<N;i++){
        printf("%d\n",temp[i]);
    }
}