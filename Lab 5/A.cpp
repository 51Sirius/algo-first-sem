#include <iostream>
#include "vector"

using namespace std;

struct Node {
    int key;
    int left;
    int right;
};


int getHeight(int current_height, int root, int new_height, vector<Node> &arr) {
    if (current_height < new_height) {
        current_height = new_height;
    }
    if (arr[root].right != 0) {
        current_height = getHeight(current_height, arr[root].right, new_height + 1, arr);
    }
    if (arr[root].left != 0) {
        current_height = getHeight(current_height, arr[root].left, new_height + 1, arr);
    }
    return current_height;

}


int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0;
        return 0;
    }
    vector<Node> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i].key >> arr[i].left >> arr[i].right;
    }
    int height = getHeight(0, 1, 1, arr);
    std::cout << height;
    return 0;
}