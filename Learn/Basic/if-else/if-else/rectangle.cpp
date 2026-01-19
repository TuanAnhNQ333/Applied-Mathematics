/*Bài 2. Nhập 3 cạnh của tam giác là số nguyên, nếu 3 cạnh của tam giác đều in 1, cân in 2, vuông in 3, thường in 4. Giả sử 3 cạnh đã là 3 cạnh của tam giác hợp lệ
*/

#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c){
        cout << 1 << endl;
    }
    else if((a == b) || (b == c) || (a == c)){
        cout << 2 << endl;
    }
    else if((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b)){
        cout << 3 << endl;
    }
    else{
        cout << 4 << endl;
    }
}