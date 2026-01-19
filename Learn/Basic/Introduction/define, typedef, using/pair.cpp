#include <iostream>
#include <iomanip>
using namespace std;

typedef char kitu;
typedef pair<int, int> ii;

int main(){
	kitu x = '@';
	cout << x << endl;
	ii p = {100, 200};
	cout << p.first << ' ' << p.second << endl;
    return 0;
}