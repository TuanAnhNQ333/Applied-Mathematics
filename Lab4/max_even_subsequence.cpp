#include <iostream>
using namespace std;

int main() {
ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long sum = 0;
    long long maxEven = LLONG_MIN;
    long long minEven = 0;
    long long maxOdd = LLONG_MIN;
    long long minOdd = LLONG_MAX;
    bool hasEven = false;

    for(int i = 0; i< n; i++) {
        int x;
        cin>>x;
        sum += x;

        if(sum % 2 == 0) {
        maxEven = max(maxEven, sum - minEven);
        minEven = min(minEven, sum);
        hasEven = true;
        } else {
            if(minOdd != LLONG_MAX) {
                maxEven = max(maxEven, sum - minOdd);
            }
            if(maxOdd != LLONG_MIN) {
                maxEven = max(maxEven, sum - maxOdd);
            }
        maxOdd = max(maxOdd, sum);
        minOdd = min(minOdd, sum);
        }
    }

    if(!hasEven&&maxEven == LLONG_MIN) {
        cout<< "NOT_FOUND\n";
    } else {
        cout<<maxEven<< "\n";
    }

    return 0;
}
