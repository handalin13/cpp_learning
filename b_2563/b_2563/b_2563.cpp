#include <iostream>
using namespace std;

int main()
{
    // 백준 2563번
    // 100x100 흰 도화지를 X, Y축 격자 모델링(0=흰색, 1=검은색)
    // 검정 색종이(10x10)가 덮는 칸을 1로 마킹한 뒤 전체 1의 개수를 합산

    int num_colored_paper; // 검정 색종이 개수
    int x, y; // 격자 좌표
    int white[100][100] = { 0 }; // 흰 도화지 상태 : 0

    std::cin >> num_colored_paper;

    // 검정 색종이 10x10 영역 마킹
    // Time: O(n * 10 * 10)
    for (int n = 0; n < num_colored_paper; n++) {
        std::cin >> x >> y;

        // 지정된 (x, y)부터 가로/세로 10칸을 1로 설정
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                white[i][j] = 1; // 중복되도 1
            }
        }
    }

    // 전체 검은 영역(=1로 마킹된 칸) 합산
    // Time: O(100*100) = O(10,000) (상수)
    int black_size = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            black_size += white[i][j];
        }
    }

    std::cout << black_size << endl;

    // 총 복잡도:
    // Time: O(n*100 + 10,000) ≈ O(n) (10x10 마킹, 100x100 합산은 상수)
    // Space: O(100*100)
    return 0;
}
