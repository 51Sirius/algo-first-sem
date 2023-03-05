#include <iostream>

typedef struct node{
    int key;
    int max;
    struct node *next;
    struct node *prev;
} node;

typedef struct qu {
    node *head;
    node *tail;
    int count;
} qu;

void create(qu *queue){
    queue->head= new node;
    queue->head->next= nullptr;
    queue->head->max= 0;
    queue->head->prev= nullptr;
    queue->tail=queue->head;
    queue->head->next=queue->tail;
    queue->count = 0;
}

void push(qu *queue, int value){
    queue->tail->next= new node;
    queue->tail->next->prev = queue->tail;
    queue->tail=queue->tail->next;
    queue->tail->key=value;
    queue->tail->next= nullptr;
    queue->count++;
    if (queue->count == 1){
        queue->head->max = value;
        queue->tail->max = value;
    }
    if (value > queue->tail->prev->max){
        queue->tail->max = value;
    } else {
        queue->tail->max = queue->tail->prev->max;
    }
}

int pop(qu *queue){
    int tmp;
    tmp = queue->tail->key;
    queue->tail=queue->tail->prev;
    queue->count--;
    return tmp;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    qu queue;
    create(&queue);
    int n;
    char operation;
    std::cin >> n;
    int value;
    for (int i = 0;i<n;i++){
        std::cin >> operation;
        if (operation == '+'){
            std::cin>>value;
            push(&queue, value);
        }
        else if(operation == '-'){
            pop(&queue);
        } else{
            std::cin >> operation;
            std::cin >> operation;
            std::cout << queue.tail->max << "\n";

        }
    }
    return 0;
}