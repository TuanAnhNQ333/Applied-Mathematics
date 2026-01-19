/*
Define có 3 chức năng chính : 

Định nghĩa tên cho kiểu dữ liệu
Định nghĩa tên cho giá trị
Định nghĩa tên cho cấu trúc hoặc câu lệnh
Định nghĩa tên cho kiểu dữ liệu 

Define có thể sử dụng để làm công việc tương tự như typedef đó là định nghĩa tên mới cho kiểu dữ liệu

Cú pháp : #define tên_mới kiểu_dữ_liệu
*/
#include <iostream>
#include <iomanip>
using namespace std;

#define songuyen int
#define ll long long
#define sothuc double
#define dungsai bool
#define ii pair<int, int>

int main(){
	songuyen a = 1000;
	ll b = 2828282828282;
	sothuc c = 3.1239;
	dungsai check = true;
	ii p = {100, 200};
	cout << a << " " << b << endl;
	cout << fixed << setprecision(2) << c << endl;
	cout << boolalpha << check << endl;
	cout << p.first << " " << p.second << endl;
    return 0;
}