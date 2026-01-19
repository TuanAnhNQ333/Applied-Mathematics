#include <iostream>
#include "typeinfo"

using namespace std;

int main(){
   auto p = make_pair(10, 20);
   cout << p.first << ' ' << p.second << endl;
   int n = 100;
   auto ptr1 = &n;
   cout << "ptr1 la kieu con tro : " << typeid(ptr1).name() << endl;
   auto ptr2 = &ptr1;
   cout << "ptr2 la kieu con tro cap 2 : " << typeid(ptr2).name() << endl;
   return 0;
}