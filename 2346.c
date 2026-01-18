#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    int id;
    struct list* f_link;
    struct list* b_link;

}List;

List* add_node(int value ,List* pre){
    List* temp = (List*) malloc(sizeof(List));
    pre->f_link = temp;
    temp->data = value;
    temp->f_link = NULL;
    temp->b_link = pre;
    return temp;
}

List* del(List* pre,List* cur){
    pre->f_link = cur->f_link;
    cur->f_link->b_link = pre;
    free(cur);
    return pre;
}



int main(void){
    int N,paper=0;
    int arr[1001];
    List* ballon;
    List* head = (List*) malloc(sizeof(List));
    List* pre = head;

    scanf("%d",&N);


    //연결 리스트 생성
    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);
        if(i==0){
            head->data = num;
            head->id = i+1;
        }
        else{
            pre = add_node(num,pre);
            pre->id = i+1;
        }       
    }
    pre->f_link = head; // 원형 연결리스트 만들기
    head->b_link = pre;
    
    ballon = pre; // 원하는 풍선 바로 이전을 가르킨다.

    for(int i=0;i<N;i++){
        arr[i] = ballon->f_link->id;
        paper = ballon->f_link->data;
        ballon = del(ballon,ballon->f_link);

        // 풍선 이동
        if(paper>0){ 
            for(int j=0;j<paper-1;j++){ 
                ballon = ballon->f_link;
            }
        }
        else{
            for(int j=0;j<-paper;j++){ 
                ballon = ballon->b_link;
            }
        }

    }

    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}