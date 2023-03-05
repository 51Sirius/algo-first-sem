#include <iostream>
#include <cmath>
#include "vector"

bool flag = true;
using namespace std;

struct Node {
    int key;
    int left;
    int right;
};

void getHeight(int root, vector<Node> &arr, int minimal, int maxi) {
    if (arr[root].key <= minimal or arr[root].key >= maxi) {
        flag = false;
        return;
    }
    if (arr[root].right != 0) {
        getHeight(arr[root].right, arr, arr[root].key, maxi);
    }
    if (arr[root].left != 0) {
        getHeight(arr[root].left, arr, minimal, arr[root].key);
    }
}


int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << "YES";
        return 0;
    }
    vector<Node> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i].key >> arr[i].left >> arr[i].right;
    }

    int minimal = pow(-10, 9) - 100;
    int maxi = pow(10, 9) + 100;
    getHeight(1, arr, minimal, maxi);
    if (flag) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}