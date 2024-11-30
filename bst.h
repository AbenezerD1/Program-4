#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
#include "classics.h"

template <typename Movie>
class BSTNode {
public:
    Movie* data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Movie* movie) : data(movie), left(nullptr), right(nullptr) {}
    ~BSTNode() {
        delete left;
        delete right;
        delete data;
    }
};

template <typename Movie>
class BST {
public:
    BST() : root(nullptr) {}
    ~BST() { destroyHelper(root); }

    void insert(Movie* movie) { insert(root, movie); }
    bool get(const std::string& key, Movie* movie) { return get(root, key, movie); }
    void print() const { inorderPrint(root); }

private:
    BSTNode<Movie>* root;

    // General insert for other types
    void insert(BSTNode<Movie>*& node, Movie* movie) {
        if (node == nullptr) {
            node = new BSTNode<Movie>(movie);
        } else if (movie->getTitle() < node->data->getTitle()) {
            insert(node->left, movie);
        } else {
            insert(node->right, movie);
        }
    }

    bool get(BSTNode<Movie>* node, const std::string& key, Movie* movie) {
        if (node == nullptr) {
            movie = nullptr;
            return false;
        }
        if (node->data->getTitle() == key) {
            movie = node->data;
            return true;
        }
        if (key < node->data->getTitle()) {
            return get(node->left, key, movie);
        } else {
            return get(node->right, key, movie);
        }
    }

    void inorderPrint(BSTNode<Movie>* node) const {
        if (node != nullptr) {
            inorderPrint(node->left);
            std::cout << node->data->getTitle() << std::endl;
            inorderPrint(node->right);
        }
    }

    void destroyHelper(BSTNode<Movie>* node) {
        if (node != nullptr) {
            destroyHelper(node->left);
            destroyHelper(node->right);
            delete node;
        }
    }
};

#endif