#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll; 
typedef pair<int, int> pii; 

int L; 
set<int> s;
int n; 

void input() {
	cin >> L; 

	for(int i = 0; i < L; i++){
		int x; 
		cin >> x; 
		s.insert(x);
	}

	cin >> n; 
}

void solution() {
	int start = 0, end = 0;
	int ans = 0;
	
	// 집합 S에 속하지 않으면서, n은 포함하는 구간 체크  
	for(auto it = s.begin(); it != s.end(); it++){
		// 집합의 원소와 겹치면, 좋은 구간 만들 수 없음. 
		if(*it == n) {
			cout << "0\n";
			return;
		}
		else if(*it > n){
			end = *it - 1;
			
			// 첫번째 원소가 n보다 크면, 좋은 구간은 1부터 시작!! 
			if(it == s.begin()) start = 1;
			else start = *prev(it) + 1;
			
			break;
		}
	}

	cout << (n - start) * (end - n + 1) + (end - n);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	
	solution(); 
	
	return 0;
}