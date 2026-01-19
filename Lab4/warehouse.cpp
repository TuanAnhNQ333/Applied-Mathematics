/**/
#include <iostream>
using namespace std;

const int MAXN = 1000;
const int MAXT = 100;
const int MOD = 1e9 + 7;

int main() {
    int N, T, D;
    cin>> N >> T >>D;

    vector<int> a(N), t(N);
    for (int i = 0; i< N; ++i) cin>> a[i];
    for (int i = 0; i< N; ++i) cin>> t[i];

    // DP table to track max goods collected
    vector<vector<int>>dp(N, vector<int>(T + 1, 0));

    // Initialize starting DP values
    for (int i = 0; i< N; ++i) {
        if (t[i] <= T) dp[i][t[i]] = a[i];
    }

    int max_goods = 0;

    // DP transitions
    for (int i = 0; i< N; ++i) {
        for (int j = 0; j <= T; ++j) {
            if (dp[i][j] == 0) continue;

            // Transition from station i to i + d (1 <= d <= D)
            for (int d = 1; d <= D; ++d) {
                int next_station = i + d;
                if (next_station>= N) break;

                int next_time = j + t[next_station];
                if (next_time<= T) {
                    dp[next_station][next_time] = max(dp[next_station][next_time], dp[i][j] + a[next_station]);
                    max_goods = max(max_goods, dp[next_station][next_time]);
                }
            }
        }
    }

    cout<<max_goods<<endl;
    return 0;
}




