#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll; 
typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K; 

	int sum = 0; 
	for(int i = 1; i <= K; i++){
		sum += i; 
	}

	N -= sum; 

	if(N < 0){
		cout << "-1\n";
	}else{
		if(N % K == 0) cout << K - 1; 
		else cout << K; 
	}
	
	return 0;
}
