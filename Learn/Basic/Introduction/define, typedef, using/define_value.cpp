/*
Định nghĩa tên cho giá trị

Define được sử dụng để đặt tên cho các giá trị được sử dụng trong chương trình nhằm mục đích truyền tải ý nghĩa tốt hơn

Cú pháp :  #define tên_giá_trị giá_trị
*/
#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14
#define INF 1000000000
#define TRUE 1
#define FALSE 0
#define Tech28 "28tech.com.vn"
#define mod 1000000007

int main(){
	cout << fixed << setprecision(2) << PI << endl;
	cout << INF << endl;
	cout << TRUE << endl;
	cout << FALSE << endl;
	cout << Tech28 << endl;
	cout << mod << endl;
    return 0;
}