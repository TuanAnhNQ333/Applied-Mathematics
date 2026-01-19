#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//true && true = true
    bool res1 = (10 < 20) && (20 >= 20);
    //true && true && false = false
    bool res2 = (10 < 20) && (20 == 20) && (5 > 10);
    //false || false || true = true
    bool res3 = (10 > 20) || (20 < 10) || (5 == 5);
    // !(true) = false
    bool res4 = !(10 < 20);
    //!(true && true) = !(true) = false
    bool res5 = !((20 < 30) && (30 > 10));
    cout << res1 << " " << res2 << " " << res3 << " " << res4 << " " << res5 << endl;
	return 0;
}