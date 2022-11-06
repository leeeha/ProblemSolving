#include <iostream>
#include <vector>
using namespace std;

int dp[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}

	dp[0] = 1; 

	// 동전의 종류마다 최대 k번까지 경우의 수가 갱신된다.
	for(int i = 1; i <= n; i++){
		// 동전의 크기를 첫번째 동전 크기부터 k원까지 1씩 늘리면서 
		for(int j = v[i]; j <= k; j++){
			// 점화식에 따라 테이블 갱신 
			dp[j] += dp[j - v[i]]; 
		}
	}

	cout << dp[k]; 
	
	return 0;
}