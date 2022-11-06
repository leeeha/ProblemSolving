#include <iostream>
#include <vector> 
#include <algorithm> 
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n; // 최대 10만 

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i]; // 오름차순 (각 원소는 최대 10억) 
	}

	int left = 0, right = n - 1; 
	int sum = 2e9; // 최대 20억 (0에 가장 가까운 값으로 갱신될 예정) 
	pair<int, int> p; // 합이 0에 가장 가까운 두 용액의 특성값 저장 
	
	// 양쪽에서 다가오는 투 포인터 
	while(left < right){
		int a = v[left];
		int b = v[right];
		
		if(abs(a + b) < sum){ 
			sum = abs(a + b); // 최솟값 갱신 
			p = { a, b }; // 쌍 갱신 
		}

		if(a + b < 0){ 
			left++; // 합을 늘리기 위해서  
		}else{
			right--; // 합을 줄이기 위해서 
		}
	}

	cout << p.first << " " << p.second << endl;

	return 0;
}
