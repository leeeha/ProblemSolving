#include<vector>
#include<algorithm>
using namespace std;

// ���� ��ȣ�� �������� �������� ����
bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k){
    // (������ �Դ� �� �ɸ��� �ð�, ���� ��ȣ)�� ��� �����ϱ�
    vector<pair<int, int>> foods;
    int n = food_times.size(); // ó���� ������ ����
    for (int i = 0; i < n; i++){
        foods.push_back(make_pair(food_times[i], i + 1));
    }

    // �ð��� �������� �������� ����
    sort(foods.begin(), foods.end());

    int prevTime = 0;
    // auto -> vector<pair<int, int>>::iterator
    // ó���ؾ� �� ������ ���� n�� �ϳ��� �پ���.
    for (auto it = foods.begin(); it != foods.end(); it++, n--){
        int gap = it->first - prevTime; // �ð� ����
        long long spendTime = (long long)gap * n; // int * int -> int ���� ���� ���� �ֱ� ������ ll Ÿ������ ĳ����
        if(gap == 0) continue;
        
        if(spendTime <= k){
            k -= spendTime; // ���⼭ k�� �ѹ��� Ȯ ���� �� �ִ�!
            prevTime = it->first; 
        }else{ 
            k %= n;
            sort(it, foods.end(), comp); // ���� ��ȣ�� �������� �ٽ� ����
            return (it + k)->second; // k%n �ε����� �ش��ϴ� ���� ��ȣ ����
        }
    }
    
    return -1; // k�� �̳��� ��� ������ �� ���� ���
}