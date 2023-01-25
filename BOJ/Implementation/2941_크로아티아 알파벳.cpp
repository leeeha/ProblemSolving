#include <iostream>
#include <vector>
#include <string>
#define NUM 7
using namespace std;

// Sol1. 2~3���ھ� �����Ͽ� ũ�ξ�Ƽ�� ���ĺ��� ���� ����   

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

	int cnt = 0; // ũ�ξ�Ƽ�� ���ĺ��� ���� 

	for(int i = 0; i < s.size(); i++){
		if(s.substr(i, 3) == "dz="){
			cnt++; 
			i += 2; // ���� ���� ���� ���ڷ� �Ѿ�� 
			continue; 
		}
		
		string token = s.substr(i, 2);
		if(findCroatia(token)){
			i += 1; // ���� ���� ���ڷ� �Ѿ�� 
		}
		
		cnt++; // ���� ���ڷ� �Ѿ��
	}

	cout << cnt; 
	
	return 0; 
}

// Sol2. ũ�ξ�Ƽ�� ���ĺ��� �߰ߵ� ������ ���� ���ڷ� ġȯ�ϱ� 

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
		while(true){ // ũ�ξ�Ƽ�� ���ĺ��� �߰ߵ� ������ #���� ġȯ�Ѵ�. 
			index = s.find(item); 
			if(index == string::npos) break; // �� �̻� ������ break 
			s.replace(index, item.length(), "#"); 
		}
	}

	cout << s.size(); 
	
	return 0; 
}