/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

int main () {
  int N, P, A, B;
  cin >> N >> P >> A >> B;
  if (P == 2)
    swap(A, B);

  if (A == B) {
    cout << (N%(A+1)==0 ? 3-P : P) << endl;
    return 0;
  }

  N -= A;
  P = 3-P;
  swap(A,B);

  int ra = (N+A)/(A+1);
  int rb = (N+B)/(B+1);
  if (ra < rb) cout << P << endl;
  else cout << 3 - P << endl;


  return 0;
}
