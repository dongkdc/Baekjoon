#include<stdio.h>
#include<stdlib.h>

void DFS(int (*arr)[1001],int V,int N){
    int stack[10001];
    int visited[1001] = {0};
    int top =-1;
    
    stack[++top] = V;

    while(top!=-1){

        // 스택에서 꺼내기
        int temp = stack[top--]; 

        // 이미 방문한 경우
        if(visited[temp]==1){
            continue;;
        } 

        visited[temp] = 1; // 방문한 노드로 표시

        printf("%d ",temp);

        for(int i=N;i>0;i--){
            // 연결이 되어 있으면서 아직 방문을 안 한 노드
            if(arr[temp][i] == 1 && visited[i]!=1){
                stack[++top] = i;
            }
        }
    }
}

void BFS(int (*arr)[1001],int V,int N){
    int que[10001];
    int head=0,tail=0;
    int visited[1001] = {0};

    que[tail++]= V;
    visited[V] = 1;

    while(head != tail){
        
        int temp = que[head++];

        printf("%d ",temp);

        for(int i=1;i<=N;i++){
            if(arr[temp][i] == 1 && visited[i]!=1){
                visited[i] = 1;
                que[tail++] = i;
            }
        }
    }
}

int main(void){

    int N, M, V;
    scanf("%d %d %d",&N,&M,&V);
    
    // 인접 행렬(크기로 인해 static로 선언)
    static int arr[1001][1001]={0};

    // 연결되는 두 정점 표시하기
    for(int i=0;i<M;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        
        //양방향 으로 연결됨
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }  

    DFS(arr,V,N);
    printf("\n");
    BFS(arr,V,N);
} 