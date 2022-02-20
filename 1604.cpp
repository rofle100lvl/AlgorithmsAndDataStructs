#include <iostream>
#include <set>

using namespace std;

int main()
{
    int k;
    cin >> k;
    set<pair<int,int>> speeds;
    for (int i = 0; i < k; i++){
        int a;
        cin >> a;
        speeds.insert(make_pair(a, i));
    }
    while(speeds.size() >= 2) {
        pair<int, int> max_speed = *speeds.rbegin();
        pair<int, int> second_max_speed = *(++speeds.rbegin());
        cout << max_speed.second + 1 << ' ';
        speeds.erase(max_speed);
        max_speed.first -= 1;
        if (max_speed.first != 0) speeds.insert(max_speed);


        cout << second_max_speed.second + 1 << ' ';
        speeds.erase(second_max_speed);
        second_max_speed.first -= 1;
        if (second_max_speed.first != 0) speeds.insert(second_max_speed);
    }

     while(speeds.begin()->first) {
         pair<int, int> max_speed = *speeds.begin();
         cout << max_speed.second + 1 << ' ';
         speeds.erase(max_speed);
         max_speed.first -= 1;
         speeds.insert(max_speed);
     }
    return 0;
}