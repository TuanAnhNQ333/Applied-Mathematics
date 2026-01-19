
/*
Cú pháp : [Biểu thức so sánh] ? [Giá trị trả về 1] : [Giá trị trả về 2]; 

Ý nghĩa : Phần thứ nhất trong toán tử này sẽ có giá trị đúng hoặc sai, nếu phần này có giá trị đúng thì biểu thức sẽ trả về giá trị 1, ngược lại nếu phần này có giá trị sai thì biểu thức sẽ trả về giá trị 2

Ví dụ : int n = 10 < 20 ? 100 : 200; thì n sẽ có giá trị là 100, vì 10 < 20 có giá trị là đúng nên n được gán giá trị là 100 thay vì 200
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n = 10 < 20 ? 28 : 82;
    cout << n << endl;
    n = (50 < 50) && (10 > 3) ? 28 : 82;
    cout << n << endl;
	return 0;
}