#include <iostream>
using namespace std;

bool isPalindrome(string& s) {
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s[left++] != s[right--])
			return false;
	}
	return true;
}

int main() {
	string str;
	while (true) {
		cin >> str;
		if (str == "0") break;

		if (isPalindrome(str)) cout << "yes\n";
		else cout << "no\n";
	}
}