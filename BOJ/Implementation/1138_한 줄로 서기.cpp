#include <iostream>
using namespace std;

int n;
int arr[11]; // 0���� �ʱ�ȭ

int main()
{
	cin >> n;

	// Ű�� ���� �������
	for(int i = 0; i < n; i++){
		int left;
		cin >> left; // �ڱ⺸�� Ű ū ����� ���ʿ� ��� �ִ��� �Է� �ޱ� 

		// �� ���� ��ȸ�ϸ鼭 
		for(int j = 0; j < n; j++){
			// �ڱ⺸�� Ű ū ������� �� �����ư�, �ڱ� �ڸ��� ���õǾ� �ִٸ�
			if(left == 0 && arr[j] == 0){
				arr[j] = i + 1; // j�� ��ġ�� ���� (�ڽ��� Ű ����)
				break;
			}
			// �ڱ⺸�� Ű ū ����� �ִٸ� ���ڸ��� ����ģ��. (j++)
			else if(arr[j] == 0){ 
				left--;
			}
		}
	}

	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}