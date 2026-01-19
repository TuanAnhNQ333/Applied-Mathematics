#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int a = 100, b = 200;
	cout << "Min(" << a << ", " << b << ") = " << min(a, b) << endl;
	cout << "Min(10, 20, 15, 4) = " << min({10, 20, 15, 4}) << endl;
	cout << "Min('d', 'b', 'z',) = " << min({'d', 'b', 'z'}) << endl;
    return 0;
}