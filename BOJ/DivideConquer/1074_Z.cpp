#include <iostream>
using namespace std;

// 1 ≤ N ≤ 15 
// 0 ≤ r, c < 2^N 
int n, r, c;
int ans;

void Z(int y, int x, int size){
	if(y == r && x == c){
		cout << ans; 
		return; 
	}

	// (r, c)가 현재 사분면에 속한다면 
	if(r >= y && r < y + size && c >= x && c < x + size){
		// 4등분으로 나눠서 
		Z(y, x, size/2); // 1사분면 탐색 
		Z(y, x + size/2, size/2); // 2사분면 탐색
		Z(y + size/2, x, size/2); // 3사분면 탐색 
		Z(y + size/2, x + size/2, size/2); // 4사분면 탐색 
	}else{
		ans += size * size; 
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> r >> c;

	Z(0, 0, (1 << n)); // size = 2^n 
	
	return 0;
}
