#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001]; 
int dp[1001]; 
int maxLength = 0; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
	
	for (int i = 0; i < n; i++) {
		int tmp = 0;

		// i보다 앞쪽에 있으면서  
		for (int j = 0; j < i; j++) {
			// i번째 값보다 작은 원소들 중에 
			if (arr[j] < arr[i]) {
				// dp 값이 가장 큰 값을 저장 
				tmp = max(tmp, dp[j]);
			}
		}
		
		dp[i] = tmp + 1; // 거기에 1을 더해서 i번째 dp값 갱신 
	    maxLength = max(dp[i], maxLength); // dp 테이블의 최댓값이 답!  
	}

	cout << maxLength; 
	
	return 0;
}