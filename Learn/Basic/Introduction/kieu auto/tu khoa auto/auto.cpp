/*
Giải thích : 

Ở đây mình sử dụng toán tử typeid() để có thể lấy về kiểu dữ liệu cho biến

Biến x được gán giá trị 30 nên có kiểu là integer (i)
Biến y được gán giá trị 30.5f nên có kiểu là float (f)
Biến z được gán giá trị '@' nên có kiểu là char(c)
Biến t được gán giá trị 1000000000000000 nên có kiểu là long long (x)
Biến p được gán giá trị là một pair(10, 20) nên có kiểu là pair (St4pairIiiE)
Biến l được gán giá trị là 30.5d nên có kiểu là double (d) 
Chú ý : Bạn không thể khai báo biến có kiểu auto mà không khởi tạo giá trị cho nó 

Thông thường mình chỉ dùng auto để thay cho các kiểu dữ liệu dài dòng như :
pair, iterator, con trỏ... Nếu bạn chưa biết kiến thức về iterator và con trỏ thì có thể tạm thời bỏ qua ví dụ này nhé.*/
#include <iostream>
#include "typeinfo"

using namespace std;

int main(){
   auto x = 100;
   auto y = 30.5f;
   auto z = '@';
   auto t = 1000000000000000;
   auto p = make_pair(10, 20);
   auto l = 30.5;
   cout << "Kieu du lieu cua x : " << typeid(x).name() << endl;
   cout << "Kieu du lieu cua y : " << typeid(y).name() << endl;
   cout << "Kieu du lieu cua z : " << typeid(z).name() << endl;
   cout << "Kieu du lieu cua t : " << typeid(t).name() << endl;
   cout << "Kieu du lieu cua p : " << typeid(p).name() << endl;
   cout << "Kieu du lieu cua l : " << typeid(l).name() << endl;
   return 0;
}