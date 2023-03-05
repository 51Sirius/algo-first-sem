#include <iostream>
#include <cmath>
#include "vector"

using namespace std;


struct Node {
    std::string key;
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

std::string minimal(Node *&root) {
    if (root->left == nullptr) {
        return root->key;
    }
    return minimal(root->left);
}


std::string maximal(Node *&root) {
    if (root->right == nullptr) {
        return root->key;
    }
    return maximal(root->right);
}

Node *next(Node *&root, std::string z) {
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


Node *prev(Node *&root, std::string z) {
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

Node *insert(Node *&root, std::string z) {
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


Node *exists(Node *&root, std::string z) {
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


Node *remove(Node *&root, std::string z) {
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
        } else if (root->right != nullptr) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }
    return root;
}


int main() {
    Node *root[3] = {nullptr, nullptr, nullptr};
    std::string strings[3][10001];
    int n;
    std::cin >> n;
    std::string value;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> value;
            strings[i][j] = value;
            insert(root[i], value);
        }
    }
    int points[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            int sovpalo = 0;
            int coincid[3] = {0, 0, 0};
            for (int k = 0; k < 3; k++) {
                if (exists(root[k], strings[i][j]) != nullptr) {
                    sovpalo++;
                    coincid[k] = 1;
                    remove(root[k], strings[i][j]);
                }
            }
            if (sovpalo == 1) {
                for (int p = 0; p < 3; p++) {
                    if (coincid[p] == 1) {
                        points[p] += 3;
                    }
                }
            } else if (sovpalo == 2) {
                for (int p = 0; p < 3; p++) {
                    if (coincid[p] == 1) {
                        points[p] += 1;
                    }
                }
            }
        }
    }
    std::cout << points[0] << " " << points[1] << " " << points[2];
    return 0;
}