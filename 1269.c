#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int search(int* a,int len,int value){
    int start,end,mid;
    start = 0;
    end = len -1;

    while(start<=end){
        mid = (start + end) / 2;

        if(a[mid]>value){
            end = mid -1;
        }
        else if(a[mid]<value){
            start = mid +1;
        }
        else{ // 같은 경우
            return 1;
        }
    }
    return 0; // 못 찾은 경우
}

int main(void){
    int n_a,n_b,cnt=0;
    scanf("%d %d",&n_a,&n_b);

    int arr[n_a];
    for(int i=0;i<n_a;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n_a,sizeof(int),compare);

    for(int i=0;i<n_b;i++){
        int num;
        scanf("%d",&num);

        if(search(arr,n_a,num)==1) cnt++; // A안에 있으면 교집합 개수 +1
    }
    
    printf("%d",n_a+n_b-(2*cnt));
}