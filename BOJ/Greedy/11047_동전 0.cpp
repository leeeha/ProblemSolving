#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v; 
	for (int i = 0; i < n; i++) {
    	int coin;
		cin >> coin;
		v.push_back(coin); // 오름차순으로 입력 
	}

	int cnt = 0; // 필요한 최소 동전의 개수 
    
    // 큰 화폐 단위부터 그리디하게 (탐욕적으로) 선택한다. 
	for (int i = n - 1; i >= 0; i--) {  
		cnt += k / v[i];
		k %= v[i];
	}

	cout << cnt << "\n";

	return 0;
}