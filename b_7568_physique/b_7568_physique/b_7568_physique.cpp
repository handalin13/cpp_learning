#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int people;
    int weight[50], height[50];
    int count[50]; // 자신보다 덩치 큰 사람 수 + 1

    cin >> people;

    for (int i = 0; i < people; i++) {
        cin >> weight[i] >> height[i];
        count[i] = 1;
    }
    // 시간복잡도: O(N^2)
    for (int i = 0; i < people; i++) {
        for (int j = 0; j < people; j++) {
            if (weight[i] < weight[j] && height[i] < height[j]) {
                count[i]++;
            }
        }
    }

    for (int i = 0; i < people; i++) {
        cout << count[i] << " ";
        // cout << rank_cnt[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
