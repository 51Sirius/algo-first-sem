#include <iostream>

typedef struct node {
    char key;
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

void push(qu *queue, char value) {
    queue->tail->next = new node;
    queue->tail->next->prev = queue->tail;
    queue->tail = queue->tail->next;
    queue->tail->key = value;
    queue->tail->next = nullptr;
    queue->count++;
}

char pop(qu *queue) {
    char tmp;
    tmp = queue->tail->key;
    queue->tail = queue->tail->prev;
    queue->count--;
    return tmp;
}

int main() {
    std::string s;
    while (std::cin >> s) {
        bool flag = true;
        qu string;
        create(&string);
        for (int i = 0; i < s.size(); i++) {
            if(s[i]==')'){
                if(string.tail->key != '('){
                    flag=false;
                    break;
                }
                else{
                    pop(&string);
                }
            }
            else if(s[i]==']'){
                if(string.tail->key != '['){
                    flag=false;
                    break;
                }
                else{
                    pop(&string);
                }
            }
            else {
                push(&string, s[i]);
            }
        }
        if(string.head->key != pop(&string)){
            flag=false;
        }
        if(flag){
            std::cout<<"YES\n";
        }
        else{
            std::cout<<"NO\n";
        }
    }
    return 0;
}