#include<stdio.h>
#include<stdlib.h>

// 구조체를 이용한 노드 표현
typedef struct{
    int* child; // 자식을 담을 곳
    int idx; // child의 인덱스
    int cap; // 담을 수 있는 최대 인원
}Node;

void add_node(Node* tree,int n1,int n2){
    // 공간이 다 찬 경우 늘려주기
    if(tree[n1].cap == tree[n1].idx){
        tree[n1].cap *= 2;
        tree[n1].child = realloc(tree[n1].child,sizeof(int)*tree[n1].cap);
    }
    if(tree[n2].cap == tree[n2].idx){
        tree[n2].cap *= 2;
        tree[n2].child = realloc(tree[n2].child,sizeof(int)*tree[n2].cap);
    }

    // 서로를 자식노드에 추가
    tree[n1].child[tree[n1].idx++] = n2;
    tree[n2].child[tree[n2].idx++] = n1;
}

void find_parent(Node* tree,int* parent, int current){

    for(int i=0;i<tree[current].idx;i++){
        int next_node = tree[current].child[i];

        // 누가 부모인지 찾기
        if(next_node != parent[current]){
            parent[next_node] = current;
            find_parent(tree,parent,next_node);
        }
    }
}
 
int main(void){
    int N;
    scanf("%d",&N);

    int* parent = (int*)calloc(N+1,sizeof(int));

    Node* tree = (Node*)malloc(sizeof(Node)*(N+1));

    // 초기화
    for(int i=1;i<=N;i++){
        tree[i].cap = 2;
        tree[i].idx = 0;
        tree[i].child = (int*)malloc(sizeof(int)*tree[i].cap);
    }

    // 입력
    for(int i=0;i<N-1;i++){
        int num1,num2;
        scanf("%d %d",&num1, &num2);

        add_node(tree,num1,num2);   
    }

    // 부모 찾기 
    find_parent(tree,parent,1);

    for(int i=2;i<=N;i++){
        printf("%d\n",parent[i]);
    }
    
    // 메모리 해제
    for(int i=1;i<=N;i++){
        free(tree[i].child);
    }
    free(tree);
    free(parent);
}