#include <iostream>
#include <vector>
using namespace std;

// �� �Ÿ��� ����� �ִ��� 10���̹Ƿ�, �� ���� ���� total ������ 8����Ʈ ũ��� �����ؾ� �Ѵٴ� �� ���صǴµ�
// ���� d�� c, ���� min���� �� long long�̾�� ����ɱ�??
// ������ �׸��� ������µ�, ������ �ڵ� �ۼ��ϴ� �� ���� �ʾҴ�. �׸��� ������ �� ���� Ǯ����߰ڴ�!!!

int main()
{	
	int n; // ���� ���� (�ִ� 10��)
	cin >> n;
	
	int tmp;
	vector<long long> d; // ������ ���� ���� �Ÿ� (�ִ� 10��)
	for(int i = 0; i < n - 1; i++){ // n-1��
		cin >> tmp;
		d.push_back(tmp);
	}
	
	vector<long long> c; // �� �������� ���ʹ� ���� (�ִ� 10��)
	for(int i = 0; i < n; i++){ // n��
		cin >> tmp;
		c.push_back(tmp);
	}

	long long min = c[0];
	long long total = c[0] * d[0]; // ù��° ���������� ���� �ʼ� 

	// ������ �� ������ ���ʹ� ������ ���ϰ�,
	// ������ �� ���� ������ ���� ���� ������ �� �ֵ���!
	for(int i = 1; i < n-1; i++){ // c[n-1]�� ũ�� �˻�X 
		if(min > c[i]){
			min = c[i];
			total += min * d[i];
		}else{
			total += min * d[i];
		}
	}

	cout << total << endl;
	
	return 0;
}