/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */


#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main () {
  int N, S;
  scanf("%d %d", &N, &S);
  vector<int> count(S+1);

  for (int i = 0; i < N; ++i) {
    int s;
    scanf("%d", &s);
    count[s]++;
  }

  for (int i = 0; i < 5; ++i) {
    int imax = 0;
    for (int j = 1; j <= S; ++j)
      if (count[j] > count[imax])
        imax = j;
    count[imax] = -1;
    if (i > 0)
      printf(" ");
    printf("%d", imax);
  }
  printf("\n");

  return 0;
}
