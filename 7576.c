#include<stdio.h>

typedef struct directions{
    int E;
    int W;
    int S;
    int N;
}D;

typedef struct C{
    int x;
    int y;
}C;

D get_d(C current){
    D result;

    result.E = current.x+1;
    result.W = current.x-1;
    result.S = current.y-1;
    result.N = current.y+1;

    return result;
}

int main(void){
    int M,N,cnt=0,ripe_top=-1,pp_top=-1;
    scanf("%d %d",&M,&N);

    C ripe[M*N]; // 처리 안 된 익은 토마토 스택
    C pp[M*N]; // 대기 열
    int arr[N+2][M+2]; // 창고

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&arr[i][j]);
            // 익은 토마토 위치 저장
            if(arr[i][j] == 1){
                ripe[++ripe_top].x = i;
                ripe[ripe_top].y = j;
            }
        }   
    }
    // 저장될 때부터 모든 토마토가 익어있는 상태
    if(N*M == ripe_top+1){
        printf("0"); 
        return 0;
    }

    //테두리를 빈 칸으로
    for(int i=0;i<M+2;i++){
        arr[0][i] = -1;
        arr[N+1][i] = -1;
    }
    for(int i=1;i<=N;i++){
        arr[i][0] = -1;
        arr[i][M+1] = -1;
    }

    while(1){
        if(ripe_top==-1) break;
        // 동 서 남 북 확인 후 익은 사과로 변경
        int result = 0;
        while(ripe_top!=-1){
            D current = get_d(ripe[ripe_top]);
            if(arr[current.E][ripe[ripe_top].y] == 0){
                arr[current.E][ripe[ripe_top].y] = 1;
                pp[++pp_top].x =  current.E;
                pp[pp_top].y = ripe[ripe_top].y;
                result++;
            }
            if(arr[current.W][ripe[ripe_top].y] == 0){
                arr[current.W][ripe[ripe_top].y] = 1;
                pp[++pp_top].x =  current.W;
                pp[pp_top].y = ripe[ripe_top].y;
                result++;
            }
            if(arr[ripe[ripe_top].x][current.S] == 0){
                arr[ripe[ripe_top].x][current.S] = 1;
                pp[++pp_top].x =  ripe[ripe_top].x;
                pp[pp_top].y = current.S;
                result++;
            }
            if(arr[ripe[ripe_top].x][current.N] == 0){
                arr[ripe[ripe_top].x][current.N] = 1;
                pp[++pp_top].x =  ripe[ripe_top].x;
                pp[pp_top].y = current.N;
                result++;
            }
            ripe_top--;
        }
        //토마토가 익어진 경우에만
        if(result!=0) cnt++;

        if(pp_top==-1) break;
        else{ // 대기열에 있는 값을 옮기기
            while(pp_top!=-1){
                ripe[++ripe_top] = pp[pp_top--];
            }
        }

    }
    // 토마토가 모두 익지는 못하는 상황
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j] == 0){
                printf("-1");
                return 0;
            }
        }   
    }

    printf("%d",cnt);

    /*  창고 확인용
    printf("----------------------------------\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            printf("%d ",arr[i][j]);
        }   
        printf("\n");
    }         
    */
   
}