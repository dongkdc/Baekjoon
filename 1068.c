#include<stdio.h>

typedef struct{
    int child[50];
    int child_cnt;
}Node;

// 노드 지우기 
void eraser(Node* tree, int idx,int value){
    Node* root = &tree[idx];
    if(root == NULL) return;

    for(int i=0;i<root->child_cnt;i++){
        if(root->child[i]==value){
            root->child[i] = -1; // 찾았다면 지우기
            return;
        }
    }
    
    for(int i=0;i<root->child_cnt;i++){
        if(root->child[i]!=-1 ){
            eraser(tree,root->child[i],value);
        }
    }
}

// 단말 노드 찾기
int count(Node* tree,Node root){
    int cnt = 0;

    if(root.child_cnt == 0 || (root.child[0] == -1 && root.child_cnt == 1)) return 1;
    
    int sum=0;
    for(int i=0;i<root.child_cnt;i++){
        if(root.child[i] != -1){
            sum+=count(tree,tree[root.child[i]]);
        }
    }
    return sum;
}

int main(void){
    int N,root_idx;
    scanf("%d",&N);
    
    Node tree[50];

    // 초기화
    for(int i=0;i<N;i++){
        tree[i].child_cnt = 0;
    }

    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);
        // 루트 인덱스 찾기
        if(num == -1) root_idx = i;
        
        else{
            tree[num].child[tree[num].child_cnt] = i;
            tree[num].child_cnt++;
        }
    }

    int del;
    scanf("%d",&del);
    if(del == root_idx){
        printf("0");
        return 0;
    }
    else{
         eraser(tree,root_idx,del);

        printf("%d",count(tree,tree[root_idx]));
    }
   
}