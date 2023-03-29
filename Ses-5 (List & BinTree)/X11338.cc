#include "BinTree.hh"
#include "ParInt.hh"
#include <iostream>
using namespace std;

void sumak(BinTree<ParInt>& a, int k) {
    if (not a.empty()) {
        BinTree <ParInt> left = a.left();
        BinTree <ParInt> right = a.right();
        sumak(left, k);
        sumak(right, k);
        ParInt p (a.value().primer(), a.value().segon() + k);
        a = BinTree <ParInt> (p, left, right);
    }
}