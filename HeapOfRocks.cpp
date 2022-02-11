#include <iostream>
#include <vector>

using namespace std;

//Функция перебора
int rec(vector<int> &arr) {
// Переменная счётчик для перебора битов
    int p = 1;
// Длинна массива
    int n = arr.size();
// Минимальная разница
    int min_diff = 1<<30;
// Цикл для перебора всех вариантов расположения
    while (p < 1<<n) {
        int first_heap = 0;
        int second_heap = 0;
        for (int i = 0; i < n; i++) {
            if ((p>>i) % 2) {
                first_heap += arr[i];
            }
            else {
                second_heap += arr[i];
            }
        }
        min_diff = min(min_diff, abs(first_heap - second_heap));
        p++;
    }
    return min_diff;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << rec(arr);
    return 0;
}
