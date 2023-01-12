#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n; 
		cin >> n; // 최대 10만 
		
		vector<pair<int, int>> v; 
		for(int i = 0; i < n; i++){
			int a, b; 
			cin >> a >> b; 
			v.push_back({a, b}); 
		}
		
		sort(v.begin(), v.end());

		int cnt = 1; // 첫번째 사원 채용 (서류 1등)
		int interviewRank = v[0].second; // 첫번째 사원의 면접 결과 
		
		for(int i = 1; i < n; i++){
			if(v[i].second < interviewRank){ // 면접 결과 비교 
				cnt++; // 채용 확정 
				interviewRank = v[i].second; // 더 높은 순위로 업데이트 
			}
		}
		
		cout << cnt << endl; 
	}
	
	return 0; 
}