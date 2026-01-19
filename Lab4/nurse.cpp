#include<iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, K1, K2;
    cin>> n >> K1 >>K2;

    // Khởitạomảng f
    vector<vector<long long>>f(n + 1, vector<long long>(2, 0));

    // Cơsở
    f[0][0] = 1; // 1 cáchđểkhônglàmgìtrong 0 ngày
    f[0][1] = 1; // Khôngcócáchnàođểlàmviệctrong 0 ngày

    for (int i = 1; i<= n; ++i) {
        // Tính f[i][0]: ngàynghỉ
        f[i][0] = f[i - 1][1];

        // Tính f[i][1]: ngàykếtthúccủamộtđợtlàmviệc
        for (int j = K1; j <= K2; ++j) {
            if (i - j >= 0) {
                f[i][1] = (f[i][1] + f[i - j][0]) % MOD;
            }
        }
    }

    // Kếtquảlàtổngsốcáchlậplịchcho N ngày
    long long result = (f[n][0] + f[n][1]) % MOD;

    cout<< result <<endl;
    return 0;
}
