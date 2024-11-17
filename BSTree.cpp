#include "BSTree.h"

BSTree::BSTree() : root(nullptr), size(0) {}

BSTree::BSTree(const BSTree& rhs) {
    if (rhs.root != nullptr) {
        root = copyHelper(rhs.root);
    }
}

Node* BSTree::copyHelper(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    Node* newNode = new Node(node->data);
    newNode->left = copyHelper(node->left);
    newNode->right = copyHelper(node->right);
    return newNode;
}

BSTree::~BSTree() {
    destroyHelper(root);
    root = nullptr;
}

void BSTree::destroyHelper(Node* node) {
    if (node != nullptr) {
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
}

bool BSTree::isEmpty() const {
    return size == 0;
}

bool BSTree::retrieve(const std::string& data, Node*& foundNode) const {
    return retrieveHelper(data, root, foundNode);
}

bool BSTree::retrieveHelper(const std::string& data, Node* current, Node*& foundNode) const {
    if (current == nullptr) {
        return false;
    }
    bool dataIsNumber = isNumber(data);
    bool nodeDataIsNumber = isNumber(current->data);
    // Compare numbers
    if (dataIsNumber && nodeDataIsNumber) {
        int numData = std::stoi(data);
        int numNodeData = std::stoi(current->data);
        if (numData < numNodeData) {
            return retrieveHelper(data, current->left, foundNode);
        } else if (numData > numNodeData) {
            return retrieveHelper(data, current->right, foundNode);
        } else {
            foundNode = current;
            return true;
        }
    } 
    // Compare strings
    else {
        if (data < current->data) {
            return retrieveHelper(data, current->left, foundNode);
        } else if (data > current->data) {
            return retrieveHelper(data, current->right, foundNode);
        } else {
            foundNode = current;
            return true;
        }
    }
}

bool BSTree::insert(const std::string& data) {
    return insertHelper(data, root);
}

bool BSTree::insertHelper(std::string data, Node*& node) {
    if (node == nullptr) {
        node = new Node(data);
        size++;
        return true;
    }
    bool dataIsNumber = isNumber(data);
    bool nodeDataIsNumber = isNumber(node->data);
    // Compare numbers
    if (dataIsNumber && nodeDataIsNumber) {
        int numData = std::stoi(data);
        int numNodeData = std::stoi(node->data);
        if (numData < numNodeData) {
            return insertHelper(data, node->left);
        } else if (numData > numNodeData) {
            return insertHelper(data, node->right);
        } else {
            return false;
        }
    // Compare strings
    } else {
        if (data < node->data) {
            return insertHelper(data, node->left);
        } else if (data > node->data) {
            return insertHelper(data, node->right);
        } else {
            return false;
        }
    }
}

void BSTree::displayTree() const {
    if (root == nullptr) {
        std::cout << "The tree is empty." << std::endl;
    } else {
        displayTreeHelper(root, "", true);
    }
}

void BSTree::displayTreeHelper(Node* node, std::string prefix, bool isLeft) const {
    if (node == nullptr) {
        return;
    }
    // Print the current prefix
    std::cout << prefix;
    // Add root or L--- / R---
    if (prefix.empty()) {
        std::cout << "Root: ";
    } else {
        std::cout << (isLeft ? "L---" : "R---");
    }
    // Print the current node's data
    std::cout << node->data << std::endl;
    // Prepare new prefix for children
    std::string newPrefix = prefix + "     ";
    // Recurse on left and right children
    displayTreeHelper(node->left, newPrefix, true);
    displayTreeHelper(node->right, newPrefix, false);
}

void BSTree::displaySideways() const {
    displaySidewaysHelper(root, 0);
}

void BSTree::displaySidewaysHelper(Node* current, int level) const {
    if (current != nullptr) {
        // Traverse the right subtree first
        displaySidewaysHelper(current->right, level + 1);
        // Print spaces proportional to the level to create indentation
        for (int i = 0; i < level; i++) {
            std::cout << "     ";
        }
        // Print the current node's data
        std::cout << current->data << std::endl;
        // Traverse the left subtree
        displaySidewaysHelper(current->left, level + 1);
    }
}

int BSTree::getHeight(const std::string& data) const {
    int height = 0;
    return getHeightHelper(data, root, height);
}

// Helper function to find the node and compute height
int BSTree::getHeightHelper(const std::string& data, Node* node, int height) const {
    // Node not found or tree is empty
    if (node == nullptr) {
        return 0;
    }
    // Calculate height from current node
    if (data == node->data) {
        // Add 1 to account for height of node itself
        return height + 1;
    } else if (data < node->data) {
        return getHeightHelper(data, node->left, height + 1);
    } else {
        return getHeightHelper(data, node->right, height + 1);
    }
}

std::ostream& operator<<(std::ostream& os, const BSTree& bst) {
    if (bst.root == nullptr) {
        os << "Tree is empty" << std::endl;
    } else {
        bst.inOrderTraversal(os, bst.root);
    }
    return os;
}

void BSTree::inOrderTraversal(std::ostream& os, Node* node) const {
    if (node == nullptr) {
        return;
    }
    inOrderTraversal(os, node->left);
    os << node->data << " ";
    inOrderTraversal(os, node->right);
}

BSTree& BSTree::operator=(const BSTree& bst) {
    if (this == &bst) {
        return *this;
    }
    // Clear the current tree
    destroyHelper(root);
    // Deep copy the source tree using copyHelper
    root = copyHelper(bst.root);
    size = bst.size;
    return *this;
}

bool BSTree::operator==(const BSTree& rhs) const {
    return isEqual(root, rhs.root);
}

bool BSTree::isEqual(Node* node, Node* rhsNode) const {
    // If both trees are empty, they are equal
    if (node == nullptr && rhsNode == nullptr) {
        return true;
    }
    // If only one tree is empty, they are not equal
    if (node == nullptr || rhsNode == nullptr) {
        return false;
    }
    // If both trees are not empty, compare their contents by traversing
    if (node->data == rhsNode->data
        && isEqual(node->left, rhsNode->left)
        && isEqual(node->right, rhsNode->right)) {
        return true;
    } else {
        return false;
    }
}

bool BSTree::operator!=(const BSTree& rhs) const {
    return !(*this == rhs);
}

void BSTree::bstreeToArray(std::string arr[]) {
    int index = 0;
    bstreeToArrayHelper(root, arr, index);
}

// In-order traversal to fill array
void BSTree::bstreeToArrayHelper(Node* node, std::string arr[], int& index) {
    // Nothing to add for null nodes
    if (node == nullptr) {
        return;
    }
    bstreeToArrayHelper(node->left, arr, index);
    // Add the current node's data to the array
    arr[index++] = node->data;
    bstreeToArrayHelper(node->right, arr, index);
}

void BSTree::arrayToBSTree(std::string arr[]) {
    destroyHelper(root);
    int arraySize = 0;
    // Calculate the size of the array until null terminator or empty string
    while (arr[arraySize] != "\0" && arr[arraySize] != "") {
        arraySize++;
    }
    root = arrayToBSTreeHelper(arr, 0, arraySize - 1);
}

Node* BSTree::arrayToBSTreeHelper(std::string arr[], int start, int end) {
    // No elements to process
    if (start > end) {
        return nullptr;
    }
    // Find the middle element of the current subarray
    int mid = (start + end) / 2;
    Node* node = new Node(arr[mid]);
    // Set the middle element in the array to empty string
    arr[mid] = "";
    // Recursively build the left and right subtrees
    node->left = arrayToBSTreeHelper(arr, start, mid - 1);
    node->right = arrayToBSTreeHelper(arr, mid + 1, end);
    return node;
}

bool BSTree::isNumber(const std::string& str) const {
    // Empty string is not a number
    if (str.empty()) {
        return false;
    }
    // Check if the first character is a sign
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
        // Not a number if string is only a sign
        if (str.length() == 1) {
            return false;
        }
        start = 1;
    }
    // Check if the rest of the string are all numbers
    for (int i = start; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}