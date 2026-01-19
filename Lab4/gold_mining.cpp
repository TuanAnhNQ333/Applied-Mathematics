#include <iostream>
using namespace std;

int main() {
    int n, L1, L2;
    cin>> n >> L1 >>L2;
    vector<int> a(n), dp(n);

    for (int i = 0; i< n; ++i) cin >> a[i];

    // Khởitạo deque đểlưutrữcácchỉsốcủadp
    deque<int>dq;
    long long max_gold = 0;

    for (int i = 0; i< n; ++i) {
        // Xóacácphầntửkhôngcầnthiếttrong deque
        while (!dq.empty() &&dp[dq.back()] <= dp[i - L1]) {
            dq.pop_back();
        }
        // Thêmchỉsốcủadp[i - L1] vào deque
        if (i - L1 >= 0) {
            dq.push_back(i - L1);
        }

        // Xóaphầntửđầutiêntrong deque nếunórangoàikhoảng [i - L2]
        while (!dq.empty() &&dq.front() <i - L2) {
            dq.pop_front();
        }

        // Tính giá trịdp[i]
        if (!dq.empty()) {
            dp[i] = dp[dq.front()] + a[i];
        } else {
            dp[i] = a[i]; // Nếukhôngcóphầntử nào trong deque
        }

        max_gold = ((max_gold>dp[i]) ?max_gold : dp[i]);
    }

    cout<<max_gold<<endl;
    return 0;
}

