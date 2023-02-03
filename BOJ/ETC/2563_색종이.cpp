#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
using namespace std;

int m = 100; 
vector<vector<bool>> check(m + 1, vector<bool>(m + 1)); 

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// ������ ���� 
	int n; 
	cin >> n; 

	int count = 0; 
	
	while(n--){
		int c, r; 
		cin >> c >> r; 

		for(int i = m - r; i > m - r - 10; i--){ // ���� �پ��� 
			for(int j = c; j < c + 10; j++){ // ���� �þ�� 
				if(!check[i][j]) { 
					check[i][j] = true; 
					count++; 
				}
			}
		}
	}

	cout << count; 
	
    return 0;
}