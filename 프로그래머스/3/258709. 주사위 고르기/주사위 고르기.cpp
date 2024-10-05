#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
<문제>
A, B가 주사위 n개 가지고 승부
주사위 6개 면 각 하나의 숫자, 각 면 나올 확률 동일
1~n의 번호를 가지고 있고, 주사위의 수 구성은 모두 다름

A가 문저 n/2개 주사위 가져가고, B가 남은 거 가져감
각각 모두 주사위 굴린 뒤, 수 합해서 점수 계산
더 큰 쪽이 승리, 같다면 무승부

A는 자신이 승리할 확률이 가장 높아지도록 가져가려 함

주사위에 쓰인 수 구성을 담은 2차원 정수배열 dice 주어짐
A가 골라야 하는 주사위 번호를 오름차순으로 1처원 정수 배열에 담아 return

승리 확률이 가장 높은 주사위조합이 유일한 경우만 주어짐


dice 길이 n <= 10
    n은 2의 배수
    dice[i] : i+1번 주사위에 쓰인 6개 수 담음
    dice[i] 원소 <= 100



<풀이>
약간, 높은 수 많은 주사위가 유리하지 않을까?
또는 6개 숫자 합이 큰 주사위가 유리하지 않을까?

-> 합이 가장 큰 주사위 순으로 가져가기
합이 같으면? 중앙값 큰 주사위 순으로 가져가기


주사위 합 pair 담은 배열 sum_mid_dice

sum 1순위, mid 2순위로 정렬


<시간>

주사위 5개씩 가져가서 한 판 하는 경우
 -> 6^5 * (10/2) 
 
주사위를 뽑는 경우의수
 -> 10C5


*/

int targetDiceNum;
vector<vector<int>> realDice;
vector<int> DiceListA;
vector<int> DiceListB;
int maxWinNum;
vector<int> winA;

void makeList(vector<int> DL, bool isA, int deep, int Num){
    if(deep == DL.size()){
        if(isA){
            DiceListA.push_back(Num);
        }
        else
            DiceListB.push_back(Num);
        return;
    } 
    else{
        for(int i=0; i<6; i++)
            makeList(DL, isA, deep+1, Num+realDice[DL[deep]][i]);
    }
}

void calc(vector<int> AD, vector<int> BD){
    DiceListA=vector<int>(0);
    DiceListB=vector<int>(0);
    makeList(AD, true, 0, 0);
    makeList(BD, false, 0, 0);
    sort(DiceListA.begin(), DiceListA.end());
    sort(DiceListB.begin(), DiceListB.end());
    int aldx=0, bldx=0;
    int winNum=0;
    while(aldx < DiceListA.size() && bldx < DiceListB.size()){
        if(DiceListA[aldx]>DiceListB[bldx]){
            bldx+=1;
        }
        else{
            winNum+=bldx;
            aldx+=1;
        }
    }
    
    if(bldx == DiceListB.size()){
        winNum+=bldx*(DiceListA.size()-aldx);
    }
    if(winNum>maxWinNum){
        maxWinNum=winNum;
        winA=AD;
    }
}


void combi(vector<int> AD, vector<int> BD, int nowD){
    vector<int> tD;
    if(AD.size() == targetDiceNum){
        tD=BD;
        for(int i=nowD; i<realDice.size(); i++){
            tD.push_back(i);
        }
        calc(AD, tD);
    }
    else if(BD.size()==targetDiceNum){
        tD=AD;
        for(int i=nowD; i<realDice.size(); i++){
            tD.push_back(i);
        }
        calc(tD, BD);
    }
    else{
        tD=AD;
        tD.push_back(nowD);
        combi(tD, BD, nowD+1);
        tD=BD;
        tD.push_back(nowD);
        combi(AD, tD, nowD+1);
    }
    return;
}

vector<int> solution(vector<vector<int>> dice) {
    realDice=dice;
    targetDiceNum = dice.size() / 2;
    combi(vector<int>(0), vector<int>(0), 0);
    for(int i=0; i<winA.size(); i++){
        winA[i]+=1;
    }
    return winA;
}