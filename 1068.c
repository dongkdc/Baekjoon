#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* child;
    struct node* sibling;
}Node;

Node* find(Node* head, int value){
    if(!head) return NULL;

    if(head->data == value){
        return head;
    }
    // 왼쪽 자식
    Node* res = find(head->child,value);
    if(res!=NULL) return res;
    // 오른쪽 형제
    return find(head->sibling,value);
}

void add(Node* head,int value,int d){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->child = NULL;
    temp->sibling = NULL;
    
    // 원하는 노드 찾기
    Node* res = find(head,value);
    if (res == NULL) return;
    
    // 첫 자식인 경우
    if(res->child == NULL){
        res->child = temp;
    }
    // 이미 자식이 있는 경우 -> 형제 노드로 들어감
    else{
        res = res->child;
        while(res->sibling!=NULL){
            res = res->sibling;
        }
        res->sibling = temp;
    }
} 

int count(Node* head){
    int cnt=0;
    if(head == NULL) return 0;

    Node* n = head->child;
    if(n == NULL) return 1 + count(head->sibling);

    return count(head->child) + count(head->sibling);
}

void eraser(Node* head,int value){
    if(head == NULL) return;

    if(head->child != NULL && head->child->data == value){
        head->child = head->child->sibling;
        return;
    }
    else if(head->sibling != NULL && head->sibling->data == value){
        head->sibling = head->sibling->sibling;
        return;
    }
    else{
        eraser(head->child,value);
        eraser(head->sibling,value);
    }
}

int main(void){
    int N;
    scanf("%d",&N);

    Node* head = (Node*)malloc(sizeof(Node));

    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);

        // 루트 노드
        if(num == -1){
            head->data = i;
            head->sibling = NULL;
            head->child = NULL;
        }
        else{
            add(head,num,i);
        } 
    }

    int del;
    scanf("%d",&del);

    eraser(head,del);

    if(del == 0){
        printf("0");
        return 0;
    }

    printf("%d",count(head));
}