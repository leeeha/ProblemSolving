#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n; // 스택 수열의 항의 개수

	stack<int> s;
	vector<char> op; // push, pop 연산 결과

	int x; // 스택 수열의 항 하나씩 입력 받기
	int num = 1; // 1~n까지의 정수

	for (int i = 0; i < n; i++) {
		cin >> x;

		// 수열의 현재 항보다 작거나 같은 정수들은 push
		while (num <= x) {
			s.push(num);
			num++;
			op.push_back('+');
		}

		// 스택의 top과 수열의 항이 같으면 pop!
		if (s.top() == x) {
			s.pop();
			op.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (char ch : op)
		cout << ch << '\n';

	return 0;
}