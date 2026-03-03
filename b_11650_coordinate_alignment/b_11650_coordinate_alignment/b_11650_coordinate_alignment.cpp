
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

    // O(N log N) (N = pts.size())
    sort(xy.begin(), xy.end());
    for (int i = 0; i < num_dot; i++) {
        std::cout << xy[i].first << " " << xy[i].second << '\n';
    }
    return 0;
}

/*
* sort함수에서 비교를 위한 comp함수
* x값이 같다면 y값을 오름차순 / x값이 다르다면 x값을 오름차순
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}
*/
