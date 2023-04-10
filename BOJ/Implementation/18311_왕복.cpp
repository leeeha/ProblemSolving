// https://www.acmicpc.net/problem/18311

#include <iostream>
#include <vector> 
using namespace std; 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long k; 
	cin >> n >> k; 

	vector<int> v; 
	for(int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		v.push_back(x); 
	}

	bool finished = false; 
	for(int i = 0; i < n; i++){
		k -= v[i];
		if(k < 0){
			cout << i + 1; 
			finished = true; 
			break; 
		}
	}

	if(!finished){
		for(int i = n - 1; i >= 0; i--){
			k -= v[i]; 
			if(k < 0){ 
				cout << i + 1;
				break; 
			}
		}
	}
	
	return 0; 
}