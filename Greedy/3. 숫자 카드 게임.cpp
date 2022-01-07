#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));

	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			v[i][j] = num;
		}
	}

	// 각 행에서 가장 작은 원소 뽑기
	vector<int> minArr;
	for (int i = 0; i < n; i++) {
		int min = 10001;
		for (int j = 0; j < m; j++) {
			if (v[i][j] < min) {
				min = v[i][j];
			}
		}
		minArr.push_back(min);
	}

	sort(minArr.begin(), minArr.end());
	cout << minArr[n - 1] << '\n'; // 그 중에서 최댓값 출력

	return 0;
}

/* 더 효율적인 풀이과정 (2차원 배열을 만들지 않고 입력을 받으면서 바로 처리)

	int main() {
		int n, m;
		cin >> n >> m;

		int result = -1;

		// 한 줄씩 입력 받아 확인하기
		for (int i = 0; i < n; i++) {
			// 현재 줄에서 '가장 작은 수' 찾기
			int min_value = 10001;
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				min_value = min(min_value, x);
			}
			// '가장 작은 수'들 중에서 가장 큰 수 찾기
			result = max(result, min_value);

			// 다음 행으로 넘어갈 때마다 result 갱신
		}

		cout << result << '\n'; // 최종 답안 출력
	}

*/