/** 
 * 최장 공통 부분 수열 
 * */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

const int MAX = 1001;
int dp[MAX][MAX]; 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b; 
	cin >> a >> b;

	// 인덱스 조정을 위해 문자열 앞에 공백 추가 
	a = " " + a; 
	b = " " + b; 

	int row = b.size(); 
	int col = a.size(); 

	for(int i = 1; i < row; i++){
		for(int j = 1; j < col; j++){
			if(a[j] == b[i]) dp[i][j] = dp[i - 1][j - 1] + 1; 
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string lcs = "";
	int n = b.size() - 1; 
	int m = a.size() - 1;

	while(dp[n][m] != 0){
		if(dp[n][m] == dp[n - 1][m]){
			n--; 
		}
		else if(dp[n][m] == dp[n][m - 1]){
			m--; 
		}
		else {
			lcs += a[m]; 
			n--; 
			m--; 
		}
	}

	cout << dp[row - 1][col - 1] << "\n";

	if(lcs.size() > 0){
		reverse(lcs.begin(), lcs.end());
		cout << lcs; 
	}
}