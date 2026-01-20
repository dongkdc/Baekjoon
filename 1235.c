#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int N,len,idx,cnt=0;
    char ID[1001][101];

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",ID[i]);
    }
    len = strlen(ID[0]);

    idx = len-1;
    while(1){
        int status = 1;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){ // 자신을 제외한 나머지 번호와 비교
                if(strcmp(ID[i]+idx,ID[j]+idx)==0){
                    status = 0; // 같은 번호 발생
                    break;
                }
            }
            if(status == 0) break;
        }
        cnt++;
        if(status==1) break; // 지금 서로를 구분가능한 최소임을 나타냄
        idx--; // 다음 자리수까지 비교
    }
    printf("%d",cnt);
}