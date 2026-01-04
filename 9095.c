#include<stdio.h>

int main(void){
    int T;
    scanf("%d",&T);

    int arr[11]={1,2,4}; // 1,2,3의 출력을 미리 채우기
    
    for(int i=3;i<11;i++){
        arr[i]=arr[i-3]+arr[i-2]+arr[i-1];
    }

    
    for(int i=0;i<T;i++){
        int num;
        scanf("%d",&num);
        printf("%d\n",arr[num-1]);
    }
}
