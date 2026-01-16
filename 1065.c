#include<stdio.h>
int hansu(int N){
  int cnt=0;
  if(N<100){
    printf("%d",N);
    return 0;
  }
  for(int i=111;i<=N;i++){
    int x,y,z;
    x=i/100;
    y=(i%100)/10;
    z=i%10;
    if(2*y==x+z){
      cnt++;
      i+=10;
    }
  }
  printf("%d",99+cnt);
  return 0;
}

int main(void){
  int N;
  scanf("%d",&N);
  hansu(N);
}