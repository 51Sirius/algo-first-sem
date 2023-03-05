#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int queue;
    int height;
};

int set_height(Node *cur) {
    if (cur == nullptr) return 0;
    else {
        int right_height = set_height(cur->right);
        int left_height = set_height(cur->left);
        cur->height = left_height - right_height;
        if (right_height > left_height) {
            return 1 + right_height;
        } else {
            return 1 + left_height;
        }
    }
}

Node *left_rotate(Node *root) {
    Node *p = root->right;
    root->right = p->left;
    p->left = root;
    set_height(root);
    set_height(p);
    return p;
}

Node *right_rotate(Node *root) {
    Node *p = root->left;
    root->left = p->right;
    p->right = root;
    set_height(root);
    set_height(p);
    return p;
}


Node *balance(Node *root) {
    set_height(root);
    if (root->right->height == 1) {
        root->right = right_rotate(root->right);
    }
    return left_rotate(root);
}

void set_queue(Node *root, int &index) {
    if (root == nullptr) return;
    root->queue = index;
    index++;
    set_queue(root->left, index);
    set_queue(root->right, index);
}

void custom_order(Node *root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        if (root->left != nullptr) std::cout << root->left->queue << ' ';
        else std::cout << "0" << " ";
        if (root->right != nullptr) std::cout << root->right->queue << '\n';
        else std::cout << "0" << "\n";
        custom_order(root->left);
        custom_order(root->right);
    }
}

int main() {
    int n;
    int left;
    int right;
    std::cin >> n;
    Node arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].key >> left >> right;
        arr[i].left = nullptr;
        arr[i].right = nullptr;
        arr[i].height = 0;
        arr[i].height = 0;
        if (left != 0) {
            arr[i].left = &arr[left - 1];
        }
        if (right != 0) {
            arr[i].right = &arr[right - 1];
        }
    }
    Node *root = arr;
    set_height(root);
    root = balance(root);
    int number = 1;
    set_queue(root, number);
    std::cout << n << "\n";
    custom_order(root);
    return 0;
}