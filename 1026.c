#include<stdio.h>

void desc(int* temp,int N){ //B를 내림차순으로 정렬하는 함수
    
    for(int i=0;i<N;i++){
        int max=-1,index=0;
        for(int j=i;j<N;j++){
            if(max<=temp[j]){
                max=temp[j];
                index=j;
            }
        }
        int tn=temp[i];
        temp[i]=temp[index];
        temp[index]=tn;
    }
}

void asc(int* A,int N){ //A를 오름차순으로 정렬하는 함수
    for(int i=0;i<N;i++){
        int min=101,index=0;
        for(int j=i;j<N;j++){
            if(min>=A[j]){
                min=A[j];
                index=j;
            }
        }
        int tn=A[i];
        A[i]=A[index];
        A[index]=tn;
    }
}

int main(void){
    int N,sum=0;
    int A[51],B[51],temp[51];

    scanf("%d",&N);
    //A배열 입력
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    //B배열과 temp배열 입력
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    //B배열의 값을 temp에 복사
    for(int i=0;i<N;i++){
        temp[i]=B[i];
    }

    desc(temp,N); // B와 동일한 temp 배열을 내림차순으로 정렬
    
    asc(A,N); //A를 올림차순으로 정렬

    for(int i=0;i<N;i++){ //S구하기
        sum+=(A[i]*temp[i]);
    }

    printf("%d",sum);
}