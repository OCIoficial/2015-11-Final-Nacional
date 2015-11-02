/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> G(n < 3? 4 : n + 1);

  G[1] = 1;
  G[2] = 2;
  G[3] = 2;

  int i = 4;
  int a = 3;
  while (i <= n) {
    for (int j = 0; i <= n && j < G[a]; ++j)
      G[i++] = a;
    a++;
  }

  cout << G[n] << endl;
}

