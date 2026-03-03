# BOJ 1302 - 베스트셀러

## Idea
- 책 제목을 key로, 판매 횟수를 value으로 판매 횟수를 센다.
- 동률(최대 판매 횟수가 같은 경우)일 때는 사전순으로 앞선 제목을 출력한다.
- `map`은 key가 사전순으로 자동으로 정렬/순회하므로
  `count > best_count`일 때만 갱신하면 동률일 때는 사전순으로 우선인 책이 유지된다.

## Complexity
- Time: O(N log M)  
  - N: 입력 개수, M: 서로 다른 책 제목 수
  - `map` 삽입/갱신이 log M
- Space: O(M)

## How to Test
Example 1:
Input:
5
top
top
top
top
kimtop

Output:
top

Example 2 (tie case):
Input:
6
a
a
a
b
b
b

Output:
a

## Pitfalls
- 동률 처리: `>=`로 갱신하면 사전순 규칙이 깨질 수 있음
  - `map` 순회 + `>` 비교로만 갱신해야 사전순 최소 유지 가능

## Implementation Notes
- I/O 성능: 입력이 커질 수 있으므로 `std::ios::sync_with_stdio(false);`와 `std::cin.tie(nullptr);`로 표준 입출력 동기화를 끄고 flush를 줄였다.
- `map` 사용하는 이유?
  - `map`은 key 정렬이 보장되어 순회 시 사전순(tie-break) 규칙을 만족시킨다.
- `for (const auto& kv : books)` 의미:
  - `auto`: 타입 추론(여기서는 `std::pair<const std::string, int>`)
  - `&`: 원소를 복사하지 않고 참조(불필요한 복사 방지)
  - `const`: 순회 중 원소를 수정하는 상황 방지(실수 방지)
  - `.first`는 key(책 제목), `.second`는 value(판매 횟수)