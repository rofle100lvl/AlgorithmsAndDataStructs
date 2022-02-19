#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> a;
    a.push(0);
    int last_pushed = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (a.top() > p) {
            cout << "Cheater";
            return 0;
        }
        if (a.top() == p) {
            a.pop();
        } else {
            for (int j = last_pushed + 1; j <= p; j++) {
                a.push(j);
                last_pushed = j;
            }
            a.pop();
        }
    }
    if (a.top() == 0) {
        cout << "Not a proof";
    }
    return 0;
}
//7
//1 6 4 5 3 2 7
//6
//4 3 5 2 6 1
// 3
// 1 2 3 4 5

