#include <iostream> 
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m; // 최대 10만 
	cin >> n >> m; 

	// 최악의 경우 1000을 10만번 더하므로, 누적 합의 타입은 long형으로 선언 
	vector<long> psum(n+1); 
	psum[0] = 0; 
	for(int i = 1; i <= n; i++){ 
		int val; 
		cin >> val; 
		psum[i] = psum[i - 1] + val; // 누적 합 
	}
	
	while(m--){ 
		int i, j; 
		cin >> i >> j;
		
		// i에서 j까지의 구간 합 구하기 
		cout << psum[j] - psum[i - 1] << "\n"; 
	}
	
	return 0;
}
