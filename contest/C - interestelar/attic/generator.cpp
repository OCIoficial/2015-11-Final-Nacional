#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <random>
#include <chrono>
#include <set>

using namespace std;

void usage(char *);
void swap(vector<int>&, int, int);

default_random_engine gen;

int main (int argc, char *argv[]) {
	
	/* Input */
	
	int n = 5, s = 5, r = 5;
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] != '-') {
			cerr << argv[0] << ": Unknown parameter \'" << argv[i] << "\'.\n";
			cerr << "Try running \'" << argv[0] << " -h\' for help.\n";
			return 1;
		}
		
		if (strcmp(argv[i],"--help") == 0) {
			usage(argv[0]);
			return 0;
		}
		
		switch (argv[i][1]) {
		case 'n':
			//FIXME validate argument
			n = atoi(argv[++i]);
			break;
		
		case 's':
			//FIXME validate argument
			s = atoi(argv[++i]);
			break;
		
		case 'r':
			//FIXME validate argument
			r = atoi(argv[++i]);
			break;
		
		default:
			cerr << argv[0] << ": Unknown parameter \'" << argv[i] << "\'.\n";
			cerr << "Try running \'" << argv[0] << " -h\' for help.\n";
			return 1;
		
		case 'h':
			usage(argv[0]);
			return 0;
		}
	}
	
	
	
	/* Range validation */
	if (s < r) {
		cerr << argv[0] << ": Number of systems must be greater than number of effective systems.\n";
		return 1;
	}
	if (s < 5) {
		cerr << argv[0] << ": At least 5 systems required by statement condition.\n";
		return 1;
	}
	if (r > n) {
		cerr << argv[0] << ": Warning: changing r=" << r << " to " << n << " (n=" << n << ").\n";
		r = n;
	}
	
	
	
	/* Random seed */
	
	typedef chrono::high_resolution_clock clock;
	clock::time_point tp = clock::now();
	gen.seed(tp.time_since_epoch().count());
	
	
	
	/* Generate event frequencies (for effective systems) */
	
	vector<int> freq(r, 1);
	
	{
		double rnd;
		normal_distribution<double> normd(r / 2.0, r / 6.0);
		for (int i = 0; i < n-r; i++) {
			do {
				rnd = normd(gen);
			} while (rnd >= r || rnd < 0);
			freq[(int)rnd]++;
		}
	}
	
	
	
	/* Permutate event frequencies */
	
	for (int i = 0; i < r; i++) {
		uniform_int_distribution<int> unif(i, r-1);
		swap(freq, i, unif(gen));
	}
	
	
	
	/* Generate (ordered) effective system ids */
	
	set<int> sysn;
	
	{
		int rnd;
		uniform_int_distribution<int> unif(1, s);
		for (int i = 0; i < r; i++) {
			while (sysn.find(rnd = unif(gen)) != sysn.end());
			sysn.insert(rnd);
		}
	}
	
	
	
	/* Event list generation (ordered by id) */
	
	vector<int> events;
	events.reserve(n);
	int a = 0;
	
	for (auto it = sysn.begin(); it != sysn.end(); it++) {
		for (int i = 0; i < freq[a]; i++) {
			events.push_back(*it);
		}
		a++;
	}
	
	
	
	/* Event list permutation */
	
	for (int i = 0; i < n; i++) {
		uniform_int_distribution<int> unif(i, n-1);
		swap(events, i, unif(gen));
	}
	
	
	
	/* Output */
	
	cout << n << " " << s << endl;
	for (int i = 0; i < n; i++) {
		cout << events[i] << endl;
	}
	
	return 0;
}

void rand_permutation(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		uniform_int_distribution<int> unif(i, v.size()-1);
		swap(v, i, unif(gen));
	}
}

void swap(vector<int>& v, int i, int j) {
	if (i == j) return;
	v[i] ^= v[j];
	v[j] ^= v[i];
	v[i] ^= v[j];
	return;
}

void usage(char *fname) {
	string bd = "\033[1m";
	string nm = "\033[0m";
	string ul = "\033[4m";
	
	cout << "Usage: " + bd + fname + nm;
	cout << " [" + bd + "-n " + nm + ul + "nevents" + nm + "]";
	cout << " [" + bd + "-s " + nm + ul + "nsystems" + nm + "]";
	cout << " [" + bd + "-r " + nm + ul + "effective" + nm + "]\n";
	cout << "Generate input to standard output for OCI 2015 problem \'C - interestelar\'.\n";
	cout << "\n";
	cout << "  " + bd + "-n " + nm + ul + "nevents" + nm + "        sets number of events captured by BVET (5 by default).\n";
	cout << "  " + bd + "-s " + nm + ul + "nsystems" + nm + "       sets number of systems tracked by BVET (5 by default).\n";
	cout << "  " + bd + "-r " + nm + ul + "effective" + nm + "      sets number of systems present in event list (5 by default).\n";
	cout << "\n";
}