#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	int n = 100;
	int can = (int)sqrt(n);
	cout << can << endl;
	
	double res = sqrt(1000);
	cout << fixed << setprecision(2) << res << endl;
    return 0;
}