#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, m; // n은 최대 100만, m은 최대 20억 
int tree[100'0001]; // 각 나무의 길이는 최대 10억 

// 절단기의 높이만큼 잘린 나무들의 길이 합이 
// m 이상인지 결정하는 함수 
bool decision(int height){
	long long total = 0; 

	// 절단기의 높이만큼 잘린 나무들의 길이 합을 구한다.
	for(int i = 0; i < n; i++){ 
		int gap = tree[i] - height;
		if(gap > 0){ 
			total += gap; 
		} // 0과 음수는 무시 
	}

	// 그 길이의 합이 m 이상이면 true 리턴 
	return total >= m; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 

	for(int i = 0; i < n; i++){
		cin >> tree[i]; 
	}

	int left = 0, right = 1e9; 
	while(left <= right){
		int mid = (left + right) / 2; 
		if(decision(mid)) left = mid + 1; // x의 최댓값을 구하기 위해 
		else right = mid - 1; // true 구간으로 이동하도록 
	}

	cout << right; 
		
	return 0; 
}