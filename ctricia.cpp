/*
* Implementation file for CTricia
*
* CTricia: A C++ Implementation of a PATRICIA Trie for IP Address Operations
* Author: Owen Webb - owebb@umich.edu
*/

#include "ctricia.h"

using namespace std;

CTricia::CTricia() {

}

CTricia::node * CTricia::insert(string &ip) {
    return nullptr;
}

void CTricia::remove(string &ip) {
    return;
}

bool CTricia::contains(string &ip) {
    return 1;
}

CTricia::~CTricia() {

}

pair<bitset<32>, int> CTricia::toBits(string &ip) {
    return {};
}

string CTricia::toIP(CTricia::node * n) {
    return {};
}
