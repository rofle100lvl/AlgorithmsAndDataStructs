#include <iostream>
#include <vector>

using namespace std;

enum Color {
    RED,
    BLACK,
    UNDEFINED
};

bool dfs(vector<vector<int>> const& graph, vector<enum Color>& colors, int country, enum Color color) {
    if (colors[country] != UNDEFINED) {
        if (colors[country] != color) return false;
        else return true;
    }
    colors[country] = color;
    bool t = true;
    for (int i: graph[country]) {
        if (color == RED) {
            t &= dfs(graph, colors, i, BLACK);
        } else {
            t &= dfs(graph, colors,  i, RED);
        }
    }
    return t;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int a;
        while (true) {
            cin >> a;
            if (!a) break;
            edges[i].push_back(a-1);
            edges[a-1].push_back(i);
        }
    }
    vector<enum Color> colors(n, UNDEFINED);
    if (dfs(edges, colors, 0, RED)) {
        for (enum Color color: colors) {
            cout << color;
        }
    } else {
        cout << -1;
    }
    return 0;
}
