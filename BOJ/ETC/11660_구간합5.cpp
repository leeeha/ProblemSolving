#include <iostream>
#define MAX 1025 // n은 최대 1024
using namespace std;

int arr[MAX][MAX]; 
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m; 
	cin >> n >> m; // m은 최대 10만 

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){ 
			cin >> arr[i][j]; 
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1] + arr[i][j];
		}
	}

	int x1, y1, x2, y2;
	int ans = 0;
	
	while(m--){
		cin >> x1 >> y1 >> x2 >> y2;

		ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
		cout << ans << "\n";
	}
	
	return 0;
}