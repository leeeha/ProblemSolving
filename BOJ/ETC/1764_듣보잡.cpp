#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map> 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;

	// 전부 맵으로 입력을 받는데, 
	// 하나의 key에 대한 value가 2이상이면 이름이 중복된 것! 
	map<string, int> map;
	vector<string> v; // 중복되는 이름 저장 

	for(int i = 0; i < n + m; i++){
		string s;
		cin >> s;
		map[s] += 1;

		if(map[s] > 1){ // 이름이 2번 이상 등장하면 
			v.push_back(s); 
		}
	} // 시간 복잡도: O(n + m)
	
	// 사전 순으로 정렬 
	sort(v.begin(), v.end());
	
	cout << v.size() << endl;
	for(auto e: v){
		cout << e << endl;
	}
	
	return 0;
}
