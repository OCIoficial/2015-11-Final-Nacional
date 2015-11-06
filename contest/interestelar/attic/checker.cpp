#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>

#define IN true
#define OUT false

using namespace std;

int wrong_ans() {
	cout << "0.0\n";
	return 0;
}

int right_ans() {
	cout << "1.0\n";
	return 0;
}

int main (int argc, char *argv[]) {
	ifstream fin;  	// Input
	ifstream fcorr;	// Expected
	ifstream ftest;	// Submission
	
	fin.open(argv[1]);
	fcorr.open(argv[2]);
	ftest.open(argv[3]);
	
	if (!fin.is_open()) {
		cerr << "Could not open file \"" << argv[1] << "\".\n";
		return 1;
	}

	if (!fcorr.is_open()) {
		cerr << "Could not open file \"" << argv[2] << "\".\n";
		return 2;
	}

	if (!ftest.is_open()) {
		cerr << "Could not open file \"" << argv[3] << "\".\n";
		return 3;
	}
	
	fcorr.close();	// Unused
	
	
	/* Read events and get frequencies */
	
	map<int,int> freq;
	
	int n, s;
	int val;
	
	fin >> n >> s;
	for (int i = 0; i < n; i++) {
		fin >> val;
		freq[val] += 1;
	}
	
	fin.close();
	
	
	/* Get keys which may be used in the answer */
	
	vector<int> opts; // Any possible answer IS here.
	int first_repeated = 0; // Numbers before this MUST be included
	int last = -1;
	
	for (int i = 0; ; i++) {
		map<int,int>::iterator best = freq.begin();	// Best pair so far
		
		for (auto it = freq.begin(); it != freq.end(); it++) {
			if (it->second > best->second) {
				best = it;
			}
		}
		
		if (best->second != last) {
			if (i >= 5) {
				break;
			}
			first_repeated = i;
		}
		
		last = best->second;
		opts.push_back(best->first);
		freq.erase(best);
	}
	
	
	/* Parsing (first line only) */
	
	vector<int> ans(5, 0);
	
	bool state = OUT;
	bool firstln = false;
	int k = 0;
	while (true) {
		char c = ftest.get();
		
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if (firstln || k == 5) {
				k = -1;
				goto endloop;
			}
			state = IN;
			ans[k] *= 10;
			ans[k] += c - '0';
			break;
		
		case ' ':
			if (state == IN) {
				k++;
				state = OUT;
			}
			break;
		
		case '\n':
			if (state == IN) {
				k++;
				state = OUT;
			}
			firstln = true;
			break;
		
		case EOF:
			if (state == IN) {
				k++;
				state = OUT;
			}
			goto endloop;
// 			break;
		
		default:
			cerr << "Error de formato: símbolo \'" << (char)c << "\' desconocido.\n";
			return wrong_ans();
		}
	}
	endloop:
	
	ftest.close();
	
	if (k != 5) {
		cerr << "Error de formato: debe imprimir una sola línea con 5 números.\n";
		return wrong_ans();
	}
	
	
	/* Answer checking */
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i; j++) {
			if (ans[i] == ans[j]) {
				// Duplicate system
				cerr << "Respuesta incorrecta.\n";
				return wrong_ans();
			}
		}
		int pos;
		for (pos = 0; pos < opts.size(); pos++) {
			if (opts[pos] == ans[i]) {
				break;
			}
		}
		if (pos == opts.size()) {
			// Not found; system is not part of any solution
			cerr << "Respuesta incorrecta.\n";
			return wrong_ans();
		}
		if (first_repeated <= pos) {
			first_repeated++;
		}
	}
	
	if (first_repeated != 5) {
		// Missing a mandatory system
		cerr << "Repuesta incorrecta.\n";
		return wrong_ans();
	}
	return right_ans();
}
