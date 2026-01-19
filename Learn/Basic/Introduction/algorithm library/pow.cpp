#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	int a = 2, b = 10;
    cout << a << "^" << b << " = " << (int)pow(a, b) << endl;
    //Tính căn bậc 5
    int n = 100;
    double res = pow(n, 1.0 / 5);
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}