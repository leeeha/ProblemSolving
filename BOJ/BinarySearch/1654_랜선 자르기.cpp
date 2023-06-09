#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int k, n;
const int MAX = 10001; 
ll lines[MAX];

bool decision(ll length){
	int sum = 0;
	for(int i = 0; i < k; i++){ 
		sum += lines[i] / length; 
	}
	return sum >= n; 
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> k >> n; 

	for(int i = 0; i < k; i++){
		cin >> lines[i]; 
	}

	// 결정 문제를 만족시키는 x의 최댓값을 구하자. 
	ll left = 0, right = 3e9;
	while(left <= right){
		ll mid = (left + right) / 2; 
		if(decision(mid)) left = mid + 1; 
		else right = mid - 1;
	}

	cout << right; 

	return 0;
}
