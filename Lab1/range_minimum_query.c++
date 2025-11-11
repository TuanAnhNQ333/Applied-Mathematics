#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, queries, i, j, sum = 0;
cin>>n;
    int a[n];
    int maxLog = log2(n) + 1; // so hang cuamang 2 chieu
    int b[n][maxLog];

    for (int k = 0; k < n; k++) cin>> a[k];

    // preprocessing
    for (int k = 0; k < n; k++) {
        b[k][0] = k; // khoitao hang dautien
    }
    // tinhtoancac hang con lai
    for (int h = 1; (1 << h) <= n; h++) {
        for (int k = 0; k + (1 << h) - 1 < n; k++) {
            if (a[b[k][h - 1]] < a[b[k + (1 << (h - 1))][h - 1]]) {
                b[k][h] = b[k][h - 1];
            } else {
                b[k][h] = b[k + (1 << (h - 1))][h - 1];
            }
        }
    }
	
	// processing
cin>>queries;
    while (queries--) {
cin>>i>>j;
        int range = (1 << (int)log2(j - i + 1)); // do dai moi khoang
        int column = (int)log2(j - i + 1); // toa do theo cot trenmang 2 chieu

        // tim min trongcackhoang
        int minIndex1 = b[i][column];
        int minIndex2 = b[j - range + 1][column];
        int minValue = min(a[minIndex1], a[minIndex2]);

        sum += minValue;
    }

cout<< sum <<endl;
    return 0;
}
