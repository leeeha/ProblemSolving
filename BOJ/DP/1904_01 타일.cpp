#include <iostream>
#include <vector> 
#include <algorithm>
#define MAX 1000001 
using namespace std; 

long long d[MAX] = {0, 1, 2}; 
int n; 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

	for(int i = 3; i <= n; i++){ 
		d[i] = (d[i - 2] + d[i - 1]) % 15746; 
	}
	
	cout << d[n]; 
	
	return 0; 
}