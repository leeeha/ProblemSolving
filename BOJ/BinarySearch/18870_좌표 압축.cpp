#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int arr[100'0001]; // �ִ� 100�� 
vector<int> v; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n; // �ִ� 100�� 

	for(int i = 0; i < n; i++){
		cin >> arr[i]; // �ִ� 10�� 
		
		v.push_back(arr[i]); // ��ǥ ������ ���� ���� 
	}

	sort(v.begin(), v.end());
	
	// unique �Լ��� �ߺ� ���ҵ��� ������ �� �ڷ� �ű�� �� ������ ���� ��ġ�� ��ȯ 
	// erase �Լ��� �� ��ġ���� ������ ���ұ��� ����  
	// ��������� �ߺ� ���� ����! 
	v.erase(unique(v.begin(), v.end()), v.end()); 

	// ���� �迭�� ���Ұ� �� �迭�� ��� ��ġ�� ����Ǿ����� ���  
	for(int i = 0; i < n; i++){
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		cout << idx << " "; 
	}

	return 0; 
}
