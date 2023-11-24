#include <string>
#include <vector>

using namespace std;
/*
<문제>
카펫 - 중앙엔 노란색, 테두리 1줄은 갈색
갈색 / 노란색 격자수가 주어졌을 때, 카펫의 가로 세로 크기를 순서대로 담아 return

brown <= 5000
yellow <= 200만
카펫의 가로길이 >= 세로길이

<풀이>
(가로 + 세로) * 2 - 4 = brown
가로*세로 - brown = yellow 

이걸 만족하는 가로, 세로 찾으면 됨

2가로 + 2세로 = brown + 4
가로세로 = brown + yellow

-16가로 -16세로 = -8brown - 32

4가로^2 + 4세로^2 = brown^2 + 16 - 8yellow

세로 = (brown + 4) / 2 - 가로
가로^2 + 세로^2 = (brown^2 + 16 - 8yellow) / 4

가로^2 + 가로^2 -가로*(brown+4) + (brown+4)^2/4 = brown^2/4 + 4 -2yellow


yellow 가 (가로 - 2)랑 나누어 떨어짐
그리고, yellow로부터 구한 세로 줄 수는 yellow / (가로 - 2) + 2 임 -> 몫이 세로 줄 수 -2이므로 2를 더해줌
마지막으로, brown은 2*가로 + 2*세로 -4임 -> 이걸 yello랑 가로로 표현하면
 -> brown = 2*가로 + 2*(yellow/(가로-2) + 2) -4
          = 가로 + yellow/(가로-2)
          
그러면,

i=1 부터 yellow까지 보면서
    yellow가 i로 나누어 떨어지면,
        여기서 brown을 보고 갯수를 맞춰보면 됨
        i+2를 가로로 설정
        이에 따른 세로 구하고, brown과 비교
        맞으면 값 집어넣고 return
        
<시간>
O(yellow)  - 200만
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;


    brown /= 2;    //합

    
    //1~yellow까지
    
    
    
    for (int i = yellow; i >=1; i--) {
        if (yellow% i == 0 && i + yellow / i + 2 == brown) {    //brown : i+2 + yellow/i (비교해보는거)
            
                answer.push_back(i+2);          //가로 : i+2
                answer.push_back(yellow/i+2);   //세로 : yellow/i + 2, 
            
         
            break;
        }
    }

    return answer;
}