#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 301; 
int dp[MAX]; 
int score[MAX];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n;

	for(int i = 1; i <= n; i++){ 
		cin >> score[i]; 
	}

	dp[1] = score[1];
	dp[2] = score[1] + score[2];

	for(int i = 3; i <= n; i++){
		dp[i] = max(dp[i - 2] + score[i], 
			        dp[i - 3] + score[i - 1] + score[i]); 
	}

	cout << dp[n];
	
	return 0;
}
