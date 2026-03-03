#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_dot;
    int x, y;
    vector<pair<int, int>> xy;
    std::cin >> num_dot;

    for (int i = 0; i < num_dot; i++) {
        std::cin >> x >> y;
        xy.push_back({ x,y });

    }

    sort(xy.begin(), xy.end()); // O(N log N)
    for (int i = 0; i < num_dot; i++) {
        std::cout << xy[i].first << " " << xy[i].second << '\n';
    }
    return 0;
}

/*
bool comp(const std::pair<int,int>& a, const std::pair<int,int>& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
*/