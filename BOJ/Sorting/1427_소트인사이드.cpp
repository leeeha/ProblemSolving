// 1427번. 소트인사이드
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 입력: 1,000,000,000보다 작거나 같은 자연수
	string s;
	cin >> s;
	int n = s.length();

	// 내림차순 정렬
	for (int i = 0; i < n - 1; ++i) {
		int max = i;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] > s[max]) {
				max = j; // 최댓값을 갖는 인덱스를 선택해서
			}
		}
		swap(s[max], s[i]); // 외부 루프의 시작점과 스왑한다.
	}

	cout << s;

	return 0;
}