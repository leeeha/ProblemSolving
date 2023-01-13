#include <iostream>
using namespace std; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i = 1; 
	while(true){
		int L, P, V; 
		cin >> L >> P >> V; 
		
		if(L == 0 && P == 0 && V == 0) break; 

		int ans = L * (V / P) + min(V % P, L);
		cout << "Case " << i << ": " << ans << endl; 
		i++; 
	}
	
	return 0; 
}