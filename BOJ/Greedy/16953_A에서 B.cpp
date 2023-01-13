#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>
using namespace std; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B; // 최대 1억 
	int ans = -1; 
	queue<pair<long long, int>> q; // 데이터 타입 주의 

	cin >> A >> B; 
	q.push({A, 1}); // 연산할 숫자, 연산한 횟수 

	while(!q.empty()){
		long long num = q.front().first; 
		int count = q.front().second; 
		q.pop(); 

		if(num == B){ 
			ans = count; 
			break; 
		}

		if(num * 2 <= B) 
			q.push({num * 2, count + 1});

		if(num * 10 + 1 <= B)
			q.push({num * 10 + 1, count + 1});
	}

	cout << ans; 
	
	return 0; 
}