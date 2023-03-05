#include <iostream>
#include <cmath>
#include "vector"

using namespace std;

struct Node {
    int key;
    int right;
    int left;
    int parent;
};
int counting = 1;

void requrtion_to_next(vector<Node> &arr, int n, int minimal, int maximal) {
    if (counting == n) {
        return;
    }

    if (arr[counting].key < minimal or arr[counting].key > maximal) {
        return;
    }
    int z = arr[counting].key;
    counting++;
    requrtion_to_next(arr, n, minimal, z);
    requrtion_to_next(arr, n, z, maximal);
    std::cout << z << " ";
}

int main() {
    int n;
    std::cin >> n;
    vector<Node> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i].key;
    }
    for (int i = 0; i < n; ++i) {
        requrtion_to_next(arr, n + 1, -1000000000, 100000000);
    }
    return 0;
}