#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int mod = n % k;
        int div = n/k;
        cout << (mod * (div + 1) * (n - div - 1) + (k - mod) * (div) * (n - div))/2 << endl;
    }
    return 0;
}
