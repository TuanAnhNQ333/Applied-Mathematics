#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    // Bước 1: Làm cho 2 chuỗi cùng độ dài bằng cách thêm '0' ở đầu
    if (a.size() < b.size()) a.insert(0, b.size() - a.size(), '0');
    else if (b.size() < a.size()) b.insert(0, a.size() - b.size(), '0');

    string result = "";
    int carry = 0;  // nhớ khi cộng

    // Bước 2: Duyệt từ cuối chuỗi về đầu
    for (int i = a.size() - 1; i >= 0; i--) {
        int digitA = a[i] - '0';
        int digitB = b[i] - '0';

        int sum = digitA + digitB + carry;
        carry = sum / 10;              // phần nhớ
        int digit = sum % 10;          // chữ số kết quả
        result = char(digit + '0') + result;  // ghép vào đầu chuỗi kết quả
    }

    // Bước 3: Nếu còn nhớ thì thêm vào đầu
    if (carry > 0) result = char(carry + '0') + result;

    cout << result << endl;
    return 0;
}
