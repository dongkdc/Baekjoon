#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node* llink;
    struct node* rlink;
}node;

// 원하는 노드의 주소 반환
node* find(node* n,char value){
    if(n==NULL) return NULL;

    if(n!=NULL){
        if(n->data == value){
            return n;
        }

        node* l = find(n->llink,value);
        if(l != NULL) return l;

        return find(n->rlink,value);
   }
}

// 노드 추가
node* add_node(char name){
    node* temp = (node*) malloc(sizeof(node));
    temp-> data = name;
    temp->llink = NULL;
    temp->rlink = NULL;

    return temp;
}

// 부모노드와 자식노드 연결
void connect(node* parent, node* children,char direct){
    if(direct == 'L'){ // 왼쪽 자식 노드인 경우
        parent->llink = children;
    }
    else if(direct == 'R'){ // 오른쪽 자식 노드인 경우
        parent->rlink = children;
    }
}

// 전위 순회
void pre(node* root){
    if(root != NULL){
        printf("%c",root->data);
        pre(root->llink);
        pre(root->rlink);
    }
}

// 중위 순회
void mid(node* root){
    if(root != NULL){
        mid(root->llink);
        printf("%c",root->data);
        mid(root->rlink);
    }
}


// 후위 순회
void post(node* root){
    if(root != NULL){
        post(root->llink);
        post(root->rlink);
        printf("%c",root->data);
    }
}

int main(void){
    int N;
    scanf("%d",&N);

    node* root = (node*) malloc(sizeof(node));

    root->data = 'A';
    root->llink = NULL;
    root->rlink = NULL;

    // 이진 노드 형성
    for(int i=0 ;i<N;i++){
        char P_N; // 부모
        char l_n; // 왼쪽 자식 값
        char r_n; // 오른쪽 자식 값

        scanf(" %c %c %c",&P_N,&l_n,&r_n);
        
        node* p = find(root,P_N); // 부모 노드 주소    
        node* L;
        node* R;
        if(l_n != '.') {
            L = add_node(l_n);
            connect(p,L,'L');
        }
        if(r_n != '.') {
            R = add_node(r_n);
            connect(p,R,'R');
        } 
    }
    pre(root);
    printf("\n");
    mid(root);
    printf("\n");
    post(root);

    free(root);

}