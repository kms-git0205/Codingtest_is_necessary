#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
<문제>
H-Index : 과학자의 생산성, 영향력 나타내는 지표
이 h값을 구하려 함

발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상, 나머지가 h번 이하 인용되었을 때 -> h의 최댓값이 H-INdex

발표한 논문 인용횟수 citations 주이지면, 이 과학자의 H-Index return

발표 논문 수(citations 길이) <= 1000
논문 별 인용 횟수(citations 각 원소) <= 1만


<풀이>
내림차순 정렬 -> citations[i]번 이상 인용된 논문이 i+1편임

6 5 3 1 0



내림차순 정렬
for문 돌면서
    해당 원소값보다 인덱스가 크거나 같으면?
        해당 원소 값이 H-Index

<시간>
O(NlogN)

*/

bool cmpp(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), cmpp);
    
    for(int i=citations.size()-1; i>=0; i--){
        //h : i+1
        int h = i+1;
        
        if(citations[i] >= h) {   //h번 이상 인용된 논문이 h편 이상
            
            return h;
        }
            
            
         
    }
    
    return answer;
}