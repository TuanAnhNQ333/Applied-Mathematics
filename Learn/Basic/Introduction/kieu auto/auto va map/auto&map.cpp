/*
Giải thích : 

auto p thì p có kiểu dữ liệu là pair 
auto it = mp.begin() thì it có kiểu dữ liệu là map::iterator 
*/
#include <iostream>
#include <map>

using namespace std;

int main(){
   map<string, string> mp;
   mp.insert({"28tech", "28tech.com.vn"});
   mp.insert({"Meta", "facebook.com"});
   mp.insert({"X", "twitter.com"});
   cout << "Duyet map bang range-based for loop : \n";
   for(auto p : mp){
      cout << p.first << ' ' << p.second << endl;
   }
   cout << "Duyet map bang iterator : \n";
   for(auto it = mp.begin(); it != mp.end(); ++it){
      cout << it->first << ' ' << it-> second << endl;
   }
}