#include <vector>
#include <iostream>
#include <iomanip>
#include "bst.h"
#include "standalone_funcs.h"

using namespace std;

int main() {
	BinarySearchTree B(4);
	B.insert(2);
	B.insert(5);
	B.insert(6);
	B.insert(3);
	cout << boolalpha;
	cout << checkBST(B.root) << endl;
	cout << B;
}


//int main() {
//	int n;
//	int k;
//	cin >> n >> k;
//	vector<int> a(n);
//	for (int a_i = 0;a_i < n;a_i++) {
//		cin >> a[a_i];
//	}
//	vector<int> output = array_left_rotation(a, n , k);
//	for (int i = 0; i < n;i++)
//		cout << output[i] << " ";
//	cout << endl;
//	return 0;
//}