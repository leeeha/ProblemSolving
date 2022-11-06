#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> arr;
vector<int> dp; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// 처음 3개는 0으로 초기화 
	for(int i = 0; i < 3; i++){
		arr.push_back(0);
		dp.push_back(0);
	}

	// 각 포도주의 양 저장 
	for(int i = 0; i < n; i++){
		int val; 
		cin >> val;
		arr.push_back(val); 
	}

	// 인덱스 3부터 시작 
	for(int i = 3; i < arr.size(); i++){ 
		// i번째 잔을 마셨을 때 
		// (i-1)번째 잔을 마신 경우와 안 마신 경우 중에 최댓값 구하기 
		int temp = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);

		// i번째 잔을 마신 경우와 안 마신 경우 중에 최댓값 구해서 저장하기  
		dp.push_back(max(temp, dp[i-1]));
	}

	// 마지막 원소까지 모두 탐색했을 때, 마실 수 있는 최대 양 출력 
	cout << dp[arr.size() - 1]; 
	
	return 0;
}