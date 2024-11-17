#ifndef BSTREE_H
#define BSTREE_H

#include <string>
#include <iostream>

struct Node {
    std::string data;
    Node *left;
    Node *right;
    Node(const std::string& data) : data(data), left(nullptr), right(nullptr) {}
};

class BSTree {
    friend std::ostream& operator<<(std::ostream&, const BSTree&);
public:
    BSTree();
    BSTree(const BSTree&);
    ~BSTree();
    bool isEmpty() const;
    int getSize() const { return size; }
    bool retrieve(const std::string&, Node*&) const;
    bool insert(const std::string&);
    void displayTree() const;
    void displaySideways() const;
    int getHeight(const std::string&) const;
    BSTree& operator=(const BSTree&);
    bool operator==(const BSTree&) const;
    bool operator!=(const BSTree&) const;
    void bstreeToArray(std::string[]);
    void arrayToBSTree(std::string[]);
private:
    Node* root;
    int size;
    Node* copyHelper(Node* node);
    void destroyHelper(Node* node);
    bool retrieveHelper(const std::string& data, Node* current, Node*& foundNode) const;
    bool insertHelper(std::string data, Node*& parent);
    void displayTreeHelper(Node* node, std::string prefix, bool isLeft) const;
    void displaySidewaysHelper(Node* current, int level) const;
    int getHeightHelper(const std::string& data, Node* node, int height) const;
    void bstreeToArrayHelper(Node* node, std::string arr[], int& index);
    Node* arrayToBSTreeHelper(std::string arr[], int start, int end);
    void inOrderTraversal(std::ostream& os, Node* node) const;
    bool isEqual(Node* node1, Node* node2) const;
    bool isNumber(const std::string& str) const;
};

#endif