/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> movx = {-2, -1, +1, +2, +2, +1, -1, -2};
vector<int> movy = {+1, +2, +2, +1, -1, -2, -2, -1};

bool check(int x, int y) {
  return x >= 0 && x < 100 && y >= 0 && y < 100;
}

int bfs(int xi, int yi, int xf, int yf) {
  vector<vector<int> > mat(100, vector<int>(100, -1));
  queue<pair<int, int> > q;
  mat[xi][yi] = 0;
  q.emplace(xi, yi);
  while (!q.empty()) {
    int nx = q.front().first;
    int ny = q.front().second;
    q.pop();
    if (nx == xf && ny == yf)
      return mat[nx][ny];
    for (int i = 0; i < 8; ++i) {
      int vx = nx + movx[i];
      int vy = ny + movy[i];
      if (check(vx, vy) && mat[vx][vy] == -1){
        mat[vx][vy] = mat[nx][ny] + 1;
        q.emplace(vx, vy);
      }
    }
  }
  return -1;
}

int P, Xi, Yi, Xf, Yf;
int calc() {
  if (Xi == Xf && Yi == Yf)
    return 0;
  int pi = (Xi + 101*Yi)%2;
  int pf = (Xf + 101*Yf)%2;
  switch (P) {
  // TORRE
  case 1: return (Xi == Xf || Yi == Yf) ? 1 : 2;
  // ALFIL
  case 2:
    if (pi != pf)
      return -1;
    return abs(Xi-Xf) == abs(Yi-Yf) ? 1 : 2;
  // REINA
  case 3: return (abs(Xi - Xf) == abs(Yi - Yf) || Xi == Xf || Yi == Yf) ? 1 : 2;
  // REY
  case 4: return max(abs(Xi - Xf), abs(Yi - Yf));
  // CABALLO
  case 5: return bfs(Xi, Yi, Xf, Yf);
  }
  return -1;
}

int main() {
  cin >> P >> Xi >> Yi >> Xf >> Yf;
  cout << calc() << endl;
  return 0;
}
