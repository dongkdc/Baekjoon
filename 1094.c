#include<stdio.h>
int main(void){
    int stick=64,sum=64,result=0,cnt=0,x;
    
    scanf("%d",&x);   

    if(x==sum) cnt++; // x가 64인 경우 

    while(result!=x){

        if(sum>x){ 
            int temp = stick>>1;  
            
            if((sum-temp)>x){  // 남은 막대의 합 > x
                stick -= temp;
                sum-=stick;     
            }

            else if((sum-temp)==x){
                stick -= temp;
                result+=temp;
                cnt++;
            }

            else{
                result+=temp;
                stick-=temp; 
                cnt++;
            }

        }
    }
    printf("%d",cnt);
}