#include <string>
#include <vector>
#include <map> 
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> map; 
    
    for(auto e: clothes){
        map[e[1]]++; // ���� ����(key)�� ����(value)
    }
    
    for(auto e: map){ 
        // ���� �������� �ʴ� ����� ���� �����Ͽ� +1 
        answer *= (e.second + 1); 
    }
    
    return answer - 1; // ��� ���� �������� �ʴ� ����� ���� �����ϹǷ� -1 
}