#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N_MAX = 101;
const int T_MAX = 10001;
int N, T;
int dp[N_MAX][T_MAX];
int times[N_MAX];
int scores[N_MAX];

void input(){
	cin >> N >> T;

	for(int i = 1; i <= N; i++){
		cin >> times[i] >> scores[i];
	}

	for(int i = 0; i <= T; i++){
		dp[0][i] = 0;
	}

	for(int i = 0; i <= N; i++){
		dp[i][0] = 0;
	}
}

void solution(){
	for(int i = 1; i <= N; i++){ // 1~i 단원까지 고려 
		for(int t = 1; t <= T; t++){ // 제한 시간 1~T
			int ti = times[i];
			int si = scores[i];

			// i번째 단원의 학습 시간이 제한 시간을 넘는 경우 
			if(ti > t) {
				// (i-1)번째 단원까지만 공부한다. 
				dp[i][t] = dp[i - 1][t];
			}else{
				// i번째 단원을 학습할지 말지 결정한다.
				dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - ti] + si);
			}
		}
	}

	// N개의 단원을 모두 고려하고, 시험까지 남은 시간이 T일 때
	// 얻을 수 있는 최대 점수
	cout << dp[N][T];
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
	
	return 0;
}