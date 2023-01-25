#include <iostream>
#include <vector>
#include <string>
#define NUM 7
using namespace std;

// Sol1. 2~3글자씩 추출하여 크로아티아 알파벳의 개수 세기   

string croatia[NUM] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};

bool findCroatia(string token) {
	for(int j = 0; j < NUM; j++){
		if(croatia[j] == token) 
			return true; 
	}
	return false; 
}

int main()
{
	string s;
	cin >> s;

	int cnt = 0; // 크로아티아 알파벳의 개수 

	for(int i = 0; i < s.size(); i++){
		if(s.substr(i, 3) == "dz="){
			cnt++; 
			i += 2; // 다음 다음 다음 문자로 넘어가기 
			continue; 
		}
		
		string token = s.substr(i, 2);
		if(findCroatia(token)){
			i += 1; // 다음 다음 문자로 넘어가기 
		}
		
		cnt++; // 다음 문자로 넘어가기
	}

	cout << cnt; 
	
	return 0; 
}

// Sol2. 크로아티아 알파벳이 발견될 때마다 단일 문자로 치환하기 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> croatia {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}; 
	
	string s;
	cin >> s;

	int index = 0; 
	for(int i = 0; i < croatia.size(); i++){
		string item = croatia[i];
		while(true){ // 크로아티아 알파벳이 발견될 때마다 #으로 치환한다. 
			index = s.find(item); 
			if(index == string::npos) break; // 더 이상 없으면 break 
			s.replace(index, item.length(), "#"); 
		}
	}

	cout << s.size(); 
	
	return 0; 
}