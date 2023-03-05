#include <iostream>
#include <cmath>
#include "vector"

using namespace std;

struct Node {
    int key;
    int left;
    int right;
    int height;
};

int setHeight(int root, vector<Node> &arr) {
    int rightHeight = 0;
    int leftHeight = 0;
    if (arr[root].left != 0) {
        leftHeight = setHeight(arr[root].left, arr);
    }
    if (arr[root].right != 0) {
        rightHeight = setHeight(arr[root].right, arr);
    }

    if (arr[root].right != 0 and arr[root].left != 0) {
        arr[root].height = rightHeight - leftHeight;
        if (rightHeight >= leftHeight) return rightHeight+1;
        else return leftHeight + 1;
    } else if (arr[root].right != 0 and arr[root].left == 0) {
        arr[root].height = rightHeight;
        return rightHeight + 1;
    } else if (arr[root].right == 0 and arr[root].left != 0) {
        arr[root].height = -leftHeight;
        return leftHeight + 1;
    } else {
        arr[root].height = 0;
        return 1;
    }
}


int main() {
    int n;
    std::cin >> n;
    vector<Node> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i].key >> arr[i].left >> arr[i].right;
    }
    setHeight(1, arr);
    for (int i = 1; i <= n; ++i) {
        std::cout << arr[i].height << '\n';
    }
    return 0;
}