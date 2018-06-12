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

void CTricia::insert(string &ip) {
    node * newNode = makeNode(ip);
    assert(newNode->prefix != 0); //not allowed
    node * curr = root;

    recurseAndInsert(curr, newNode);

}

void CTricia::remove(string &ip) {
    return;
}

bool CTricia::contains(string &ip) {
    return 1;
}

CTricia::~CTricia() {
    CTricia::destroyTree(root);
}

CTricia::node * CTricia::makeNode(string &ip) {
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

void CTricia::recurseAndInsert(node * curr, node * n) {

    if (newNode->data[newNode->prefix] == 0) {

    }
    else {

    }



    //if here that means that up until the prefix of the current node,
    //the bits are EXACTLY the same

    //find point where they diverge and insert left or right depending on 
    //whether the diverging bit is a 0 or 1 and as long as the node
    //below has a greater prefix.
}