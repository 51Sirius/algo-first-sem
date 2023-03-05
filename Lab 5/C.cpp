#include <iostream>
#include "vector"

using namespace std;

struct Node {
    int key;
    int left;
    int right;
};

int counting = 1;

void set_wood(vector<Node> &arr, int root) {
    if (arr[root].left != 0) {
        set_wood(arr, arr[root].left);
    }
    arr[root].key = counting;
    counting++;
    if (arr[root].right != 0) {
        set_wood(arr, arr[root].right);
    }
}

int main() {
    int n;
    std::cin >> n;
    vector<Node> arr(n+1);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i].left >> arr[i].right;
    }
    set_wood(arr, 1);
    for (int i = 1; i <= n; i++) {
        std::cout << arr[i].key << ' ';
    }
}