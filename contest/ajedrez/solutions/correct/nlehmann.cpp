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
    if (nx == xf && ny == yf)
      return mat[nx][ny];
    q.pop();
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

int main() {
  int P, Xi, Yi, Xf, Yf;
  cin >> P >> Xi >> Yi >> Xf >> Yf;
  if (Xi == Xf && Yi == Yf) {
    cout << 0 << endl;
    return 0;
  }
  int pi = (Xi + 101*Yi)%2;
  int pf = (Xf + 101*Yf)%2;
  switch (P) {
  case 1: //TORRE
    if (Xi == Xf || Yi == Yf)
      cout << 1 << endl;
    else
      cout << 2 << endl;
    break;
  case 2: //ALFIL
    if (pi != pf)
      cout << -1 << endl;
    else if (abs(Xi-Xf) == abs(Yi-Yf))
      cout << 1 << endl;
    else
      cout << 2 << endl;
    break;
  case 3: //REINA
    if (abs(Xi - Xf) == abs(Yi - Yf) || Xi == Xf || Yi == Yf)
      cout << 1 << endl;
    else
      cout << 2 << endl;
    break;
  case 4: //REY
    cout << max(abs(Xi - Xf), abs(Yi - Yf)) << endl;
    return 0;
  case 5: //Caballo
    cout << bfs(Xi, Yi, Xf, Yf) << endl;
  }
  return 0;
}
