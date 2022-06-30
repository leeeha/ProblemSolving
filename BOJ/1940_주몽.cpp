#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; // ����� ���� (�ִ� 15,000)
	cin >> n; 

	int m; // ������ ����� �� �ʿ��� ��
	cin >> m; 

	// �� ����� ���� ��ȣ �Է� 
	vector<int> v(n); 
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	// �� ������ 
	int left = 0, right = n - 1, cnt = 0;
	while(left < right){
		if(v[left] + v[right] > m) right--;
		else if(v[left] + v[right] < m) left++;
		else { cnt++; right--; }
	}
	
	cout << cnt << endl;
	
	return 0;
}