/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <map>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
  int N, S;
  map<int, int> count;
  scanf("%d %d", &N, &S);

  for (int i = 0; i < S; ++i) {
    int s;
    scanf("%d", &s);
    count[s]++;
  }

  for (int i = 0; i < 5; ++i) {
    int max = -1;
    int smax = -1;
    for (auto p : count) {
      if (p.second > max) {
        max = p.second;
        smax = p.first;
      }
    }
    count.erase(smax);
    if (i > 0)
      printf(" ");
    printf("%d", smax);
  }
  printf("\n");

  return 0;
}
