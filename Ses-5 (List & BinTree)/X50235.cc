// X50235	PODA DE SUBARBRES D'UN BINTREE D'ENTERS

#include "BinTree.hh"

bool poda_subarbre(BinTree<int> &a, int x) 
{
	bool found;
	if (a.empty()) {
		return false;
	}
	else if (a.value() == x) {
		a = BinTree<int> ();
		return true;
	}
	else {
		BinTree<int> l = a.left();
		BinTree<int> r = a.right();
		
		found = poda_subarbre(l, x);

		if (not found) {
			found = poda_subarbre(r, x);
		}
		if (found) {
			a = BinTree<int>(a.value(), l, r);
		}
	}
	return found;
}