#include <iostream>
#include <vector>
#include <cstring> 
#include <algorithm> 
#include <utility>
using namespace std;

const int MAX = 100; 
int arr[MAX][MAX]; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t; 

	while(t--){ 
		int h, w, n; 
		cin >> h >> w >> n;

		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				arr[i][j] = (h - (i - 1)) * 100 + j; 
			}
		}

		int q = n / h; // 72 / 6 -> 12 
		int r = n % h; // 72 % 6 -> 0 
		if(r == 0){
			cout << arr[1][q] << endl; 
		}else {
			cout << arr[h - r + 1][q + 1] << endl;
		}

		// 배열 초기화 
		memset(arr, 0, sizeof(arr)); 
	}
	
	return 0;
}