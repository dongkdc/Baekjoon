#include <stdio.h>

void get_desc_indices(int* idx, int* temp, int N) {
    for (int i = 0; i < N; i++) {
        int max = -1;
        int max_idx = 0;
        
        // 최댓값 찾기
        for (int j = 0; j < N; j++) {
            // 이미 처리된(-1) 값은 제외하고 최댓값 찾기
            if (temp[j] != -1 && temp[j] > max) {
                max = temp[j];
                max_idx = j;
            }
        }
        
        idx[i] = max_idx; // 큰 순서대로 인덱스 저장
        temp[max_idx] = -1; // 처리된 값은 제외
    }
}

// A를 오름차순으로 정렬하는 함수 
void asc(int* A, int N) {
    for (int i = 0; i < N; i++) {
        int min = 101; 
        int min_idx = i;
        
        for (int j = i; j < N; j++) {
            if (A[j] < min) {
                min = A[j];
                min_idx = j;
            }
        }

        int tn = A[i];
        A[i] = A[min_idx];
        A[min_idx] = tn;
    }
}

int main(void) {
    int N, sum = 0;
    int A[51], B[51], temp[51];
    int idx[51];          
    int rearranged_A[51]; 
    scanf("%d", &N);

    // A 입력
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    // B 입력 및 temp 복사 
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        temp[i] = B[i];
    }

    //B(temp)의 큰 값 순서대로 인덱스 추출
    get_desc_indices(idx, temp, N);

    // A를 오름차순 정렬
    asc(A, N);

    // A[idx]를 순서대로 변경하기
    
    for (int i = 0; i < N; i++) {
        rearranged_A[idx[i]] = A[i]; // B의 가장 큰 값이 있던 자리에 A의 작은 값을 넣음
    }

    for (int i = 0; i < N; i++) {
        sum += (rearranged_A[i] * B[i]);
    }

    printf("%d", sum);

    return 0;
}