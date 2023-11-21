#include<stdio.h>
#include <stdlib.h> //malloce을 사용하기 위한 헤더파일
#include<string.h> //memset을 사용하기 위한 헤더파일
int main(void) {
    int n, a=0;
    scanf_s("%d", &n);

    int* cal = malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &cal[i]);
    }
    for (int j = 0; j < n; j ++) {
        a += (j%2==0)? cal[j]:-cal[j];
    }

    a = a / 2;
    printf("%d\n", a);
    for (int b = 0; b < n-1; b++) {
        a = cal[b] - a;
        printf("%d\n", a);
    }
    free(cal);
}