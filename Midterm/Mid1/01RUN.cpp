/*
Huyền đang có một dãy số nguyên a = a1, a2, . . . , an. Cô muốn cắt a thành các đoạn con gồm các phần tử liên
tiếp của a, sao cho mỗi đoạn đều là một dãy tăng. Hãy giúp Huyền tính xem cô phải cắt a thành ít nhất bao nhiêu
đoạn để thỏa mãn tính chất trên.
Dữ liệu vào
• Dòng đầu chứa số nguyên dương n (1 ≤n ≤105)
• Dòng tiếp theo chứa n số nguyên dương a1 a2 . . . an (0 ≤ai ≤109)
Kết quả
Ví dụ
Ghi một số nguyên duy nhất là số ít nhất các đoạn con tăng của a.
test 
6
3 6 1 7 8 2
answer 3
Giải thích
Dãy a được cắt thành (3,6), (1,7,8), (2)*/
#include<iostream>
using namespace std;
const int MAX = 100005;
int n;
int a[MAX];
int res;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}
void solve(){
    int fi = a[0];
    int cnt = 0;
    for(int i=1; i<n; i++){
        if(a[i] < a[i-1]) cnt++;
    }
    res = cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    cout << res + 1;
    return 0;
}
