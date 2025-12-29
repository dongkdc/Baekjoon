#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    int len_a = strlen((char*)a);
    int len_b = strlen((char*)b);

    if(len_a == len_b){
        return strcmp((char*)a,(char*)b);
    }
    return (len_a-len_b);
}

int main(void){
    int N;
    scanf("%d",&N);

    char arr[N][51];

    //단어 입력
    for(int i=0;i<N;i++){
        scanf("%s",arr[i]);
    }

    //정렬(동일한 문자열도 포함)
    qsort(arr,N,sizeof(arr[0]),compare);
    
    printf("%s\n",arr[0]);
    // 동일한 문자열 제외 출력
    for(int i=1;i<N;i++){
        if(strcmp(arr[i],arr[i-1])!=0){
            printf("%s\n",arr[i]);
        }   
    }
}