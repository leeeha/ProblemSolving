#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;

	int sum = 0;
	vector<char> v;
	for(int i = 0; i < s.size(); i++){
		if(s[i] < 65 || s[i] > 90){
			sum += s[i] - '0';
		}else{
			v.push_back(s[i]);
		}
	}

	if(!v.empty()){
		// 알파벳 대문자를 오름차순으로 정렬
		sort(v.begin(), v.end());

		for(int i = 0; i < v.size(); i++){
			cout << v[i];
		}
	}
		
	if(sum != 0) 
		cout << sum << '\n';

    return 0;
}