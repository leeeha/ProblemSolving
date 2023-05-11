#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n;

	vector<int> v; 
	for(int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		v.push_back(x); 
	}

	if(next_permutation(v.begin(), v.end())){
		for(int i = 0; i < n; i++){
			cout << v[i] << " ";
		}
		cout << endl; 
	}else{
		cout << "-1\n";
	}
	
	return 0;
}