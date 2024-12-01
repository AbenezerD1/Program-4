#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
#include "classics.h"
#include "classicssummary.h"

template <typename Movie>
class BSTNode {
public:
    Movie* data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Movie* movie) : data(movie), left(nullptr), right(nullptr) {}
    ~BSTNode() {
        delete data;
    }
};

template <typename Movie>
class BST {
public:
    BST() : root(nullptr) {}
    ~BST() { destroyHelper(root); }

    void insert(Movie* movie) { insert(root, movie); }
    bool get(const std::string& key, Movie*& movie) { return get(root, key, movie); }
    bool inorderSearch(const std::string& key, Movie*& movie) { return inorderSearch(root, key, movie); }
    void print() const { inorderPrint(root); }
    void printClassics() const { 
        ClassicsSummary cs;
        inorderPrintClassics(root, cs);
        cs.flush();
    }

private:
    BSTNode<Movie>* root;

    void insert(BSTNode<Movie>*& node, Movie* movie) {
        if (node == nullptr) {
            node = new BSTNode<Movie>(movie);
        } else if (movie->getSortingKey() < node->data->getSortingKey()) {
            insert(node->left, movie);
        } else {
            insert(node->right, movie);
        }
    }

    bool get(BSTNode<Movie>* node, const std::string& key, Movie*& movie) {
        if (node == nullptr) {
            movie = nullptr;
            return false;
        }
        if (node->data->getSortingKey() == key) {
            movie = node->data;
            return true;
        }
        if (key < node->data->getSortingKey()) {
            return get(node->left, key, movie);
        } else {
            return get(node->right, key, movie);
        }
    }

    bool inorderSearch(BSTNode<Movie>* node, const std::string& mergeKey, Movie*& movie) const {
        if (node != nullptr) {
            inorderSearch(node->left, mergeKey, movie);
            if (mergeKey == node->data->getMergeKey() && node->data->getStock() > 0) {
                movie = node->data;
                return true;
            }
            inorderSearch(node->right, mergeKey, movie);
        }
        return false;
    }

    void inorderPrint(BSTNode<Movie>* node) const {
        if (node != nullptr) {
            inorderPrint(node->left);
            if (node->data->getGenre() == 'C') {
                Classics* c = static_cast<Classics*>(node->data);
                std::cout << *c << std::endl;
            } else {
                std::cout << *(node->data) << std::endl;
            }
            inorderPrint(node->right);
        }
    }

    void inorderPrintClassics(BSTNode<Movie>* node, ClassicsSummary& cs) const {
        if (node != nullptr) {
            inorderPrintClassics(node->left, cs);
            cs.add(static_cast<Classics*>(node->data));
            inorderPrintClassics(node->right, cs);
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