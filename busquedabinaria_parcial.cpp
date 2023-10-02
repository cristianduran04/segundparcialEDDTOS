#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}


int search(TreeNode* root, int val) {
    if (root == nullptr) {
        return -1; // No se encontró el valor
    }
    if (root->data == val) {
        return val; // Se encontró el valor
    } else if (val < root->data) {
        return search(root->left, val); // Buscar en el subárbol izquierdo
    } else {
        return search(root->right, val); 
    }
}

int main() {
    TreeNode* root = nullptr;

 
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    cout << "Ingrese un número a buscar en el árbol: ";
    int val;
    cin >> val;

    int result = search(root, val);

    if (result == -1) {
        cout << "-1" << endl;
    } else {
        cout << val << endl;
    }

    return 0;
}
