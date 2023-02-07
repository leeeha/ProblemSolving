// Sol1. 이분탐색 
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

		// key가 arr에 없는 경우에는 upper와 lower의 위치가 동일해서 0이 출력된다. 
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

map<int, int> m; // 0으로 초기화 

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