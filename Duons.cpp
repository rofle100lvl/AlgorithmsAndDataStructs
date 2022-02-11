#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    char name;
    int count;
    Point(char name, int count) {
        this->name = name;
        this->count = count;
    }
};

enum Imposobility {
    POSSIBLE,
    IMPOSSIBLE
};

string print_and_diff_between_neighbours(Point& first_point, Point& second_point) {
    string commands;
    while (first_point.count > 0 && second_point.count > 0) {
        commands.push_back(first_point.name);
        commands.push_back(second_point.name);
        commands += "-\n";
        first_point.count -= 1;
        second_point.count -= 1;
    }
    return commands;
}

string print_and_diff_between_diagonal(Point& first_point, Point& second_point) {
    string commands;
    if (first_point.name > second_point.name) swap(first_point, second_point);
    string create_between;
    if (first_point.name == 'A' && second_point.name == 'G')
        create_between = "BF";
    else if (first_point.name == 'B' && second_point.name == 'H') create_between = "FE";
    else if (first_point.name == 'C' && second_point.name == 'E') create_between = "DH";
    else if (first_point.name == 'D' && second_point.name == 'F') create_between = "CG";
    while (first_point.count > 0 || second_point.count > 0) {
        commands += create_between + "+\n";
        commands.push_back(first_point.name);
        commands.push_back(create_between[0]);
        commands += "-\n";
        commands.push_back(second_point.name);
        commands.push_back(create_between[1]);
        commands += "-\n";
        first_point.count -= 1;
        second_point.count -= 1;
    }
    return commands;

}

vector<Point> find_none_zero_points(const vector<Point>& points) {
    vector<Point> zero_points;
    for(Point point: points) {
        if (point.count > 0) zero_points.push_back(point);
    }
    return zero_points;
}

bool is_one_plain(Point first_point, Point second_point) {
    if (first_point.name > second_point.name) swap(first_point, second_point);
    if (first_point.name == 'A' && second_point.name == 'G')
        return false;
    else if (first_point.name == 'B' && second_point.name == 'H') return false;
    else if (first_point.name == 'C' && second_point.name == 'E') return false;
    else if (first_point.name == 'D' && second_point.name == 'F') return false;
    else return true;
}

int main()
{
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;

    string ans ="";

    Point A('A', a);
    Point B('B', b);
    Point C('C', c);
    Point D('D', d);
    Point E('E', e);
    Point F('F', f);
    Point G('G', g);
    Point H('H', h);

    ans += print_and_diff_between_neighbours(A, B);
    ans += print_and_diff_between_neighbours(A, D);
    ans += print_and_diff_between_neighbours(A, E);

    ans += print_and_diff_between_neighbours(B, F);
    ans += print_and_diff_between_neighbours(B, C);

    ans += print_and_diff_between_neighbours(C, G);
    ans += print_and_diff_between_neighbours(C, D);

    ans += print_and_diff_between_neighbours(D, H);

    ans += print_and_diff_between_neighbours(E, F);
    ans += print_and_diff_between_neighbours(E, H);

    ans += print_and_diff_between_neighbours(F, G);

    ans += print_and_diff_between_neighbours(H, G);

    vector<Point> zero_points = find_none_zero_points(vector<Point>{A, B, C, D, E, F, G, H});

    enum Imposobility imposobility;
    if (zero_points.size() == 1) {
        imposobility = IMPOSSIBLE;
    } else if (zero_points.size() == 2) {
        if (is_one_plain(zero_points[0], zero_points[1])) imposobility = IMPOSSIBLE;
        else if (zero_points[0].count != zero_points[1].count) imposobility = IMPOSSIBLE;
        else {
            ans += print_and_diff_between_diagonal(zero_points[0], zero_points[1]);
            imposobility = POSSIBLE;
        }
    } else if(zero_points.size() == 0) {
        imposobility = POSSIBLE;
    }

    if (imposobility == IMPOSSIBLE) cout<< "IMPOSSIBLE";
    else {
        if (!ans.empty()) ans.pop_back();
        cout << ans;
    }
    return 0;
}
