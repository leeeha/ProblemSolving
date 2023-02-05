#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string> 
using namespace std;

vector<int> compression(const vector<int>& arr){
	vector<int> v(arr); 
	sort(v.begin(), v.end()); 
	v.erase(unique(v.begin(), v.end()), v.end()); 
	return v; 
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; // 최대 100만 

	vector<int> arr; 
	for(int i = 0; i < n; i++){
		int x; 
		cin >> x; // 최대 10억 
		arr.push_back(x); 
	}

	vector<int> pressed = compression(arr); 

	for(int i = 0; i < n; i++){
		int idx = lower_bound(pressed.begin(), pressed.end(), arr[i]) - pressed.begin(); 
		cout << idx << " "; 
	} 
	
    return 0;
}