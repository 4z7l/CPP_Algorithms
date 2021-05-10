#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 5:34 ~ 7:55..

// https://rubiks-cube-solver.com/fr/
/*
*	¨Û
* ¨Ó¨ã¨Î
*	¨Þ
*	¨å
*/

#define ORANGE 0
#define GREEN 1
#define WHITE 2
#define BLUE 3
#define RED 4
#define YELLOW 5

#define BOTTOM 0
#define LEFT 1
#define TOP 2
#define RIGHT 3

char colors[6] = { 'o','g','w','b','r','y' };

int rotate_face[6][4] = { {YELLOW,BLUE,WHITE,GREEN},
							{ORANGE,WHITE,RED,YELLOW},
							{ORANGE,BLUE,RED,GREEN},
							{ORANGE,YELLOW,RED,WHITE},
							{WHITE,BLUE,YELLOW,GREEN},
							{RED,BLUE,ORANGE,GREEN} };

int rotate_direction[6][4] = { {BOTTOM,TOP,TOP,TOP},
							{LEFT,LEFT,LEFT,LEFT},
							{BOTTOM,LEFT,TOP,RIGHT},
							{RIGHT,RIGHT,RIGHT,RIGHT},
							{BOTTOM,BOTTOM,TOP,BOTTOM},
							{BOTTOM,RIGHT,TOP,LEFT} };

// BOTTOM,LEFT,TOP,RIGHT
int dxy[4][3][2] = { {{2,0}, {2,1},{2,2}},
					{{0,0},{1,0},{2,0}},
					{{0,2},{0,1},{0,0}},
					{{2,2},{1,2},{0,2}} };

int idxy[8][2] = { {0,0}, {0,1},{0,2}, {1,2}, {2,2}, {2,1}, {2,0}, {1,0} };

void print_cube(vector<vector<vector<char>>> cube, int face) {
	if (face == -1) {
		for (int k = 0; k < 6; k++) {
			for (int i = 0; i < 3; i++) {
				if (k != 1) cout << "   ";
				if (k == 3) cout << "   ";
				for (int j = 0; j < 3; j++) {
					cout << cube[k][i][j];
				}
				cout << '\n';
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[face][i][j];
			}
			cout << '\n';
		}
	}
}

void rotate_clockwise(vector<vector<vector<char>>>& cube, int face) {
	char temp[3];
	for (int d = 0; d < 3; d++) {
		int f = rotate_face[face][3];
		int dind = rotate_direction[face][3];
		int dx = dxy[dind][d][0];
		int dy = dxy[dind][d][1];
		temp[d] = cube[f][dx][dy];
	}
	for (int ff = 3; ff > 0; ff--) {
		for (int d = 0; d < 3; d++) {
			int f1 = rotate_face[face][ff - 1];
			int f2 = rotate_face[face][ff];
			int dind1 = rotate_direction[face][ff - 1];
			int dind2 = rotate_direction[face][ff];
			int dx1 = dxy[dind1][d][0];
			int dy1 = dxy[dind1][d][1];
			int dx2 = dxy[dind2][d][0];
			int dy2 = dxy[dind2][d][1];
			cube[f2][dx2][dy2] = cube[f1][dx1][dy1];
		}
	}
	for (int d = 0; d < 3; d++) {
		int f = rotate_face[face][0];
		int dind = rotate_direction[face][0];
		int dx = dxy[dind][d][0];
		int dy = dxy[dind][d][1];
		cube[f][dx][dy] = temp[d];
	}

	for (int r = 0; r < 2; r++) {
		char temp2 = cube[face][idxy[7][0]][idxy[7][1]];
		for (int d = 7; d > 0; d--) {
			cube[face][idxy[d][0]][idxy[d][1]] = cube[face][idxy[d - 1][0]][idxy[d - 1][1]];
		}
		cube[face][idxy[0][0]][idxy[0][1]] = temp2;
	}
}

void rotate_anticlockwise(vector<vector<vector<char>>>& cube, int face) {
	for (int i = 0; i < 3; i++) {
		rotate_clockwise(cube, face);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int TC, N, face = 0;
	char cmd[3];

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		vector<vector<vector<char>>> cube(6, vector<vector<char>>(3, vector<char>(3)));
		for (int k = 0; k < 6; k++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[k][i][j] = colors[k];
				}
			}
		}

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> cmd;

			if (cmd[0] == 'B') face = 0;
			else if (cmd[0] == 'L') face = 1;
			else if (cmd[0] == 'U') face = 2;
			else if (cmd[0] == 'R') face = 3;
			else if (cmd[0] == 'F') face = 4;
			else face = 5;

			if (cmd[1] == '+') rotate_clockwise(cube, face);
			else rotate_anticlockwise(cube, face);
		}
		print_cube(cube, WHITE);
	}

	return 0;
}