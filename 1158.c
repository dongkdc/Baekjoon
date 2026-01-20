#include<stdio.h>
int main(void){
    int N,k,idx=-1; 
    scanf("%d %d",&N,&k);

    int arr[N],seq[N];

    for(int i=0;i<N;i++){
        arr[i]=i+1; // 1부터 N까지 순서대로 삽입
    }

    // 요세푸스 순열 구하기
    for(int j=0;j<N;j++){ 
        // 인덱스 증가
       for(int i=0;i<k;i++){
            idx++;
            if(idx == N) idx=0; // 원형 큐
            if(arr[idx]==0) i--; // 이미 제거된 수 넘어가기
       }
       seq[j] = arr[idx];
       arr[idx] = 0; // 제거
    }

    printf("<");
    for(int i=0;i<N;i++){
        if(i==N-1) printf("%d>",seq[i]);
        else printf("%d, ",seq[i]);
    }

}