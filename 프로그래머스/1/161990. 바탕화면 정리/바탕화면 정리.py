def solution(wallpaper):
    answer = []
    h = len(wallpaper) # 배경화면의 세로값
    wallpaper = list(wallpaper)
    w = len(wallpaper[0]) # 배경화변 가로값
    
    start = [0,0] #시작 좌표 - 가장 작은 숫자들 저장
    end = [0,0] #끝 좌표 - 가장 큰 숫자들 저장
    hi = [] #세로 좌표들
    wi = [] #가로 좌표들
    #min, max 로... 세로랑 가로 따로 저장하고... min끼리 max 끼리 하면되는거 아님?
    for i in range(h):
        for j in range(w):
            if wallpaper[i][j] == "#":
                hi.append(i)
                wi.append(j)
    
    print(hi)
    print(wi)

    answer= [min(hi),min(wi),max(hi)+1,max(wi)+1]
   
    print(answer)
    return answer