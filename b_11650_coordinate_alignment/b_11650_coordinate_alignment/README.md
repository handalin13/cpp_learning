# BOJ 11650 - 좌표 정렬하기

## Idea
- 점 `(x, y)`들을 x 오름차순, x가 같으면 y 오름차순으로 정렬
- `std::pair<int,int>`의 기본 비교는 사전식(lexicographical)
  - 먼저 `first(x)`를 비교
  - 같으면 `second(y)`를 비교
- 따라서 `vector<pair<int,int>>`에 저장한 뒤 `std::sort(xy.begin(), xy.end())`만 호출하면 정렬 규칙 만족

## Complexity
- Time: O(N log N)
  - N: 점 개수
  - `std::sort`가 평균/최악 기준으로 `N log N` (좌표 비교는 O(1))
- Space: O(N)
  - 좌표 저장용 벡터

## How to Test
Example 1:
Input:
5
3 4
1 1
1 -1
2 2
3 3

Output:
1 -1
1 1
2 2
3 3
3 4

## Pitfalls
- 정렬 규칙 착각: y 먼저 정렬하거나 내림차순으로 하지 않도록 주의
- 많은 출력이므로 `std::endl` 대신 `'\n'` 사용(불필요한 flush 방지).

## Implementation Notes
- I/O 최적화:
  - `ios::sync_with_stdio(false); cin.tie(nullptr);`
- `pair` 기본 정렬을 쓰는 이유:
  - 문제 요구사항이 정확히 “(x, y) 사전식 오름차순”
  - 코드 길이 감소 + comparator 버그 방지.
  - std::vector<std::pair<int, int>> pts;
  - 오름차순 :  std::sort(pts.begin(), pts.end());