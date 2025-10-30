/*
Đếm số nghiệm nguyên dương của một phương trình
• Input: 2 số nguyên dương 𝑛, 𝑀
𝑛 số nguyên dương 𝑎1, 𝑎2, … , 𝑎𝑛.
• Output: Số nghiệm nguyên dương của một phương trình
𝑎1𝑋1 + 𝑎2𝑋2 + . . . + 𝑎𝑛𝑋𝑛 = 𝑀
*/

#include <iostream>
using namespace std;

int n, m, a[1000];

int countSolutions(int currentSum, int index) {
    // Nếu đã xét hết n biến
    if (index == n) {
        return (currentSum == m); // chỉ hợp lệ khi tổng đúng M
    }

    int totalWays = 0;

    // Vì Xi > 0
    for (int x = 1; currentSum + a[index] * x <= m; x++) {
        totalWays += countSolutions(currentSum + a[index] * x, index + 1);
    }

    return totalWays;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = countSolutions(0, 0);
    cout << result << endl;

    return 0;
}
