#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


int n;

void init (int nn, vector<int> &t)
{
    n = nn;
    t.assign (n, 0);
}

int sum (int r, vector<int> &t)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int delta, vector<int> &t)
{
    for (; i < n; i = (i | (i+1)))
        t[i] += delta;
}

int sum (int l, int r, vector<int> &t)
{
    return sum (r,t) - sum (l-1,t);
}

void find_position(int &position, int k, int N, vector<int>&t) {


}

int main() {
    unsigned int N, K;
    cin >> N >> K;
    vector<int>soliders(N);
    vector<int> tree;
    init(N, tree);
    for (int i = 0; i < N; i++) soliders[i] = i + 1;
    int position = -1;
    int count = 0;
    while (count < N ) {
        int old_position = position;
        position = (position + K) % soliders.size();
        while(true) {
            int plus_position = 0;
            if (old_position > position && old_position >= 0) {
                plus_position += sum(old_position + 1, N-1, tree) + sum(0, position, tree);
            } else if (old_position < position && old_position >= 0) {
                plus_position += sum(old_position + 1, position, tree);
            } else if (old_position == position) {
                plus_position += sum(0, N-1, tree);
            }
            old_position = position;
            position += plus_position;
            position %= N;
            if (plus_position == 0) break;
        }
        cout << soliders[position] << ' ';
        inc(position, 1, tree);
        count++;
    }
}

// 3
// 1 2 3 4 5