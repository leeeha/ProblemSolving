// https://school.programmers.co.kr/learn/courses/30/lessons/134240

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
	vector<int> food {1,3,4,6};
	cout << solution(food) << endl; 

	return 0; 
}