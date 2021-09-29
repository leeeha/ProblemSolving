#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
	// 문자열의 길이가 같으면 사전 순으로 정렬
	if (a.length() == b.length())
		return a < b; // a가 b보다 사전 순으로 앞에 오면 true

	// 기본적으로는 문자열 길이 순으로 정렬
	return a.length() < b.length(); // a가 b보다 짧으면 true
}

int main()
{
	// 단어의 개수 입력 받기
	int n;
	cin >> n;

	// n개의 문자열로 이루어진 배열
	string* arr = new string[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 사용자 정의 함수로 정렬하기
	sort(arr, arr + n, compare);

	cout << arr[0] << "\n";
	for (int i = 1; i < n; i++) {
		// 이전 문자열과 같으면 다음 인덱스로 넘어가기
		if (arr[i - 1] == arr[i])
			continue;
		else // 이전 문자열과 다르다면 출력하기
			cout << arr[i] << "\n";
	}

	return 0;
}