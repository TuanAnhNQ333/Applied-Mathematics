/*
Kiến thức về vector nếu bạn chưa học có thể bỏ qua phần này và khi học xong vector có thể tiếp tục tham khảo.

Thông thường để duyệt qua vector bạn có thể dùng iterator, 
tuy nhiên đôi khi việc khai báo iterator quá dài dòng nên bạn có thể thay nó bằng kiểu auto

Giải thích : 

auto x khi dùng trong range-based for loop thì x đóng vai trò là int
auto it = v.begin() thì it đóng vai trò là iterator nên khi truy xuất giá trị trong vector bạn cần giải tham chiếu
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
   vector<int> v = {1, 2, 3, 4, 5};
   cout << "Duyet vector bang range-based for loop : \n";
   for(auto x : v){
      cout << x << ' ';
   }
   cout << endl;
   cout << "Duyet vector bang iterator : \n";
   for(auto it = v.begin(); it != v.end(); ++it){
      cout << *it << ' ';
   }
   return 0;
}