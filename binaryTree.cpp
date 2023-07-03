#include <iostream>

class Node {
public:
  int key;
  Node *left;
  Node *right;
  Node(int key) {
    this->key = key;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
private:
  Node *root;

  Node *insertNodeRecursive(Node *root, int key) {
    if (root == nullptr) {
      return new Node(key);
    }

    if (key < root->key) {
      root->left = insertNodeRecursive(root->left, key);
    } else if (key > root->key) {
      root->right = insertNodeRecursive(root->right, key);
    }

    return root;
  }

  Node *searchNodeRecursive(Node *root, int key) {
    if (root == nullptr || root->key == key) {
      return root;
    }

    if (key < root->key) {
      return searchNodeRecursive(root->left, key);
    } else {
      return searchNodeRecursive(root->right, key);
    }
  }

  Node *findMinNode(Node *node) {
    Node *current = node;
    while (current && current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  Node *deleteNodeRecursive(Node *root, int key) {
    if (root == nullptr) {
      return nullptr;
    }

    if (key < root->key) {
      root->left = deleteNodeRecursive(root->left, key);
    } else if (key > root->key) {
      root->right = deleteNodeRecursive(root->right, key);
    } else {
      // Caso 1: Nó sem filhos ou com apenas um filho
      if (root->left == nullptr) {
        Node *temp = root->right;
        delete root;
        return temp;
      } else if (root->right == nullptr) {
        Node *temp = root->left;
        delete root;
        return temp;
      }

      // Caso 2: Nó com dois filhos
      Node *minRight = findMinNode(root->right);
      root->key = minRight->key;
      root->right = deleteNodeRecursive(root->right, minRight->key);
    }

    return root;
  }

  void inOrderTraversal(Node *root) {
    if (root == nullptr) {
      return;
    }

    inOrderTraversal(root->left);
    std::cout << root->key << " ";
    inOrderTraversal(root->right);
  }

  void preOrderTraversal(Node *root) {
    if (root == nullptr) {
      return;
    }

    std::cout << root->key << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }

  void posOrderTraversal(Node *root) {
    if (root == nullptr) {
      return;
    }
    posOrderTraversal(root->left);
    posOrderTraversal(root->right);
    std::cout << root->key << " ";
  }

public:
  BinaryTree() { root = nullptr; }

  void insertNode(int key) { root = insertNodeRecursive(root, key); }

  Node *searchNode(int key) { return searchNodeRecursive(root, key); }

  void inOrder() { inOrderTraversal(root); }

  void preOrder() { preOrderTraversal(root); }

  void posOrder() { posOrderTraversal(root); }

  void deleteNode(int key) { root = deleteNodeRecursive(root, key); }
};

int main() {
  BinaryTree tree;

  tree.insertNode(50);
  tree.insertNode(60);
  tree.insertNode(55);
  tree.insertNode(20);
  tree.insertNode(30);
  tree.insertNode(22);
  tree.insertNode(15);
  tree.insertNode(65);

  std::cout << "Pre order :";
  tree.preOrder();
  std::cout << std::endl;

  std::cout << "In order :";
  tree.inOrder();
  std::cout << std::endl;

  std::cout << "Pos order :";
  tree.posOrder();
  std::cout << std::endl;

  int key = 65;
  Node *result = tree.searchNode(key);

  if (result != nullptr) {
    std::cout << key << " Foi encontrado";
  } else {
    std::cout << key << " Não Foi encontrado";
  }

  tree.deleteNode(key);

  result = tree.searchNode(key);

  if (result != nullptr) {
    std::cout << key << " Foi encontrado";
  } else {
    std::cout << key << " Não Foi encontrado";
  }

  return 0;
}