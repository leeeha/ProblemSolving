#include <string>
using namespace std;

int solution(string s){
    int answer = s.size(); // �־��� ���ڿ��� ����

    // 1�� ����(step)���� ���� ������ �÷����� Ȯ��
    for (int step = 1; step <= s.size() / 2; step++){
        string compressed = "";
        string prev = s.substr(0, step); // �տ������� step��ŭ�� ���ڿ� ����
        int cnt = 1; // Ư�� �κ� ���ڿ��� �ݺ��� Ƚ�� ����

        // ����(step) ũ�⸸ŭ ������Ű�� ���� ���ڿ��� ��
        for (int j = step; j < s.size(); j += step){
            // ���� ���ڿ��� �����ϴٸ� cnt ����
            if(prev == s.substr(j, step)) 
                cnt++;
            // �ٸ� ���ڿ��� ���Դٸ� (�� �̻� ���� �Ұ�)
            else{
                compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;

                // �ٽ� ���� �ʱ�ȭ 
                prev = s.substr(j, step); // step�� ���ڿ��� ���̸� �Ѿ�� ���ڿ� �������� ����
                cnt = 1;
            }
        }

        // �����ִ� ���ڿ��� ���ؼ� ó��
       compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;

       // ������� ���� ���ڿ� �߿��� ���� ª�� ���� ����
       answer = min(answer, (int)compressed.size());
    }

    return answer;
}