/**
입력값의 범위에 비해 입력 개수가 턱없이 작을 때, 메모리 초과를 방지하는 좌표 압축! 
압축된 배열에서 이분 탐색 이용하여 원본 배열의 원소 위치 찾을 수 있음.
*/
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

const int MAX = 10000001; 
vector<int> arr(MAX); 

// 좌표 압축 
vector<int> compression(const vector<int>& arr){
	vector<int> v = arr;
	sort(v.begin(), v.end()); // 오름차순 정렬 
	v.erase(unique(v.begin(), v.end()), v.end()); // 중복 원소 제거 
	return v; 
}

int main()
{
	// arr에 입력값을 주었다고 가정하자.
	
	vector<int> pressed = compression(arr); 

	// 압축된 새 배열에서 특정 값의 인덱스 찾기 (이진 탐색)
	int search = 123123; 
	int index = lower_bound(pressed.begin(), pressed.end(), search) - pressed.begin();

	return 0;
}