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

	// ���� ������ �Է��� �޴µ�, 
	// �ϳ��� key�� ���� value�� 2�̻��̸� �̸��� �ߺ��� ��! 
	map<string, int> map;
	vector<string> v; // �ߺ��Ǵ� �̸� ���� 

	for(int i = 0; i < n + m; i++){
		string s;
		cin >> s;
		map[s] += 1;

		if(map[s] > 1){ // �̸��� 2�� �̻� �����ϸ� 
			v.push_back(s); 
		}
	} // �ð� ���⵵: O(n + m)
	
	// ���� ������ ���� 
	sort(v.begin(), v.end());
	
	cout << v.size() << endl;
	for(auto e: v){
		cout << e << endl;
	}
	
	return 0;
}
