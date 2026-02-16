#include<stdio.h>
#include<stdlib.h>

typedef struct coordinate{
    int xpos;
    int ypos;
    int step;
}CD;

CD que[1000];
int tail=-1; // 제일 뒤에 위치한 값의 위치
int head=-1; // 제일 앞에 위치한 값의 위치 앞

int visited[102][102]={0};

int escape(int N,int M,int (*maze)[M+2]){
    
    // pop
    CD temp = que[++head];
    
    // 도착 위치에 도달하면 종료
    if(temp.xpos == N && temp.ypos == M) return temp.step;
    
    // 오른쪽
    CD right = {temp.xpos+1,temp.ypos};
    if(maze[right.xpos][right.ypos] == 1 && visited[right.xpos][right.ypos] == 0){
        right.step = temp.step+1;
        visited[right.xpos][right.ypos] = 1;
        que[++tail] = right;
    }

    // 아래
    CD down = {temp.xpos,temp.ypos-1};
    if(maze [down.xpos][down.ypos] == 1 && visited [down.xpos][down.ypos] == 0){
     down.step = temp.step+1;
        visited [down.xpos][down.ypos] = 1;
        que[++tail] = down;
    }

    // 왼쪽
    CD left = {temp.xpos-1,temp.ypos};
    if(maze[left.xpos][left.ypos] == 1 && visited[left.xpos][left.ypos] == 0){
        left.step = temp.step+1;
        visited[left.xpos][left.ypos] = 1;
        que[++tail] = left;
    }

    // 위
    CD top = {temp.xpos,temp.ypos+1};
    if(maze[top.xpos][top.ypos] == 1 && visited[top.xpos][top.ypos] == 0){
        top.step = temp.step+1;
        visited[top.xpos][top.ypos] = 1;
        que[++tail] = top;
    }

    escape(N,M,maze);  

}

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);

    // 테두리를 포함한 미로 생성
    int maze[N+2][M+2];
    
    // 미로 초기화
    for(int i=0;i<N+2;i++){
        for(int j=0;j<M+2;j++){
            maze[i][j] = 0;
        }
    }

    // 입력
    for(int i=1;i<N+1;i++){

        char num[100];
        scanf("%s",num); // 1칸에 1개의 숫자 입력

        for(int j=0;j<M;j++){
            if(num[j] == '1'){
                maze[i][j+1] = 1;
            }
        }
    }

    // 시작 위치 제공
    CD start = {1,1,1};
    que[++tail] = start;

    int result = escape(N,M,maze);
    printf("%d",result);
}