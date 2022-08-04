#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int n;
int arr[100'0001]; 
int dp[100'0001]; 
int maxLength = 0; 
vector<int> L; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 

		if(L.size() == 0) 
			L.push_back(arr[i]);
		else{
			int last = L.size() - 1;
			if(L[last] < arr[i]){
				L.push_back(arr[i]);
			}else{
				// arr[i] 이상의 값이 처음 나오는 위치 반환 
				auto iter = lower_bound(L.begin(), L.end(), arr[i]);
				*iter = arr[i]; // 그 위치를 arr[i]로 대체 
			}
		}
	}

	cout << L.size(); 
	
	return 0;
}