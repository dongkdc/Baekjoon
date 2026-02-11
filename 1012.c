#include<stdio.h>

// 상하좌우 살피기
void  find(int (*land)[50],int (*visited)[50],int x,int y,int N, int M){
   
    // 우
    if((x+1<M && land[x+1][y] == 1) && visited[x+1][y] == 0){
        visited[x+1][y] = 1;
        find(land,visited,x+1,y,N,M);
    }

    // 하
    if((y-1>=0 && land[x][y-1] == 1) && visited[x][y-1] == 0){
        visited[x][y-1] = 1;
        find(land,visited,x,y-1,N,M);
    }

    // 좌
    if((x-1>=0 && land[x-1][y] == 1) && visited[x-1][y] == 0){
        visited[x-1][y] = 1;
        find(land,visited,x-1,y,N,M);
    }

    // 상
    if((y+1<N && land[x][y+1] == 1) && visited[x][y+1] == 0){
        visited[x][y+1] = 1;
        find(land,visited,x,y+1,N,M);
    }

}

int main(void){ 
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++){
        int cnt = 0; // 필요한 지렁이의 수
        int M,N,K; // 가로, 세로, 배추의 개수
        scanf("%d %d %d",&M,&N,&K);

        // 땅 만들기
        int land[50][50] = {0};
        // 방문 확인용
        int visited[50][50] = {0};

        // 배추 심기
        for(int j=0;j<K;j++){
            int x,y;
            scanf("%d %d",&x,&y);
            
            land[x][y] = 1;
        }

        for(int l=0;l<M;l++){
            for(int q=0;q<N;q++){
                // 배추가 심어져있고, 아직 방문하지 않은 경우
                if(land[l][q] == 1 && visited[l][q] == 0){
                    visited[l][q] = 1;
                    find(land,visited,l,q,N,M);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}