def solution(name):
    answer = 0
    
    move = len(name) - 1
    
            
    for i in range(len(name)):
        if ord(name[i]) <= ord('N'):
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