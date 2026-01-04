#include<stdio.h>

int factorial(int n) {
    if (n <= 1) return 1;
    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

int main(void){
    int T;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        int num,cnt=0;
        scanf("%d",&num);
        
        
        for (int k = 0; k <= num / 3; k++) {       // 3의 개수
            for (int j = 0; j <= num / 2; j++) {   // 2의 개수
                for (int i = 0; i <= num; i++) {   // 1의 개수
                    if (i * 1 + j * 2 + k * 3 == num) {
                        int n = i+j+k;
                        int p = factorial(n) / (factorial(i) * factorial(j) * factorial(k));
                        cnt += p;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
}
