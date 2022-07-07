#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n; // �ִ� 600 

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i]; // �ִ� 1�� 
	}

	// ������ ũ�� ������ �������� ���� 
	sort(v.begin(), v.end());

	int answer = 1e9; // �� ������� Ű ���� �� �ּڰ� ���ϱ� 
	for(int i = 0; i < n - 3; i++){
		for(int j = i + 3; j < n; j++){ // i�� �ּ� 3ĭ ���̳����� 
			// i�� j ������ �����̸� ����Ű�� �� ������
			int left = i + 1;
			int right = j - 1;
			
			while(left < right){
				int anna = v[i] + v[j]; 
				int elsa = v[left] + v[right]; 
				int diff = elsa - anna; 
				
				answer = min(answer, abs(diff));

				// ���簡 �ȳ����� �� ũ�ٸ� ���� ���̱� ���� �������� �̵�
				if(diff > 0) right--; 
				// ���簡 �ȳ����� �� �۴ٸ� ���� �ø��� ���� ���������� �̵� 
				else left++;
			}
		}
	}

	cout << answer << endl;
	
	return 0;
}

