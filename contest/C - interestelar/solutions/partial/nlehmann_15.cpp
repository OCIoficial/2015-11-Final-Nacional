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

  int a;
  scanf("%d", &a);
  printf("%d", a);
  for (int i = 1; i < N; ++i) {
    scanf("%d", &a);
    printf(" %d", a);
  }
  printf("\n");
}
