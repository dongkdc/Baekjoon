#include<stdio.h>
#include<stdlib.h>


int main(void){
    int n,idx=0,paper=0,cnt;
    scanf("%d",&n);
    cnt=n; // 현재 풍선의 개수

    int* que = (int*)malloc(n*sizeof(int)); // 풍선을 담을 큐
    int* seq = (int*)malloc(n*sizeof(int)); // 터진 풍선 순서
    
    for(int i=0;i<n;i++){
        scanf("%d",&que[i]);
    }

    // 1번 풍선 처리
    paper = que[0];
    seq[0] = 1; 
    que[idx] = 0; // 제거
    cnt--;

    for(int i=1;i<n;i++){
        if(paper>0){
            for(int j=0;j<paper;j++){
                idx++;
                if(que[idx%(n)]==0){ // 이미 터진 풍선일 경우
                    j--;
                }
            }
            idx=idx%n;
            paper = que[idx];
            seq[i] = idx+1;
            que[idx] = 0; // 제거
            cnt--;
        }
        
        else{
            paper = (cnt+1) - ((-paper)%cnt);
            for(int j=0;j<paper;j++){
                idx++;
                if(que[idx%(n)]==0){ // 이미 터진 풍선일 경우
                    j--;
                }
            }
            idx=idx%n;
            paper = que[idx];
            seq[i] = idx+1;
            que[idx] = 0; // 제거
            cnt--;


        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",seq[i]);
    }

    free(seq);
    free(que);
}