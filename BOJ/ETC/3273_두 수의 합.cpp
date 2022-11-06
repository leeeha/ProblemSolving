#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n; // 10�� 

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i]; // 100�� 
	}

	sort(v.begin(), v.end()); // �������� ���� 

	int x;
	cin >> x; // 200�� 

	// ai + aj = x�� ������Ű�� ���� ���� 
	int cnt = 0;
	int left = 0, right = n - 1;
	while(left < right){
		if(v[left] + v[right] > x) right--;
		else if(v[left] + v[right] < x) left++;
		else { cnt++; right--; }
	}

	cout << cnt << "\n";
	
	return 0;
}