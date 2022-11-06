// 11650번. 좌표 정렬하기
// 점의 개수 N: 10만개 이하, 좌표 범위: -100,000 ≤ xi, yi ≤ 100,000

// 점 개수가 많지 않다면, Point 구조체로 x,y 좌표를 묶어서 정렬을 직접 구현할 수 있지만
// 이 문제는 점의 개수가 10만개나 되기 때문에 std::pair를 쓰자.

#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <algorithm> // std::sort
using namespace std;

int main()
{
    int n; // 점의 개수
    cin >> n;
    vector<pair<int, int>> v;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }

    // x좌표 기준으로 정렬, x좌표가 같으면 y좌표 기준으로 정렬
    sort(v.begin(), v.end());

    vector<pair<int, int>>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }

    return 0;
}
