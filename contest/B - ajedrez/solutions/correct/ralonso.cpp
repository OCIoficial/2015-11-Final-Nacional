#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int res = 0;
	
	int t, xi, xf, yi, yf;
	
	scanf("%d", &t);
	scanf("%d %d", &xi, &yi);
	scanf("%d %d", &xf, &yf);
	
	int r = abs(xi - xf);
	int c = abs(yi - yf);
	int d1 = abs(xi - yi - xf + yf);
	int d2 = abs(xi + yi - xf - yf);
	
	switch (t) {
		case 1:
			if (r != 0) res++;
			if (c != 0) res++;
			break;
		
		case 2:
			if (d1 != 0) res++;
			if (d2 != 0) res++;
			if (d1 & 1 == 1) res = -1;
			break;
		
		case 3:
			if (r != 0 || c != 0) res++;
			if (r != 0 && c != 0 && d1 != 0 && d2 != 0) res++;
			break;
		
		case 4:
			res = max(r,c);
			break;
		
		case 5:
			// Octaedro
			res = max(max((d1+2)/3, (d2+2)/3), max((r+1)/2, (c+1)/2));
			// Paridad
			if ((res + r + c) & 1 == 1) res++;
			// Casos borde (no considerados en los testcases
			if (r == 2 && c == 2) res += 2;
			else if (r + c == 1) res = r + c + 2;
			else if (r == 1 && c == 1 && (abs(99-2*xi) == 9) && (abs(99-2*yi) == 9)) res += 2;
			break;
	}
	
	printf("%d\n", res);
	
	return 0;
}
