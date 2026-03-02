#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int num_today_book; 
    string name; 
    std::cin >> num_today_book;

    // 책 제목(key), 판매횟수(value)
    // map은 key가 자동 정렬 -> 사전순 tie-break 구현하기 좋음
    map<string, int> books; // std::map<std::string, int> books;
    
    for (int i = 0; i < num_today_book; i++) {
        std::cin >> name;
        books[name]++; // O(log M)
    }
    int best_count = 0;
    string bestseller;
        // 지금까지의 최고 판매량보다 현재 책의 판매량이 크면 최고 기록 갱신, 해당 책 제목 저장
        // 동률 시 사전순 우선인 책 출력하기 위해 >=대신 >로 갱신
        if (pair.second > best_count) { 
            best_count = pair.second;
            bestseller = pair.first;
        }
    }

    /*
    for (const auto& pair : books) {
        const std::string& title = pair.first;
        const int count = pair.second;

        if (count > best_count) {
            best_count = count;
            best_title = title;
        }
    }
    */

    std::cout << bestseller << endl;
    return 0;

}