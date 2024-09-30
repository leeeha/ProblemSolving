#include <iostream>
#include <algorithm>
using namespace std;

// 순차 탐색
int LinearSearch(int n, int* arr, int key){
	for(int i = 0; i < n; i++){
		if(arr[i] == key)
			return i;
	}
	return -1; // not found
}

// 이진 탐색 
int BinarySearch(int n, int* arr, int key){
	int low = 0, high = n - 1, mid;

	while(low <= high){
		mid = (low + high) / 2;

		if(key == arr[mid]) return mid;
		else if(key < arr[mid]) high = mid - 1;
		else low = mid + 1; 
	}

	return -1; // not found
}

int main(){
	int arr[10] = {0, 4, 9, 2, 1, 8, 6, 7, 5, 3};

	// 순차 탐색
	int a = LinearSearch(10, arr, 9);
	cout << a << "\n"; // 2

	// 이진 탐색은 정렬된 배열에서만 사용할 수 있다.
	sort(arr, arr + 10); 

	// 이진 탐색
	int b = BinarySearch(10, arr, 7);
	cout << b << "\n"; // 7

	return 0;
}
