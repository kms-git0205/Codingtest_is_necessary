#include<iostream>
#include<vector>
#include<algorithm>

#define MAXX 987654321
using namespace std;
/*
<문제>

1645 시작

직사각형 보드에 빨강, 파랑 구슬 하나씩 넣고 
빨간 구슬을 구멍을 통해 빼내는 게임

보드 세로 N, 가로 M
가장 바깥 행, 열은 모두 막힘
구멍 하나 있음 -> 여기로 빨간 구슬 빼기 / 파란 구슬은 안됨

중력을 통해 굴리기(상하좌우 동작 가능)
기울이기를 통해 굴리고, 구슬이 움직이지 않을 때 까지 기울임

보드 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 뺄 수 있는지 구하기



입력:
N M (M 10 이하)
N개 줄
	보드 모양을 나타내는 문자열(길이 M) -> . # O R B 중 하나

출력:
최소 몇 번 만에 빨간 구슬을 구멍으로 빼낼 수 있는 지
(10번 이하로 못 빼내면 -1 출력)


<풀이>

재귀?
직접 다 해보면서, 최소값 뽑기
기울이면 안되는 경우 제거

기울이면 안되는 경우(하나라도 해당되면 종료)
	1. 파란 구슬이 구멍에 감
	2. 파랑, 빨강 구슬 움직임 변동이 없음
	3. 총 횟수가 10번 넘어감

끝나는 경우(전부 해당해야 함)
	1. 빨강이 구멍에 도착
	2. 파랑은 구멍이 아닌 곳에 도착
	3. 총 횟수가 10번 이하
	

<시간>
O(4^10) -> 1048576번

*/


//현 상황을 담음
struct Situation {
	int cnt;
	pair<int, int> red;
	pair<int, int> blue;

	Situation(pair<int, int> redt, pair<int, int> bluet) {
		//cnt = cntt;
		red = redt;
		blue = bluet;
	}
};

//한 번 기울임 -> 1, 2, 3, 4 순으로 상하좌우
//red/blue : 공 위치
Situation MoveOne(vector<string> pan, int way, pair<int, int> red, pair<int, int> blue) {

	int rx = red.first, ry = red.second, bx = blue.first, by = blue.second;
	bool is_hole = false;	//구멍 도착 여부


	//cout << "이동 전 Situation - " << "red:" << red.first << " " << red.second << " , blue : " << blue.first << " " << blue.second << endl;


	if (way == 1) {	//상

		while (rx >= 0 && pan[rx][ry] == '.') { rx--; } rx++;
		while (bx >= 0 && pan[bx][by] == '.') { bx--; } bx++;

	
		if (rx != 0 && pan[rx - 1][ry] == 'O') { is_hole = true; rx--; }
		if (bx != 0 && pan[bx - 1][by] == 'O') { is_hole = true; bx--; }

		if (rx == bx && ry == by && red.first < blue.first && !is_hole) bx++;
		else if (rx == bx && ry == by && red.first > blue.first && !is_hole) rx++;

		//cout << "상";// << endl;
	}
	else if (way == 2) {	//하
		
		while (rx <= pan.size() && pan[rx][ry] == '.') { rx++; } rx--;
		while (bx <= pan.size() && pan[bx][by] == '.') { bx++; } bx--;

		if (rx != pan.size() - 1 && pan[rx + 1][ry] == 'O') { is_hole = true; rx++; }
		if (bx != pan.size() - 1 && pan[bx + 1][by] == 'O') { is_hole = true; bx++; }

		if (rx == bx && ry == by && red.first < blue.first && !is_hole) rx--;
		else if (rx == bx && ry == by && red.first > blue.first && !is_hole) bx--;

		//cout << "하";// << endl;
	}
	else if (way == 3) {	//좌

		while (ry >= 0 && pan[rx][ry] == '.') { ry--; } ry++;
		while (by >= 0 && pan[bx][by] == '.') { by--; } by++;

		if (ry != 0 && pan[rx][ry - 1] == 'O') { is_hole = true; ry--; }
		if (by != 0 && pan[bx][by - 1] == 'O') { is_hole = true; by--; }

		if (rx == bx && ry == by && red.second < blue.second && !is_hole) by++;
		else if (rx == bx && ry == by && red.second > blue.second && !is_hole) ry++;

		//cout << "좌";// << endl;
	}
	else if (way == 4) {	//우

		while (ry <= pan[0].size() && pan[rx][ry] == '.') { ry++; } ry--;
		while (by <= pan[0].size() && pan[bx][by] == '.') { by++; } by--;

		if (ry != pan[0].size() && pan[rx][ry + 1] == 'O') { is_hole = true; ry++; }
		if (by != pan[0].size() && pan[bx][by + 1] == 'O') { is_hole = true; by++; }

		if (rx == bx && ry == by && red.second < blue.second && !is_hole) ry--;
		else if (rx == bx && ry == by && red.second > blue.second && !is_hole) by--;

		//cout << "우";// << endl;
	}

	red.first = rx, red.second = ry, blue.first = bx, blue.second = by;
	//cout << "이동 후 Situation - " << "red:" << red.first << " " << red.second << " , blue : " << blue.first << " " << blue.second << endl << endl;

	return Situation(red, blue);

}


