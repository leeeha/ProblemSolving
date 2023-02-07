// Sol1. �̺�Ž�� 
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n;
	
	vector<int> arr; 
	for(int i = 0; i < n; i++){
		int val; 
		cin >> val; 
		arr.push_back(val); 
	}

	sort(arr.begin(), arr.end()); 

	int m; 
	cin >> m; 

	for(int i = 0; i < m; i++){
		int key;  
		cin >> key; 

		// key�� arr�� ���� ��쿡�� upper�� lower�� ��ġ�� �����ؼ� 0�� ��µȴ�. 
		int num = upper_bound(arr.begin(), arr.end(), key) - lower_bound(arr.begin(), arr.end(), key);
		cout << num << " "; 
	}

    return 0;
}

// Sol2. map 
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map> 
using namespace std;

map<int, int> m; // 0���� �ʱ�ȭ 

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; 
	cin >> N; 
	
	for(int i = 0; i < N; i++){
		int val; 
		cin >> val; 
		m[val]++; 
	}

	int M; 
	cin >> M; 

	for(int i = 0; i < M; i++){
		int key;  
		cin >> key; 

		cout << m[key] << " "; 
	}

    return 0;
}