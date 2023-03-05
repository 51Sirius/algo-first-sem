#include <iostream>
#include <cmath>
#include "vector"

using namespace std;


struct Node {
    int key;
    Node *left;
    Node *right;
};

void postorderTraversal(Node *&root) {
    if (root->left != nullptr) {
        postorderTraversal(root->left);
    }
    if (root->right != nullptr) {
        postorderTraversal(root->right);
    }
    std::cout << root->key << " ";
}

int minimal(Node *&root) {
    if (root->left == nullptr) {
        return root->key;
    }
    return minimal(root->left);
}


int maximal(Node *&root) {
    if (root->right == nullptr) {
        return root->key;
    }
    return maximal(root->right);
}

Node *next(Node *&root, int z) {
    Node *tmp = root;
    Node *last_save;
    bool flag = false;
    while (tmp != nullptr) {
        if (tmp->key > z) {
            flag = true;
            last_save = tmp;
            tmp = tmp->left;
        } else tmp = tmp->right;
    }
    if (flag) {
        return last_save;
    } else {
        return nullptr;
    }
}


Node *prev(Node *&root, int z) {
    Node *tmp = root;
    Node *last_save;
    bool flag = false;
    while (tmp != nullptr) {
        if (tmp->key < z) {
            flag = true;
            last_save = tmp;
            tmp = tmp->right;
        } else tmp = tmp->left;
    }
    if (flag) {
        return last_save;
    } else {
        return nullptr;
    }
}

Node *insert(Node *&root, int z) {
    if (root == nullptr) {
        root = new Node;
        root->key = z;
        root->left = nullptr;
        root->right = nullptr;
    } else if (root->key > z) {
        insert(root->left, z);
    } else if (root->key < z) {
        insert(root->right, z);
    }
    return root;
}


Node *exists(Node *&root, int z) {
    if (root == nullptr) {
        return root;
    }
    if (root->key == z) {
        return root;
    }
    if (root->key > z) {
        return exists(root->left, z);
    }

    if (root->key < z) {
        return exists(root->right, z);
    }
}


Node *remove(Node *&root, int z) {
    if (root == nullptr) {
        return root;
    }
    if (root->key > z) {
        root->left = remove(root->left, z);
    } else if (root->key < z) {
        root->right = remove(root->right, z);
    } else if (root->right != nullptr and root->left != nullptr) {
        root->key = minimal(root->right);
        root->right = remove(root->right, root->key);
    } else {
        if (root->left != nullptr) {
            root = root->left;
        } else if (root->right != nullptr){
            root = root->right;
        } else {
            root = nullptr;
        }
    }
    return root;
}


int main() {
    Node *root = nullptr;
    std::string operation;
    int value;
    while (std::cin >> operation) {
        std::cin >> value;
        if (operation == "insert") {
            insert(root, value);
        }
        if (operation == "delete") {
            remove(root, value);
        }
        if (operation == "exists") {
            Node *tmp = exists(root, value);
            if (tmp != nullptr) {
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        }
        if (operation == "next") {
            Node *tmp = next(root, value);
            if (tmp == nullptr) {
                std::cout << "none\n";
            } else {
                std::cout << tmp->key << "\n";
            }
        }
        if (operation == "prev") {
            Node *tmp = prev(root, value);
            if (tmp == nullptr) {
                std::cout << "none\n";
            } else {
                std::cout << tmp->key << "\n";
            }
        }

    }
    return 0;
}