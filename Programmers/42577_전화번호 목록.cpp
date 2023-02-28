#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> v) { 
    sort(v.begin(), v.end());
    
    // ���ξ�ϱ� �ܼ��� find �Լ��� ����ϴ� �� �ƴ϶� 
    // '0���� v[i] ũ�⸸ŭ' �κ� ���ڿ��� �����ؼ� ������ ���ҿ� ���ؾ� �Ѵ�! 
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] == v[i + 1].substr(0, v[i].size())){
            return false; 
        }
    }
    
    return true; 
}