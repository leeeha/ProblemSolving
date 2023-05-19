#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

const int COLOR_NUM = 3; 
const int HOUSE_NUM = 1001; 
int cost[COLOR_NUM]; 
int dp[HOUSE_NUM][COLOR_NUM]; 

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	dp[0][0] = 0; 
	dp[0][1] = 0; 
	dp[0][2] = 0; 

	int n; 
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> cost[0] >> cost[1] >> cost[2];

		// i번째 집을 R, G, B로 칠할 때의 최소 비용 저장 
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
	}

	// N번째 집까지 칠했을 때, 최소 비용 출력 
	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]); 
	
	return 0;
}