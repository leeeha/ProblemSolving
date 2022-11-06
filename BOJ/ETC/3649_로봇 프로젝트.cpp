#include <iostream>
#include <vector> 
#include <algorithm>
#include <cmath> 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int x, n; // ���� �ʺ� (cm), ������ ����
	while(cin >> x >> n){
		vector<int> v(n); // �� ������ ���� (nm)  
		for(int i = 0; i < n ; i++){ 
			cin >> v[i]; // �ִ� 10cm (10^8 -> 1��) 
		}

		sort(v.begin(), v.end()); // �������� ���� ���� 

		// �ʺ� ������� ������ ��ȯ 
		int width = x * pow(10, 7); 
		
		int left = 0;
		int right = n - 1;
		pair<bool, pair<int, int>> ans = {false, {0, 0}}; 
		while(left < right){ 
			int temp = v[left] + v[right];
			if(temp > width) 
				right--; // �� ���̱� 
			else if(temp < width) 
				left++; // �� �ø��� 
			else {
				ans = {true, {v[left], v[right]}}; 
				break; // ���� ���� �߰ߵ� ���� ���� ���̰� �ִ���.  
			}
		}
	
		if(ans.first){ 
			pair<int, int> p = ans.second;
			cout << "yes " << p.first << " " << p.second << "\n";
		}else{
			cout << "danger\n"; 
		}
	}
	
	return 0;
}