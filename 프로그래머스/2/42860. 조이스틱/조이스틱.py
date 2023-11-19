def solution(name):
    answer = 0
    lr = len(name) - 1
    for i, s in enumerate(name):
        answer += min(ord(s) - ord("A"), ord("Z")-ord(s)+1)

        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
        
        lr = min([lr, 2 * i + len(name) - next, i + 2 * (len(name) - next)])
    answer += lr
    
    return answer