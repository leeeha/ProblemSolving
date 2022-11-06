#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;

	string s = to_string(a * b * c);
	vector<pair<char, int>> v; // 문자와 등장 횟수
	char ch = '0';
	for(int i = 0; i < 10; i++){
		v.push_back({ch++, 0});
	}

	for(int i = 0; i < s.length(); i++){
		for(int j = 0; j < 10; j++){
			if(s[i] == v[j].first){
				v[j].second++;
				break;
			}
		}
	}

	for(int j = 0; j < 10; j++){
		cout << v[j].second << '\n';
	}

    return 0;
}