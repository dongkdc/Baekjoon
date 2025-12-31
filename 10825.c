#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Score
{
    char Name[11];
    int Korean;
    int English;
    int Math;
};

int compare(const void* a, const void* b){
    struct Score* SA = (const struct Score*) a;
    struct Score* SB = (const struct Score*) b;
    
   // 1. 국어 점수가 다르면 내림차순
    if (SA->Korean != SB->Korean) return SB->Korean - SA->Korean;
    
    // 2. 영어 점수가 다르면 오름차순
    if (SA->English != SB->English) return SA->English - SB->English;
    
    // 3. 수학 점수가 다르면 내림차순
    if (SA->Math != SB->Math) return SB->Math - SA->Math;
    
    // 4. 위 세 조건이 모두 같으면 이름 오름차순
    return strcmp(SA->Name, SB->Name);
}



int main(void){
    int N;
    scanf("%d",&N);

    //구조체를 넣을 배열
    struct Score arr[N];

    //입력
    for(int i=0;i<N;i++){
        scanf("%s %d %d %d",arr[i].Name,&arr[i].Korean,&arr[i].English,&arr[i].Math);
    }
    
    //정렬
    qsort(arr,N,sizeof(arr[0]),compare);

    for(int i=0;i<N;i++){
        printf("%s\n",arr[i].Name);
    }
}