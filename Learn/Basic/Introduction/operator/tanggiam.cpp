/*
++a : Tăng trước
a++ : Tăng sau
--a : Giảm trước
a-- : Giảm sau 

Sự khác nhau giữa n++ và ++n, tương tư như n-- và --n

n++ : Giá trị của n sẽ được sử dụng, sau đó n mới được tăng lên 1 đơn vị

++n : Giá trị của n sẽ được tăng lên luôn, sau đó sử dụng giá trị mới của n
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n = 100;
    ++n; // n = 101
    cout << n << endl;
    n++; // n = 102
    cout << n << endl;
    n--; // n = 101
    cout << n << endl;
    --n; // 100
    cout << n << endl;
	return 0;
}