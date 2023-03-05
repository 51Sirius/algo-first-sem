#include <iostream>
#include <cstring>

using namespace std;

void build_tree(int current, int left_tree, int right_tree, int tree[], int arr[]) {
    if (left_tree == right_tree)
        tree[current] = arr[left_tree];
    else {
        int tm = (left_tree + right_tree) / 2;
        build_tree(current * 2, left_tree, tm, tree, arr);
        build_tree(current * 2 + 1, tm + 1, right_tree, tree, arr);
        tree[current] = tree[current * 2] + tree[current * 2 + 1];
    }
}

int get_sum(int current, int left_tree, int right_tree, int left, int right, int tree[]) {
    if (left > right) {
        return 0;
    }
    if (left == left_tree and right == right_tree) {
        return tree[current];
    }
    int srz = (left_tree + right_tree) / 2;
    int tmp_r;
    int tmp_l;
    if (right < srz) {
        tmp_r = right;
    } else {
        tmp_r = srz;
    }
    if (left > srz + 1) {
        tmp_l = left;
    } else {
        tmp_l = srz + 1;
    }
    return get_sum(current * 2, left_tree, srz, left, tmp_r, tree)
           + get_sum(current * 2 + 1, srz + 1, right_tree, tmp_l, right, tree);
}

void update(int current, int left_tree, int right_tree, int index, int value, int tree[]) {
    if (left_tree == right_tree)
        tree[current] = value;
    else {
        int srz = (left_tree + right_tree) / 2;
        if (index <= srz)
            update(current * 2, left_tree, srz, index, value, tree);
        else
            update(current * 2 + 1, srz + 1, right_tree, index, value, tree);
        tree[current] = tree[current * 2] + tree[current * 2 + 1];
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    int a;
    int b;
    char cmd;
    int arr[4 * n];
    memset(arr, 0, n * 4 * sizeof(int));
    int tree[16 * n];
    memset(tree, 0, n * 4 * 4 * sizeof(int));
    build_tree(1, 0, n - 1, tree, arr);
    for (int j = 0; j < m; j++) {
        cin >> cmd;
        cin >> a >> b;
        if (cmd == '+') {
            arr[a - 1] += b;
            update(1, 0, n * 4 - 1, a, arr[a - 1], tree);
        } else if (cmd == '-') {
            arr[a - 1] -= b;
            if (arr[a - 1] < 0) {
                arr[a - 1] = 0;
            }
            update(1, 0, n * 4 - 1, a, arr[a - 1], tree);
        } else if (cmd == '?') {
            cout << get_sum(1, 0, n * 4 - 1, a, b, tree) << '\n';
        }
    }
    return 0;
}
