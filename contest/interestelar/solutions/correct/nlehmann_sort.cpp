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
  vector<int> vec(N);
  vector<int> vec2;
  vector<int> vec3;

  for (int i = 0; i < N; ++i)
    scanf("%d", &vec[i]);

  sort(vec.begin(), vec.end());

  int count = 1;
  for (int i = 1; i < N; ++i) {
    if (vec[i] == vec[i-1]) {
      count++;
    } else {
      vec2.push_back(vec[i-1]);
      vec3.push_back(count);
      count = 1;
    }
  }
  vec2.push_back(vec[N-1]);
  vec3.push_back(count);

  for (int i = 0; i < 5; ++i) {
    int imax = 0;
    for (int j = 1; j < vec2.size(); ++j) {
      if (vec3[j] > vec3[imax])
        imax = j;
    }
    vec3[imax] = -1;
    if (i > 0)
      printf(" ");
    printf("%d", vec2[imax]);
  }
  printf("\n");

  return 0;
}
