#include <iostream>
#include <vector>

using namespace std;


void rec(vector<vector<int>> &matrix, int n, int start_x , int start_y, int i, int j, int &counter) {
    if (n == 1) return;
    if (i - start_x >= n/2 && j - start_y >= n/2) {
        counter++;
        matrix[start_x + n/2 - 1][start_y + n/2 -1] = counter;
        matrix[start_x+ n/2 - 1][start_y + n/2 ] = counter;
        matrix[start_x + n/2 ][start_y + n/2 - 1] = counter;

        rec(matrix, n/2, start_x, start_y, start_x + n/2 - 1, start_y + n/2 -1, counter);
        rec(matrix, n/2, start_x, start_y + n/2, start_x+ n/2 - 1, start_y + n/2, counter);
        rec(matrix, n/2, start_x + n/2, start_y, start_x + n/2, start_y + n/2 - 1, counter);
        rec(matrix, n/2, start_x + n/2, start_y + n/2, i, j, counter);
    }
    else if (i - start_x < n/2 && j - start_y < n/2) {
        counter++;
        matrix[start_x + n/2 - 1][start_y + n/2] = counter;
        matrix[start_x + n/2][start_y + n/2] = counter;
        matrix[start_x + n/2][start_y + n/2 - 1] = counter;

        rec(matrix, n/2, start_x + n/2, start_y, start_x + n/2 , start_y + n/2 - 1, counter);
        rec(matrix, n/2, start_x, start_y + n/2, start_x + n/2 - 1, start_y + n/2, counter);
        rec(matrix, n/2, start_x + n/2, start_y + n/2, start_x + n/2, start_y + n/2, counter);
        rec(matrix, n/2, start_x, start_y, i, j, counter);
    }
    else if(i - start_x < n/2 && j - start_y >= n/2) {
        counter++;
        matrix[start_x + n/2][start_y+ n/2] = counter;
        matrix[start_x + n/2][start_y + n/2 -1] = counter;
        matrix[start_x + n/2-1][start_y + n/2-1] = counter;

        rec(matrix, n/2, start_x, start_y, start_x + n/2 - 1, start_y + n / 2 - 1, counter);
        rec(matrix, n/2, start_x + n/2, start_y + n/2, start_x + n/2, start_y + n / 2, counter);
        rec(matrix, n/2 , start_x + n/2, start_y, start_x + n/2, start_y + n/2 -1, counter);
        rec(matrix, n/2, start_x, start_y + n/2, i, j, counter);
    }
    else {
        counter++;
        matrix[start_x + n/2][start_y+ n/2] = counter;
        matrix[start_x + n/2 - 1][start_y + n/2 - 1] = counter;
        matrix[start_x + n/2 - 1][start_y + n/2] = counter;

        rec(matrix, n/2, start_x, start_y, start_x + n/2 - 1, start_y + n / 2 - 1, counter);
        rec(matrix, n/2, start_x + n/2, start_y + n/2, start_x + n/2, start_y + n / 2, counter);
        rec(matrix, n/2 , start_x, start_y + n/2, start_x +n / 2 -1, start_y + n/2, counter);
        rec(matrix, n/2, start_x+ n/2 , start_y, i, j, counter);
    }
}

int main()
{
    int n;
    cin >> n;
    n = (1<<n);
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    matrix[x][y] = 1;
    int counter = 1;
    rec(matrix, n, 0, 0, x, y, counter);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j]-1 <<' ';
        }
        cout << endl;
    }
    return 0;
}