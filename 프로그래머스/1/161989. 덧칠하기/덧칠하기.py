'''
<문제>
n미터 벽에 페인트 덧칠
1미터 길이의 구역 n개로 나누고, 1~n번까지 구역 번호
롤러의 길이 : m미터 벽에 페인트 한 번 칠하는 규칙이 있음
    벽에서 벗어나면 안됨
    구역의 일부만 포함되도록 칠하면 안됨
-> 롤러의 좌우 끝을 경계선 or 벽의 좌우측 끝에 맟춰 칠함 -> 이걸 한 번 칠했다고 정의

페인트칠 횟수를 최소하 하고자 함(중복으로 칠해도 되지만, 칠하기로 정한 구역은 최소 한 번 칠해야 함)
n, m, 칠하기로 정한 구역번호 정수배열 section 주어지면, 페인트칠 최소 횟수를 return

m <= n <= 10만
section 길이 <= n
    section 원소 <= n (1부터)
    중복없고, 오름차순 정렬되어있음
    
<풀이>
처음부터 반복문 돌면서, 칠해나가면 됨


<시간>
O(N)
'''

def solution(n, m, section):
    
    
    answer = 0 
    

    
    while len(section)!=0:   #section 돌면서
        target = section[0] # 칠해야 하는 칸
        next = target+m-1    # 롤러가 닿는 곳

        while section[0] <= next:
            del section[0]
            if len(section)==0:
                break
            
        answer+=1
        
        
    return answer