#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int arr[3] = {300, 60, 10}; 

int main() {
	int t; 
	cin >> t; 

	int cnt[3]{};
	for(int i = 0; i < 3; i++){
		cnt[i] = t / arr[i];
		t %= arr[i];
	}

	if(t != 0) {
		cout << "-1\n";
		return 0; 
	}

	for(int i = 0; i < 3; i++)
		cout << cnt[i] << " ";
	cout << endl; 
	
	return 0; 
}