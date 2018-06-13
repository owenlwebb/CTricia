#pragma once
/*
* Header file for CTricia
*
* CTricia: A C++ Implementation of a PATRICIA trie for IP Address Operations
* Author: Owen Webb - owebb@umich.edu
*/

#include <string>
#include <bitset>
#include <sstream>
#include <cassert>
#include <stdexcept>

class CTricia {
//struct delcarations
private:
    struct node {
        std::bitset<32> data;
        int prefix;
        node * left;
        node * right;
    };

//interface
public:
    CTricia();
    void insert(std::string ip);
    void remove(std::string ip);

    // DESCRIPTION: Returns "true" if IP is covered under some prefix within
    //              the trie. Return "false" otherwise. 
    // REQUIRES: IP is a string formatted as a full IP address of the form
    //           XXX.XXX.XXX.XXX
    bool contains(std::string &ip);

    // DESCRIPTION: Destructor
    ~CTricia();

//helpers
private:
    node * makeNode(std::string &ip);
    void destroyTree(node * n);
    void insertInSubtree(node * curr, node * n, node * &below);
    int findDivergeIndex(std::bitset<32> b1, std::bitset<32> b2, int prefix);

//data
private:
    node * root = nullptr;
    size_t size = 0;
};