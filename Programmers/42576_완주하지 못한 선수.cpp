#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// �� �迭�� ũ�� ���̴� 1
string solution(vector<string> part, vector<string> com) { 
    sort(part.begin(), part.end());
    sort(com.begin(), com.end());
    
    // ¦��� �� 
    for(int i = 0; i < com.size(); i++){ 
        if(part[i] != com[i]){ 
            return part[i]; 
        }
    }
    
    return part[part.size() - 1]; 
}