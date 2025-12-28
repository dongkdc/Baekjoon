#include<stdio.h>
#include<stdlib.h>

int main(void){

    int N,num;
    scanf("%d",&N);

    int* p_count = (int*)calloc(1000001,sizeof(int));
    int* m_count = (int*)calloc(1000001,sizeof(int));
    
    for(int i=0;i<N;i++){ 
        scanf("%d",&num);
        if(num>=0){
            p_count[num] = 1;
        }
        else{
            m_count[-num] = 1;
        }
    }

    for(int i=1000000;i>0;i--){
        if(m_count[i]==1){
            printf("-%d\n",i);
        }
    }
   
    for(int i=0;i<=1000000;i++){
        if(p_count[i]==1){
            printf("%d\n",i);
        }
    }
    free(p_count);
    free(m_count);
}