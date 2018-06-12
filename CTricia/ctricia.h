#pragma once
/*
* Header file for CTricia
* 
* CTricia: A C++ Implementation of a PATRICIA tree for IP Address Operations
* Author: Owen Webb - owebb@umich.edu
*/

#include <string>
#include <bitset>

class CTricia {
//struct delcarations
private:
    //node declaration
    struct node {
        std::bitset<32> data;
        int prefix;
        node * left;
        node * right;
    };

//interface
public:
    CTricia();
    node * insert(std::string &ip);
    void remove(std::string &ip);

    // DESCRIPTION: Returns "true" if IP is covered under some prefix within
    //              the trie. Return "false" otherwise. 
    // REQUIRES: IP is a string formatted as a full IP address of the form
    //           XXX.XXX.XXX.XXX
    bool contains(std::string &ip);

    // DESCRIPTION: Destructor
    ~CTricia();

//helpers
private:
    std::pair<std::bitset<32>, unsigned char> toBits(std::string &ip);
    std::string toIP(node * n);

//data
private:
    node root = { {}, -1, nullptr, nullptr };
};