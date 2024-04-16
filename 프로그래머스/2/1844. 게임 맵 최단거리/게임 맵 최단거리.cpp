#include<vector>
#include<queue>
using namespace std;
/*
1950 시작

<문제>
게임 맵 maps 주어질 때, 상대팀 진영에 도차가기 위해 지나야 하는 칸의 최소 갯수 return
불가능한 경우 -1 return

maps : n*m 크기 (각 100 이하)
0은 벽, 1은 길
캐릭터는 처음에 (1, 1)에 위치, 상대 진영은 (n, m)에 위치


<풀이>
모든 방향으로 가보기(도착 시 return 및 비교해서 최소값 선정)
-> BFS

<시간>
O(nlogn)

*/


bool visited[100][100]; //방문 여부



struct pos{
    int r;
    int c;
    int cur_ans; 
};


//현 위치, 현재 지나온 칸 수, maps 입력받음
int goOnestep(int r, int c, int cur_ans, vector<vector<int> > map){
    
    int min_ans = 987654321;
    
    
    queue<pos> q;   //queue
    
    pos a;
    a.r = r; a.c=c; a.cur_ans = cur_ans;
    
    q.push(a);
    
    
    while(!q.empty()){
        pos target = q.front();
        q.pop();
        
        r = target.r; c = target.c; cur_ans = target.cur_ans;
        
        if(r==map.size()-1 && c==map[0].size()-1) return target.cur_ans;

        
        
        map[r][c] = 0;
        
        
        //상
        if(r-1 >= 0 && map[r-1][c] == 1){
    
            map[r-1][c] = 0;
            pos tmp; tmp.r = r-1;  tmp.c = c; tmp.cur_ans = cur_ans+1;
            q.push(tmp);
            
            
        }
        //하
        if(r+1 <= map.size()-1 && map[r+1][c] == 1){
        
            map[r+1][c] = 0;
            pos tmp; tmp.r = r+1;  tmp.c = c; tmp.cur_ans = cur_ans+1;
            q.push(tmp);
        }
        //좌
        if(c-1 >= 0 && map[r][c-1] == 1){
        
            map[r][c-1] = 0;
            pos tmp; tmp.r = r;  tmp.c = c-1; tmp.cur_ans = cur_ans+1;
            q.push(tmp);
        }
        //우
        if(c+1 <= map[0].size()-1 && map[r][c+1] == 1){
            
            map[r][c+1] = 0;
            pos tmp; tmp.r = r;  tmp.c = c+1; tmp.cur_ans = cur_ans+1;
            q.push(tmp);
        }
            
        
    }
    
    return -1;
    
    
    //if(r == map.size()-1 && c == map[0].size()-1) return cur_ans;   //도착한 경우
    //if(r >= map.size() || c >= map[0].size()) return cur_ans;   //범위 밖으로 벗어난 경우
    
    

//     map[r][c] = 0;  //지나옴 처리
    
//     //상
//     if(r-1 >= 0 && map[r-1][c] == 1){

//         vector<vector<int> > map2 = map;
//         map2[r-1][c] = 0;
//         int tmp = goOnestep(r-1, c, cur_ans+1, map2);
//         if (tmp < min_ans) min_ans = tmp;
//     }
//     //하
//     if(r+1 <= map.size()-1 && map[r+1][c] == 1){
    
//         vector<vector<int> > map2 = map;
//         map2[r+1][c] = 0;
//         int tmp = goOnestep(r+1, c, cur_ans+1, map2);
//         if (tmp < min_ans) min_ans = tmp;
//     }
//     //좌
//     if(c-1 >= 0 && map[r][c-1] == 1){
    
//         vector<vector<int> > map2 = map;
//         map2[r][c-1] = 0;
//         int tmp = goOnestep(r, c-1, cur_ans+1, map2);
//         if (tmp < min_ans) min_ans = tmp;
//     }
//     //우
//     if(c+1 <= map[0].size()-1 && map[r][c+1] == 1){
        
//         vector<vector<int> > map2 = map;
//         map2[r][c+1] = 0;
//         int tmp = goOnestep(r, c+1, cur_ans+1, map2);
//         if (tmp < min_ans) min_ans = tmp;
//     }
    
//     return min_ans;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    answer = goOnestep(0, 0, 1, maps);
    
    if(answer == 987654321) answer = -1;
    
    
    return answer;
}