#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int n;
int arr[1001]; 
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		dp[i] = arr[i]; 
	}

	for(int i = 0; i < n; i++){
		// j = 0 to (i-1)
		for(int j = 0; j < i; j++){
			// �����ϴ� �κ� �������� && ���� �� Ŀ������ �˻� 
			if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]){
				// �κ� ������ �ִ� �� ���� 
				dp[i] = dp[j] + arr[i];
			}
		}
	}

	int ans = 0; 
	for(int i = 0; i < n; i++){
		ans = max(ans, dp[i]); 
	}

	cout << ans; 
	
	return 0;
}