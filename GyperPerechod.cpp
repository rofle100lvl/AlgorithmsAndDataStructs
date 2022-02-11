#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<int> sums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        sums[i] = sum;
    }
    int max_sum = 0;
    int min_element = 0;
    for (int i = 0; i < n; i++) {
        max_sum = max(max_sum, sums[i] - min_element);
        if (sums[i] < min_element) min_element = sums[i];
    }
    cout << max_sum;

    return 0;
}
