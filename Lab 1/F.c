#include <stdio.h>

struct Fridge {
    int milk;
    int meat;
    int cheese;
    int sweet;
};

int main() {
    struct Fridge my = {10,19, 20, 30};
    struct Fridge friend_fridge = {5,1, 1000, 12};
    printf("Our meat: %d", my.meat+friend_fridge.meat);
    my.meat += friend_fridge.meat;
    friend_fridge.meat = 0; //Друг отдал все мясо мне !!!
    return 0;
}