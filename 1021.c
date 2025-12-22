#include<stdio.h>
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    
    //원하는 수 저장
    int want[M]; 
    for(int i=0;i<M;i++){
        scanf("%d",&want[i]);
    }

    //전체 큐 저장
    int que[N];
    for(int i=0;i<N;i++){
        que[i]=i+1; 
    }

    int cnt=0; //최소의 개수
    
    for(int j=0;j<M;j++){

        // 원하는 숫자의 인덱스 저장
        int target_idx = 0; 
        for (int i = 0; i < N; i++) {
            if (que[i] == want[j]) {
                target_idx = i;
                break;
            }
        }

        int check=0;
        if(target_idx>=(N+1)/2) check = 1; // 뒤에서부터 더 빠른경우
        while(1){
            if(que[0]==want[j]){
                for(int i=0;i<N-1;i++){
                    que[i]=que[i+1];
                } 
                N--;
                break;
            }
            
            if(check==0){ // 왼쪽으로 한 칸씩 이동(앞의 수를 뒤로)
                int temp=que[0];
                for(int k=0;k<N-1;k++){
                    que[k]=que[k+1];
                }
                que[N-1] = temp;
                cnt++;
            }

            else if(check==1){ // 오른쪽으로 한 칸씩 이동(뒤의 수를 앞으로)
                int temp=que[N-1]; 
                for(int k=N-1;k>0;k--){
                    que[k]=que[k-1];
                }
                que[0]=temp;
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}