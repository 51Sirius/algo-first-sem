#include <iostream>
using namespace std;

typedef struct node {
    int key;
    struct node *next;
    struct node *prev;
} node;

typedef struct qu {
    node *head;
    node *tail;
    int count;
} qu;

void create(qu *queue) {
    queue->head = new node;
    queue->head->next = nullptr;
    queue->head->prev = nullptr;
    queue->tail = queue->head;
    queue->count = 0;
}

void push(qu *queue, int value) {
    queue->tail->next = new node;
    queue->tail->next->prev = queue->tail;
    queue->tail = queue->tail->next;
    queue->tail->key = value;
    queue->tail->next = nullptr;
    queue->count++;
}

int pop(qu *queue) {
    int tmp;
    tmp = queue->tail->key;
    queue->tail = queue->tail->prev;
    queue->count--;
    return tmp;
}

int main() {
    qu queue;
    create(&queue);
    char s;
    int result = 0;
    char trash;
    while (std::cin >> s) {
        if (s == '+') {
            result = queue.tail->prev->key;
            result += queue.tail->key;
            pop(&queue);
            pop(&queue);
            push(&queue, result);
        } else if (s == '-') {
            result = queue.tail->prev->key;
            result -= queue.tail->key;
            pop(&queue);
            pop(&queue);
            push(&queue, result);
        } else if (s == '*') {
            result = queue.tail->prev->key;
            result *= queue.tail->key;
            pop(&queue);
            pop(&queue);
            push(&queue, result);
        } else {
            int numb=(int)s -48;
            push(&queue, numb);
        }
    }
    std::cout<< queue.tail->key << "\n";
    return 0;
}


