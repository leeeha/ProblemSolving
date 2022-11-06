#include <iostream>
#include <vector> 
#include <algorithm>
#include <cmath> 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int x, n; // 구멍 너비 (cm), 조각의 개수
	while(cin >> x >> n){
		vector<int> v(n); // 각 조각의 길이 (nm)  
		for(int i = 0; i < n ; i++){ 
			cin >> v[i]; // 최대 10cm (10^8 -> 1억) 
		}

		sort(v.begin(), v.end()); // 오름차순 정렬 먼저 

		// 너비를 나노미터 단위로 변환 
		int width = x * pow(10, 7); 
		
		int left = 0;
		int right = n - 1;
		pair<bool, pair<int, int>> ans = {false, {0, 0}}; 
		while(left < right){ 
			int temp = v[left] + v[right];
			if(temp > width) 
				right--; // 합 줄이기 
			else if(temp < width) 
				left++; // 합 늘리기 
			else {
				ans = {true, {v[left], v[right]}}; 
				break; // 가장 먼저 발견된 쌍이 값의 차이가 최대임.  
			}
		}
	
		if(ans.first){ 
			pair<int, int> p = ans.second;
			cout << "yes " << p.first << " " << p.second << "\n";
		}else{
			cout << "danger\n"; 
		}
	}
	
	return 0;
}