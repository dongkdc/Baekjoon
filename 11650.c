#include<stdio.h>
#include<stdlib.h>

// 구조체 정의
struct coordinate
{
    int xpos;
    int ypos;
};

int compare(const void* a, const void* b){
    struct coordinate* sa = (const struct coordinate*)a;
    struct coordinate* sb = (const struct coordinate*)b;
    
    //x좌표가 동일한 경우 y좌표로 비교
    if((sa->xpos) == (sb->xpos)){ 
        return (sa->ypos) - (sb->ypos);
    }

    //동일하지 않은 경우 x좌표로 비교
    else{
        return (sa->xpos) - (sb->xpos);
    }
    
}   

int main(void){
    int N;
    scanf("%d",&N);

    struct coordinate arr[N];

    //배열에 값 저장
    for(int i=0;i<N;i++){
        scanf("%d %d",&arr[i].xpos,&arr[i].ypos);
    }

    //배열 정렬
    qsort(arr,N,sizeof(struct coordinate),compare);

    for(int i=0;i<N;i++){
        printf("%d %d\n",arr[i].xpos,arr[i].ypos);
    }
}