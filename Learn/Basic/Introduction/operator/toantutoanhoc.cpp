#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double R;
	cout << "Nhap ban kinh : ";
	cin >> R;
	double chuvi = 2 * 3.14 * R;
	double dientich = 3.14 * R * R;
	cout << "Chu vi : " << fixed << setprecision(2) << chuvi << endl;
	cout << "Dien tich : " << fixed << setprecision(2) << dientich << endl;
	return 0;
}