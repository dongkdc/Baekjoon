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
    
    // 국어 점수 동일한 경우
    if(SA->Korean == SB->Korean){
        
        //국어점수와 영어점수가 동일한 경우 
        if(SA->English == SB->English){

            //모든 점수가 같은 경우(이름으로 정렬)
            if(SA->Math == SB->Math){
                return strcmp(SA->Name,SB->Name);
            }

            //수학점수로 정렬(내림차순)
            else{
                return (SB->Math - SA->Math);
            }
        }

        // 영어점수로 정렬(오름차순)
        else{
            return (SA->English - SB->English);
        }
    }

    // 국어 점수로 정렬(내림차순)
    else{
        return (SB->Korean - SA->Korean);
    }
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