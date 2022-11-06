#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverse(string const &s)
{
    string rev(s.rbegin(), s.rend());
    return rev;
}

string solution(vector<int> food) {
    string answer, front; 

	for(int i = 1; i < food.size(); i++){
		int num = food[i] / 2;
		while(num--){
			front += to_string(i);
		}
	}

	answer = front + '0' + reverse(front); 
    
    return answer;
}

int main(){
	vector<int> food; 
	food.push_back(1);
	food.push_back(3);
	food.push_back(4);
	food.push_back(6);
	
	cout << solution(food) << endl; 

	return 0; 
}