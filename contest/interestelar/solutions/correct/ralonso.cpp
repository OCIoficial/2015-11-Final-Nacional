#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main (int argc, char *argv[]) {
	
	map<int,int> freq;
	
	int n, s;
	int val;
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> val;
		freq[val] += 1;
	}
	
	for (int i = 0; i < 5; i++) {
		map<int,int>::iterator best = freq.begin();	// Best pair so far
		
		for (auto it = freq.begin(); it != freq.end(); it++) {
			if (it->second > best->second) {
				best = it;
			}
		}
		
		cout << best->first;
		cout << (i == 4 ? "\n" : " ");
		freq.erase(best);
	}
}
