#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	int n; 
	cin >> n;

	vector<int> v;
	for(int i = 0; i < n; i++){
		int input; 
		cin >> input; 
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	vector<int> temp;
	for(int i = 0; i < n; i++){
		int x = v[i] * (n - i); 
		temp.push_back(x);
	}

	int max = *max_element(temp.begin(), temp.end());
	cout << max; 
	
	return 0; 
}