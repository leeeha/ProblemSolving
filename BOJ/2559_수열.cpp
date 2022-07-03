#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, k;
	cin >> n >> k; // 최대 10만 (k는 윈도우 크기) 

	vector<int> v(n); 
	for(int i = 0; i < n; i++){ 
		cin >> v[i]; // -100 이상 100 이하 
	}

	// 연속적인 k일 동안의 온도의 합 중에서 최댓값 출력 
	int start = 0, sum = 0;
	int ans = -1e9; // 더해서 음수일 수도 있으니까 초기값 유의하기!!!! 
	for(int right = 0; right < n; right++){ 
		sum += v[right]; // 오른쪽에 추가 
		if(right >= k - 1){ 
			ans = max(ans, sum); 
			sum -= v[start++]; // 왼쪽 슬라이딩  
		} 
	}

	cout << ans;
	
	return 0;
}