int reverse(int a) {	//a의 반대방향 return
	if (a == 1) return 2;
	else if (a == 2) return 1;
	else if (a == 3) return 4;
	else if (a == 4) return 3;
	else return 0;
}

int minn = MAXX;

//pan: 보드 현황, cnt : 기울임 카운트, red/blue : 각 공 위치, prev: 이전에 기울인 방향
int getAns(vector<string> pan, int cnt, pair<int, int>red, pair<int, int>blue, int prev) {	//기울이기 시뮬레이션

	//기울이면 안되는 경우
	if (pan[blue.first][blue.second] == 'O') return MAXX;
	if (cnt > 10) return MAXX;

	//끝나는 경우
	if (pan[red.first][red.second] == 'O' && pan[blue.first][blue.second] != 'O') {
		//cout << "조건 만족! cnt는? " << cnt << endl;
		return cnt;
	}



	for (int i = 1; i <= 4; i++) {	//상하좌우 기울인 후, 판단
		
		//이건 이동만
		if (i == reverse(prev)) continue;	//이전 방향의 반대방향이면 건너뛰기
		Situation tmp = MoveOne(pan, i, red, blue);	//red/blue 공 위치, cnt만 반환(pan은 어차피 같음)
		

		int res;

		if (tmp.red == red && tmp.blue == blue) res = MAXX;	//움직임 변동이 없으면 끝
		else {
			//cout << "Situation - " << "red:" << tmp.red.first << " " << tmp.red.second << " , blue : " << tmp.blue.first << " " << tmp.blue.second << endl;

		/*	for (int ii = 0; ii < pan.size(); ii++) {
				for (int jj = 0; jj < pan[0].size(); jj++) {
					if (ii == tmp.red.first && jj == tmp.red.second) cout << "R";
					else if (ii == tmp.blue.first && jj == tmp.blue.second)cout << "B";
					else cout << pan[ii][jj];
				}
				cout << endl;
			}*/


			//cout << "" << endl;//새로운 주기 시작
			res = getAns(pan, cnt + 1, tmp.red, tmp.blue, i);
		}

		if (res < minn) {
			//cout << "여기 오긴 함?" << endl;
			minn = res;
		}
	}


	if (minn == MAXX) return MAXX;
	else {// cout << "\n\n하나 끝\n-> 이 때 cnt : " << minn << endl << endl; 
		return minn; }

}

int main() {

	int n, m; cin >> n >> m;
	//n, m 입력

	vector<string> pan;	//보드판

	//각 공 위치
	pair<int, int> red;	
	pair<int, int> blue;


	for (int i = 0; i < n; i++) {	//n개의 줄
		string s; cin >> s;	//문자열 입력

		//공 위치 설정
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'R') {
				red.first = i; red.second = j; s[j] = '.';
			}
			if (s[j] == 'B') {
				blue.first = i; blue.second = j; s[j] = '.';
			}
		}

		pan.push_back(s);
	}

	int ans = getAns(pan, 0, red, blue, 0);
	if (ans == MAXX) ans = -1;
	cout << ans;

	return 0;
}

// 상 좌 하