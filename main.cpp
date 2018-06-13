/*
*
* Testing / Demonstration file for CTricia
*
* CTricia: A C++ Implementation of a PATRICIA tree for IP Address Operations
* Author: Owen Webb - owebb@umich.edu
*/

#include <iostream>
#include "ctricia.h"

using namespace std;

int main() {
    CTricia trie;
    trie.insert("192.168.0.1/24");
    trie.insert("8.8.8.8");
    trie.insert("1.1.1.1");
    trie.insert("35.0.0.0/8");
    trie.insert("192.168.0.1");
    return 0;
}
