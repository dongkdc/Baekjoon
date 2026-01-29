#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void make_tree(int start, int end, int* inorder, int* tree, int idx){
    if(start>end) return;

    int mid = (start+end) / 2;
    
    // 중앙값
    tree[idx] = inorder[mid];

    // 왼쪽 자식
    make_tree(start,mid-1,inorder,tree,idx*2);

    // 오른쪽 자식
    make_tree(mid+1,end,inorder,tree,idx*2+1);
}

int main(void){
    int k;
    scanf("%d",&k);

    int cnt = pow(2,k) - 1; // 전체 노드의 개수
    
    // 중위 순회의 결과(입력)
    int* inorder = (int*)calloc(cnt+1,sizeof(int));
    for(int i=1;i<=cnt;i++){
        scanf("%d",&inorder[i]);
    }

    int* tree = (int*)calloc(cnt+1,sizeof(int));
    
    // 중위 순회 값들로 트리 만들기
    make_tree(1,cnt,inorder,tree,1);

    // 출력
    int idx=1;
    for(int i=0;i<k;i++){
        for(int j=1;j<=pow(2,i);j++){
            printf("%d ",tree[idx++]);
        }
        printf("\n");
    }
    
    free(inorder);
    free(tree);
}