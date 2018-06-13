/*
* Implementation file for CTricia
*
* CTricia: A C++ Implementation of a PATRICIA Trie for IP Address Operations
* Author: Owen Webb - owebb@umich.edu
*/

#include "ctricia.h"

using namespace std;

CTricia::CTricia() {
    string rootIP = "0.0.0.0/0";
    root = makeNode(rootIP);
}

void CTricia::insert(const string ip) {
    node * newNode = makeNode(ip);

    if (newNode->prefix == 0)
        throw invalid_argument("prefix \"0\" not allowed!");

    //go left or right
    if (newNode->data[0] == 0)
        insertInSubtree(root, newNode, root->left);
    else
        insertInSubtree(root, newNode, root->right);
}

void CTricia::remove(const string ip) {
    return;
}

bool CTricia::contains(const string &ip) {
    return 1;
}

CTricia::~CTricia() {
    CTricia::destroyTree(root);
}

CTricia::node * CTricia::makeNode(const string &ip) {
    node * newNode = new node;

    //1, 2, or 0 digit prefix
    if (ip[ip.length() - 2] == '/') {
        newNode->prefix = stoi(ip.substr(ip.length() - 1));
    }
    else if (ip[ip.length() - 3] == '/') {
        newNode->prefix = stoi(ip.substr(ip.length() - 2));
    }
    else {
        newNode->prefix = 32;
    }

    //convert octets to bits
    stringstream ss(ip);
    string octetStr = "";
    int octetInt = 0;
    bitset<32> bits;

    for (int i = 0; i < 4; ++i) {
        getline(ss, octetStr, '.');
        octetInt = stoi(octetStr);

        bits |= (octetInt << (24 - (8 * i)));
    }

    newNode->data = bits;
    newNode->left = newNode->right = nullptr;

    return newNode;
}

void CTricia::destroyTree(node * n) {
    if (n == nullptr) return;

    destroyTree(n->left);
    destroyTree(n->right);

    delete n;
}

void CTricia::insertInSubtree(node * curr, node * newNode, node * &below) {
    assert(!(curr->prefix > newNode->prefix)); //bad
    int div;

    //below doesn't exist
    if (below == nullptr) {
        below = newNode;
        return;
    }
    //below is less specific
    else if (below->prefix < newNode->prefix) {
        div = findDivergeIndex(below->data, newNode->data, below->prefix);

        //below prefixed bits are same. Go deeper
        if (div == below->prefix) {
            if (newNode->data[below->prefix] == 0)
                insertInSubtree(below, newNode, below->left);
            else
                insertInSubtree(below, newNode, below->right);
        }
    }
    //below is more specific
    else if (below->prefix > newNode->prefix) {
        div = findDivergeIndex(below->data, newNode->data, newNode->prefix);

        //below prefixed bits are same. Insert here
        if (div == below->prefix) {
            if (below->data[newNode->prefix] == 0) {
                newNode->left = below;
                newNode->right = nullptr;
            }
            else {
                newNode->left = nullptr;
                newNode->right = below;
            }
            below = newNode;
            return;
        }
    }
    //already exists
    else {
        return;
    }

    //prefixes diverge. Combine below and newNode under a shared parent
    node * sharedParent = new node;
    sharedParent->prefix = div;
    sharedParent->data = newNode->data;

    if (newNode->data[div] == 0) {
        sharedParent->left = newNode;
        sharedParent->right = below;
    }
    else {
        sharedParent->right = newNode;
        sharedParent->left = below;
    }

    below = sharedParent;
}

int CTricia::findDivergeIndex(const std::bitset<32> &b1, const std::bitset<32> &b2, const int prefix) {
    for (int i = 0; i < prefix; ++i) {
        if (b1[i] != b2[i])
            return i;
    }

    return prefix;
}
