#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, k, b; // n�� �ִ� 10��
	cin >> n >> k >> b;

	vector<int> broken(b + 1);
	for(int i = 1; i <= b; i++){
		cin >> broken[i]; // ���峭 ��ȣ���� ��ȣ 
	}

	vector<pair<int, bool>> v(n + 1);
	for(int i = 1; i <= n; i++){
		v[i].first = i; // ��ȣ�� ��ȣ �ʱ�ȭ 

		// ���� ��ȣ���� ���峭 ������ üũ! 
		// i�� broken[j]�� ���Ե� ���ڶ�� true 
		for(int j = 1; j <= b; j++){ 
			if(i == broken[j]){ 
				v[i].second = true; // ����
			}
		} 
		// �� ���� i�� ���� false 
	}
	
	int fixCount = 0; // �����ؾ� �� ��ȣ���� ���� ī���� 
	int ans = 1e9; 
	for(int i = 1; i <= n - k + 1; i++){
		// ���ӵ� k���� ��ȣ� ���ؼ�
		// true�� ���� ī����! 
		for(int j = i; j < i + k; j++){ 
			if(v[j].second == true){ 
				fixCount++; 
			}
		}

		ans = min(ans, fixCount); // �ּڰ� ���� 
		fixCount = 0; // �� ���� ������ ���� ����� ���� �ʱ�ȭ �ʼ�!!
	}
	
	cout << ans << endl;
	
	return 0;
}

