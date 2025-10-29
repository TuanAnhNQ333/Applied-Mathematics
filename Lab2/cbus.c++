/*
• Tìm đường đi ngắn nhất cho 1 xe bus phục vụ khách hàng
• Có 𝑛 khách hàng. Khách 𝑖 cần đi từ điểm 𝑖 đến điểm 𝑖 + 𝑛
Phương tiện: một xe bus với 𝑘 chỗ ngồi
• Input: 𝑛, 𝑘 và ma trận khoảng cách 𝑐[1. . 2𝑛][1. . 2𝑛]
• Output: độ dài đường đi ngắn nhất tìm được
Example
stdin 3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
stdout
25
• Ý tưởng: Quay lui và nhánh cận, giống với TSP
• Dùng 1 mảng x[1..2n] – hoán vị của 1,…,2n thể hiện hành trình xe bus
• Biến phụ trợ:
• Mảng đánh dấu: appear[1..2n]
appear[v] = v đã xuất hiện trong hành trình chưa.
• load: hiện tại có bao nhiêu khách trên xe
• Programming:
• Try(k): chọn giá trị cho x[k]
• Branch and bound: cũng giống TSP
*/


#include <iostream> 

using namespace std;

const int MAX_N = 11;
int n, K, load = 0, f = 0, f_best = INT_MAX, Cmin = INT_MAX;
vector<vector<int>> c(2 * MAX_N + 1, vector<int> (2 * MAX_N + 1));
vector<int> X(2 * MAX_N + 1);
vector<bool> visited(2 * MAX_N + 1);

bool check(int v) {
    if (visited[v]) return false; 
    if (v > n && !visited[v - n]) return false; 
    if (v <= n && load + 1 > K) return false;
    return true;
}

void tryRoute(int k) {
    for (int v = 1; v <= 2 * n; ++v) {
        if (check(v)) {
            X[k] = v;  
            f += c[X[k - 1]][v]; 
            visited[v] = true;

            if (v <= n) {
                load += 1;
            } else {
                load -= 1;
            }

            if (k == 2 * n && f + c[X[2 * n]][0] < f_best) {
                f_best = f + c[X[2 * n]][0];
            } else {
                if (f + Cmin * (2 * n + 1 - k) < f_best) {
                    tryRoute(k + 1);
                }
            }
            if (v <= n) {
                load -= 1;
            } else {
                load += 1;
            }
            f -= c[X[k - 1]][X[k]]; 
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n >> K;
    c.assign(2 * n + 1, vector<int> (2 * n + 1));
    X.resize(2 * n + 1);
    visited.resize(2 * n + 1);
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            cin >> c[i][j];
            if (i != j) {
                Cmin = min(Cmin, c[i][j]); 
            }
        }
    }
    X[0] = 0;
    visited[0] = true;

    tryRoute(1);

    cout << f_best << endl;

    return 0;
}
