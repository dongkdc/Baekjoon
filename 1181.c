#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    int len_a = strlen(a);
    int len_b = strlen(b);

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

    for(int i=0;i<N-1;i++){
        if(strcmp(arr[i],arr[i+1])==0){
            arr[i][0]= 'A'; // 입력값은 소문자 이므로 대문자를 입력시켜 제외하는 목적
        }
    }
    for(int i=0;i<N;i++){
        if(arr[i][0]!='A'){
            printf("%s\n",arr[i]);
        }   
    }
}