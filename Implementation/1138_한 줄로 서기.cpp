#include <iostream>
using namespace std;

int n;
int arr[11]; // 0으로 초기화

int main()
{
	cin >> n;

	// 키가 작은 순서대로
	for(int i = 0; i < n; i++){
		int left;
		cin >> left; // 자기보다 키 큰 사람이 왼쪽에 몇명 있는지 입력 받기 

		// 한 줄을 순회하면서 
		for(int j = 0; j < n; j++){
			// 자기보다 키 큰 사람들을 다 지나쳤고, 자기 자리가 마련되어 있다면
			if(left == 0 && arr[j] == 0){
				arr[j] = i + 1; // j의 위치에 착석 (자신의 키 저장)
				break;
			}
			// 자기보다 키 큰 사람이 있다면 빈자리를 지나친다. (j++)
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