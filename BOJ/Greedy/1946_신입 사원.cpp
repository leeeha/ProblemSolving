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
		cin >> n; // �ִ� 10�� 
		
		vector<pair<int, int>> v; 
		for(int i = 0; i < n; i++){
			int a, b; 
			cin >> a >> b; 
			v.push_back({a, b}); 
		}
		
		sort(v.begin(), v.end());

		int cnt = 1; // ù��° ��� ä�� (���� 1��)
		int interviewRank = v[0].second; // ù��° ����� ���� ��� 
		
		for(int i = 1; i < n; i++){
			if(v[i].second < interviewRank){ // ���� ��� �� 
				cnt++; // ä�� Ȯ�� 
				interviewRank = v[i].second; // �� ���� ������ ������Ʈ 
			}
		}
		
		cout << cnt << endl; 
	}
	
	return 0; 
}