#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
<문제>
조이스틱 조작 횟수의 최소값 구하기
처음엔 A로만 이루어져 있음

<풀이>
A에서 25번 이동하면 Z

*/
int solution(string name) {
    int answer = 0;

    int move = name.size() - 1;


    for (int i = 0; i < name.size(); i++) {   //알파벳 이동 처리
        if (name[i] <= 'N')
            answer += (int)name[i] - (int)'A';
        else
            answer += (int)'Z' - (int)name[i] + 1;

        int idx = i + 1;

        //A가 안나올 때까지 계속 오른쪽으로 idx를 이동
        while (idx < name.size() && name[idx] == 'A')
            idx++;


        int left_right = (name.size() - idx) * 2 + i;  //[0] -> [i](오른쪽) -> [idx](왼쪽)
        int right_left = i * 2 + (name.size() - idx);  //[0] -> [idx](왼쪽) -> [i](오른쪽)
        move = min(move, right_left);
        move = min(move, left_right);
    }
    answer += move; //좌우이동 횟수   
    cout << move << endl;
    return answer;
}

int main() {
    cout << solution("JAAABDAA") << endl;

}