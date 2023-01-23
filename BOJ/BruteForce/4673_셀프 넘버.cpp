#include <iostream>
#define MAX 10001
using namespace std;

bool excluded[MAX];

int d(int num){
	int sum = num; // �ڱ� �ڽ��� ������ �ʱ�ȭ 

	// ��� �ڸ� �� ���ϱ� 
	while (num != 0) {
		sum += (num % 10); // ���� �ڸ��� ���ϱ� 
		num /= 10; // ���� �ڸ��� ���ֱ� 
	}
	
	return sum;
}

int main()
{
	for(int i = 1; i < MAX; i++){
        // i�� �����ڷ� �Ͽ� ������� ���ڴ� ���� �ѹ����� ���ܽ�Ų��. 
		int sum = d(i);
		if(sum < MAX) {
			excluded[sum] = true; 
		}
	}

	for(int i = 1; i < MAX; i++){
		if(!excluded[i])
			cout << i << "\n";
	}
	
	return 0; 
}