'''
<문제>
조이스틱 조작 횟수의 최소값 구하기
처음엔 A로만 이루어져 있음

<풀이>
A에서 25번 이동하면 Z

1. 위, 아래를 통해 알파벳 조정 횟수 정하기
 - easy
 
2. 좌, 우 이동방향 횟수 정하기
 1. 그냥 한 방향으로 순차적 진행(A가 없으면 이게 최적)
   - 이걸 default로 설정([0] ~ [끝] 까지 이동)
 2. A가 있는 구간에 대해 처리하면서 좌우로 왔다갔다 진행
   - 이 때 두가지 경우가 있음 -> 오른쪽 이동 후 왼쪽이동 / 왼쪽 이동 후 오른쪽 이동

<시간>
O(N) -> 가능
'''

def solution(name):
    answer = 0
    
    move = len(name) - 1
    
            
    for i in range(len(name)):
        # 알파벳 조정 카운트
        if name[i] <= 'N':
            answer += ord(name[i]) - ord('A')
        else:
            answer += ord('Z') - ord(name[i]) + 1

        idx = i + 1

        # A가 안나올 때까지 계속 오른쪽으로 idx를 이동
        while idx < len(name) and name[idx] == 'A':
            idx += 1

        # i: [0] -> [i]로 가는 이동 횟수(방향 : 오른쪽)
        # len(name) - idx: [0] -> [idx]로 가는 이동 횟수(방향 : 왼쪽)
        left_right = (len(name) - idx) * 2 + i  # [0] -> [i](오른쪽) -> [idx](왼쪽)
        right_left = i * 2 + (len(name) - idx)  # [0] -> [idx](왼쪽) -> [i](오른쪽)

        move = min(move, right_left, left_right)

    answer += move  # 좌우 이동 횟수
    print(move)
    return answer    