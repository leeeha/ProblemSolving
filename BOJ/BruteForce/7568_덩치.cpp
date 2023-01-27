#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <utility>
using namespace std;

const int MAX = 50;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; 

	int rank = 1; 
	pair<int, int> arr[MAX];

	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second; 
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// 몸무게와 키가 자신보다 더 큰 사람을 발견하면 
			if(arr[i].first < arr[j].first && arr[i].second < arr[j].second){
				// 순위가 밀린다. 
				rank++; 
			}
		}

		cout << rank << " "; 
		rank = 1; 
	}
	
	return 0;
}