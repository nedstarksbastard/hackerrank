#include "standalone_funcs.h"


vector<int> array_left_rotation(vector<int> a, int n, int k) {
	std::rotate(a.begin(), a.begin() + k, a.end());
	return a;
}


