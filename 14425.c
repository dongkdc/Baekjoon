#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    char* A = (char*) a;
    char* B = (char*) b;

    return strcmp(A,B);
}

int search(char arr[][501], char* value,int n){
    int front=0;
    int last=n-1;
    while(front<=last){
        int mid = (front+last)/2;
        int res = strcmp(arr[mid], value);
        if (res == 0) { // 두 문자열이 완벽히 일치할 때
            return 1;
        }
        if (res > 0) { // arr[mid]가 value보다 사전순으로 뒤에 있다면
            last = mid - 1;
        } 
        else { // arr[mid]가 value보다 사전순으로 앞에 있다면
            front = mid + 1;
        }
    }
    return 0;
}

int main(void){
    int N,M,cnt=0;
    scanf("%d %d",&N,&M);
    char arr[N][501];

    for(int i=0;i<N;i++){
        scanf("%s",arr[i]);
    }

    qsort(arr,N,501*sizeof(char),compare);

    for(int i=0;i<M;i++){
        char test[501];
        scanf("%s",test);

        if(search(arr,test,N)==1) cnt++;
    }
    printf("%d",cnt);
}