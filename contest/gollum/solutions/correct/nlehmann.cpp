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
using namespace std;

#define MAX 10000000

int main() {
  long long n;
  cin >> n;
  vector<long long> V(MAX+1);

  V[1] = 1;
  V[2] = 2;
  if (n <= 2) {
    cout << n << "\n";
    return 0;
  }
  long i = 3;
  long g = 2;
  while (true) {
    V[i] = V[i-1] + g;
    if (V[i] > n)
      break;
    if (i >= V[g+1]) ++g;
    ++i;
  }
  cout << i - 1 << "\n";

  return 0;
}
