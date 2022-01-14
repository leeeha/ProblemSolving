/* 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; // 볼링공의 개수 n, 공의 최대 무게 m

	int x;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end()); // 오름차순 정렬

	// 서로 다른 n개에서 2개를 선택하는 경우의 수
	int result = n * (n - 1) / 2;

	// 볼링공이 각각 몇개씩 중복되는지 카운트
	vector<int> arr;
	int cnt = 1;

	for (int i = 0; i < n - 1; i++) {
		if (v[i] == v[i + 1]) {
			cnt++;

			// 배열의 끝에서 발생한 중복값은 따로 처리해주기
			if (i == n - 2 && cnt > 1) {
				arr.push_back(cnt);
			}
		}
		else { // 중복된 값이 나오다가 다른 값이 나오면
			if (cnt > 1) {
				arr.push_back(cnt);
				cnt = 1; // 개수 초기화
			}
		}
	}

	// 선택된 두 개의 볼링공이 같은 무게인 경우 제외
	for (int i = 0; i < arr.size(); i++) {
		result -= arr[i] * (arr[i] - 1) / 2;
	}

	cout << result << '\n';

	return 0;
}
*/

#include<iostream>
using namespace std;

// 1부터 10까지의 무게를 담을 수 있는 배열
int arr[11];

int main() {
	int n, m;
	cin >> n >> m; // 볼링공의 개수 n, 공의 최대 무게 m

	// 각 무게에 해당하는 볼링공의 개수 카운트
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	int result = 0;
	for (int i = 1; i <= m; i++) { // 무게 1~m까지에 대해서
		// A가 선택할 수 있는, 무게가 i인 볼링공의 개수는 arr[i]
		// B가 선택할 수 있는 경우의 수는 n -= arr[i]
		n -= arr[i];
		result += arr[i] * n;
	}

	// 두 사람이 서로 다른 무게의 볼링공을 선택하는 경우의 수 출력
	cout << result << "\n";

	return 0;
}