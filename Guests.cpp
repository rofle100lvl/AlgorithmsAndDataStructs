#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    vector<unsigned long long>x(n);
    vector<unsigned long long>y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    unsigned long long sum = 0;
    for (unsigned long long i = 1; i < n; i++) {
        sum += 2 * ((x[i] - x[i-1]) + (y[i] - y[i-1])) * i * (n - i);
    }
    cout << sum/(n*(n-1));
}