#include <iostream>
using namespace std;

// Tính diện tích hình chữ nhật lớn nhất trong histogram
int largestRectangleHistogram(vector<int>& h) {
    int m = h.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= m; ++i) {
        int height = (i == m ? 0 : h[i]);
        while (!st.empty() && height < h[st.top()]) {
            int top = st.top();
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h[top] * width);
        }
        st.push(i);
    }

    return maxArea;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];

    vector<int> h(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            h[j] = (A[i][j] == 0 ? 0 : h[j] + 1);

        maxArea = max(maxArea, largestRectangleHistogram(h));
    }

    cout << maxArea << "\n";
    return 0;
}
