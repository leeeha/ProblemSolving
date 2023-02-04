#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string> 
using namespace std;
typedef pair<int, string> pis; 

// ���̼����� ����
bool compare(pis a, pis b){
	return a.first < b.first; 
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; 

	vector<pis> v; 
	for(int i = 0; i < n; i++){ 
		int age; 
		string name; 
		cin >> age >> name;
		v.push_back({age, name});
	}

    // ���̰� ������ �Էµ� ������� ����Ѵ�. 
	stable_sort(v.begin(), v.end(), compare); 

	for(auto e: v){
		cout << e.first << " " << e.second << "\n"; 
	}
	
    return 0;
}