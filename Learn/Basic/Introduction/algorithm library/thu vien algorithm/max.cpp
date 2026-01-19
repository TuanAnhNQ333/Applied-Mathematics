#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int a = 100, b = 200;
	cout << "Max(" << a << ", " << b << ") = " << max(a, b) << endl;
	cout << "Max(10, 20, 15, 4) = " << max({10, 20, 15, 4}) << endl;
	cout << "Max('d', 'b', 'z',) = " << max({'d', 'b', 'z'}) << endl;
    return 0;
}