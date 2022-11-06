#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int arr[100'0001]; // 최대 100만 
vector<int> v; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n; // 최대 100만 

	for(int i = 0; i < n; i++){
		cin >> arr[i]; // 최대 10억 
		
		v.push_back(arr[i]); // 좌표 압축을 위한 벡터 
	}

	sort(v.begin(), v.end());
	
	// unique 함수는 중복 원소들을 벡터의 맨 뒤로 옮기고 그 수들의 시작 위치를 반환 
	// erase 함수는 그 위치부터 마지막 원소까지 삭제  
	// 결과적으로 중복 원소 삭제! 
	v.erase(unique(v.begin(), v.end()), v.end()); 

	// 원래 배열의 원소가 새 배열의 어느 위치로 압축되었는지 출력  
	for(int i = 0; i < n; i++){
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		cout << idx << " "; 
	}

	return 0; 
}
