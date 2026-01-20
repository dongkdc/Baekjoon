#include<stdio.h>

int main(void){
    int a_num,b_num,cnt=0;

    scanf("%d %d",&a_num,&b_num);

    int a_arr[a_num],b_arr[b_num];

    for(int i=0;i<a_num;i++){ // A의 원소 입력
        scanf("%d",&a_arr[i]);
    }
    for(int i=0;i<b_num;i++){ // B의 원소 입력
        scanf("%d",&b_arr[i]);
    }
    
    for(int i=0;i<a_num;i++){
        for(int j=0;j<b_num;j++){
            if(a_arr[i]==b_arr[j]){ 
                cnt++;
                break;
            }
        }
    }
    printf("%d",a_num+b_num-(2*cnt)); // 총 차집합의 개수 = A의 원소 개수 + B의 원소 개수 -2*교집합
}