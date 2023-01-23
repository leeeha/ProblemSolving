#include <iostream>
#define MAX 10001
using namespace std;

bool excluded[MAX];

int d(int num){
	int sum = num; // 자기 자신의 값으로 초기화 

	// 모든 자리 수 더하기 
	while (num != 0) {
		sum += (num % 10); // 일의 자리수 더하기 
		num /= 10; // 일의 자리수 없애기 
	}
	
	return sum;
}

int main()
{
	for(int i = 1; i < MAX; i++){
        // i를 생성자로 하여 만들어진 숫자는 셀프 넘버에서 제외시킨다. 
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