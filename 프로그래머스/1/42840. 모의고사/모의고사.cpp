#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
1번 수포자가 찍는 방식 : 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식 : 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
*/
vector<int> solution(vector<int> answers) {
    vector<int> answer;
  
    int one = 0, two = 0, three = 0;    //각 수포자 번호
    vector<int> seq3 = { 3,3,  1,1,  2,2,  4,4,  5,5 };
    vector<int> seq2 = { 2, 1, 2, 3, 2, 4, 2, 5 };

    for (int i = 0; i < answers.size(); i++){
        if (i % 5 + 1 == answers[i]) one++; //1번 수포자
        if (seq2[i % seq2.size()] == answers[i])two++;  //2번 수포자
        if(seq3[i % seq3.size()] == answers[i])three++; //3번 수포자
    }

    if (one >= two && one >= three) answer.push_back(1);
    if (two>= one && two >= three) answer.push_back(2);
    if (three >= two && three >= one) answer.push_back(3);

    
    return answer;
}