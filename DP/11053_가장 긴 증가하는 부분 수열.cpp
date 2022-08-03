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

		// j = 0 to (i - 1) 
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				tmp = max(tmp, dp[j]);
			}
		}
		
		dp[i] = tmp + 1; // i번째 값 갱신 
	    maxLength = max(dp[i], maxLength); // 최장 길이 갱신 
	}

	cout << maxLength; 
	
	return 0;
}