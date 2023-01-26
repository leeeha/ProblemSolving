#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; 
	cin >> n >> m; 

	vector<int> v; 
	for(int i = 0; i < n; i++){ // ÃÖ´ë 100
		int x; 
		cin >> x; 
		v.push_back(x); 
	}

	int max = 0; 
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				int sum = v[i] + v[j] + v[k];
				if(sum <= m && sum > max){
					max = sum; 
				}
			}
		}
	}

	cout << max; 
	
	return 0; 
}