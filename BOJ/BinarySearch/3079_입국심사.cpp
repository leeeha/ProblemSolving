#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll; // 최대 2^63 - 1 (10^18 보다 크다) 

ll n, m; // n은 최대 10^5, m은 최대 10^9 
const int MAX = 100001; 
ll times[MAX]; // 각 시간은 최대 10^9 

bool decision(ll x){ 
	ll cnt = 0; 

	for(int i = 0; i < n; i++){
		cnt += x / times[i]; 
		if(cnt > m) break; // 이걸 안 해주면 오답 처리된다. 
	}

	return cnt >= m; 
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m; 

	for(int i = 0; i < n; i++){
		cin >> times[i]; 
	}

	sort(times, times + n);

	ll left = 1, right = times[n - 1] * m;
	
	while(left <= right){
		ll mid = (left + right) / 2;
		
		// 결정 문제를 만족시키는 x의 최솟값을 구하자. 
		if(decision(mid)) right = mid - 1; 
		else left = mid + 1;
	}

	cout << left;

	return 0;
}
