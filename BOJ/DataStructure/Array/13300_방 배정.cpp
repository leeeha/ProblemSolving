#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[7][2];

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, k; 
	cin >> n >> k; 

	for(int i = 0; i < n; i++){
		int a, b; // 성별, 학년  
		cin >> a >> b; 
		arr[b][a] += 1; 
	}

	int sum = 0;
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j < 2; j++){
			sum += arr[i][j] / k;
			if(arr[i][j] % k != 0){
				sum++; 
			}
		}
	}

	cout << sum; 
	
    return 0;
}
