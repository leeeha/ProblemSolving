#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	long long S; 
	cin >> S; 

	long long sum = 0; // 데이터 범위 잘 확인하기!!! 
	int n = 1; // 더하는 수 자체 
	int cnt = 0; // 더한 개수 
	
	while(sum < S){ 
		sum += n; 

		if(sum > S) break; 
		
		cnt++; 
		n += 1; 
	}

	cout << cnt; 
	
	return 0;
}
