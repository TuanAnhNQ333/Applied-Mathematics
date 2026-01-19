/*
Giải thích : 

auto x khi duyệt set thì x có kiểu dữ liệu là string
auto pos = se.find("28tech") được gán giá trị trả về của hàm find nên pos có kiểu là set::iterator 
*/

#include <iostream>
#include <set>

using namespace std;

int main(){
   set<string> se = {"28tech", "c++", "python", "c++", "java"};
   cout << "Duyet set bang range-based for loop : \n";
   for(auto x : se){
      cout << x << " ";
   }
   cout << endl;
   auto pos = se.find("28tech");
   if(pos == se.end()){
      cout << "NOT FOUND";
   }
   else{
      cout << "FOUND\n";
   }
}