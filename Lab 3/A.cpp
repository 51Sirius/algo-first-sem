#include <iostream>

typedef struct node{
    int key;
    struct node *next;
} node;

typedef struct qu {
    node *head;
    node *tail;
    int count;
} qu;

void create(qu *queue){
    queue->head= new node;
    queue->head->next= nullptr;
    queue->tail=queue->head;
    queue->count = 0;
}

void push(qu *queue, int value){
    queue->tail->next= new node;
    queue->tail=queue->tail->next;
    queue->tail->key=value;
    queue->tail->next= nullptr;
    queue->count++;
}

int pop(qu *queue){
    int tmp;
    tmp = queue->head->next->key;
    queue->head=queue->head->next;
    queue->count--;
    return tmp;
}

int main(){
    qu queue;
    create(&queue);
    int n;
    char operation;
    std::cin >> n;
    int value;
    int arr[n-1];
    int count_del=0;
    for (int i = 0;i<n;i++){
        std::cin >> operation;
        if (operation == '+'){
            std::cin>>value;
            push(&queue, value);
        }
        else{
            arr[count_del] = pop(&queue);
            count_del++;
        }
    }
    for (int i = 0;i<count_del;i++){
        std::cout << arr[i] << "\n";
    }
    return 0;
}