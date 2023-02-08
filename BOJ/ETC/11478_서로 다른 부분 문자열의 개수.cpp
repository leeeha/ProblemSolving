#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <string> 
#include <unordered_set>  
using namespace std;

unordered_set<string> myset; // 중복 제거해서 저장 

int main()
{
	string str; 
	cin >> str; 

	// ababc 
	// a ab aba abab ababc
	// b ba bab babc 
	// a ab abc 
	// b bc 
	// c 
	int len = str.size(); 
	for(int i = 0; i < len; i++){ // N 
		// i + j 
		// 0 + 1~5 
		// 1 + 1~4 
		// 2 + 1~3 
		// 3 + 1~2
		// 4 + 1 
		for(int j = 1; j <= len - i; j++){ // N 
			string token = str.substr(i, j); // N 
			myset.insert(token); // logN 
		}
	}

	cout << myset.size(); 

	return 0; 
}