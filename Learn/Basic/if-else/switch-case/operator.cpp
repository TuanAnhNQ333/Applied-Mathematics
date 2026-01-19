#include <iostream>

using namespace std;

int main(){
    int a = 20, b = 5;
    char op;
    cin >> op;
    switch(op){
        case '+':
           	cout << a + b << endl;;
            break;
        case '-':
            cout << a - b << endl;;
            break;
        case '*':
            cout << a * b << endl;;
            break;
        case '/':
            cout << a / b << endl;;
            break;
        default:
            cout << "INVALID INPUT" << endl;
    }
}