#include <iostream>
using namespace std;

// 1 �� N �� 15 
// 0 �� r, c < 2^N 
int n, r, c;
int ans;

void Z(int y, int x, int size){
	if(y == r && x == c){
		cout << ans; 
		return; 
	}

	// (r, c)�� ���� ��и鿡 ���Ѵٸ� 
	if(r >= y && r < y + size && c >= x && c < x + size){
		// 4������� ������ 
		Z(y, x, size/2); // 1��и� Ž�� 
		Z(y, x + size/2, size/2); // 2��и� Ž��
		Z(y + size/2, x, size/2); // 3��и� Ž�� 
		Z(y + size/2, x + size/2, size/2); // 4��и� Ž�� 
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
