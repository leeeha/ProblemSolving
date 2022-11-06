#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, k, b; // n은 최대 10만
	cin >> n >> k >> b;

	vector<int> broken(b + 1);
	for(int i = 1; i <= b; i++){
		cin >> broken[i]; // 고장난 신호등의 번호 
	}

	vector<pair<int, bool>> v(n + 1);
	for(int i = 1; i <= n; i++){
		v[i].first = i; // 신호등 번호 초기화 

		// 현재 신호등이 고장난 것인지 체크! 
		// i가 broken[j]에 포함된 숫자라면 true 
		for(int j = 1; j <= b; j++){ 
			if(i == broken[j]){ 
				v[i].second = true; // 고장
			}
		} 
		// 그 외의 i는 전부 false 
	}
	
	int fixCount = 0; // 수리해야 할 신호등의 개수 카운팅 
	int ans = 1e9; 
	for(int i = 1; i <= n - k + 1; i++){
		// 연속된 k개의 신호등에 대해서
		// true의 개수 카운팅! 
		for(int j = i; j < i + k; j++){ 
			if(v[j].second == true){ 
				fixCount++; 
			}
		}

		ans = min(ans, fixCount); // 최솟값 갱신 
		fixCount = 0; // 그 다음 구간에 대한 계산을 위해 초기화 필수!!
	}
	
	cout << ans << endl;
	
	return 0;
}

