#include <cstdio>
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
	
	int n = 1, s = 1, r = 1;
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] != '-') {
			fprintf(stderr, "%s: Unknown parameter '%s'.\n", argv[0], argv[i]);
			fprintf(stderr, "Try running \'%s -h\' for help", argv[0]);
			return 1;
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
			fprintf(stderr, "%s: Unknown parameter '%s'.\n", argv[0], argv[i]);
			fprintf(stderr, "Try running \'%s -h\' for help.\n", argv[0]);
			return 1;
		
		case 'h':
			usage(argv[0]);
			return 0;
		}
	}
	
	
	
	/* Range validation */
	if (s < r) {
		fprintf(stderr, "%s: Number of systems must be greater than number of effective systems.\n", argv[0]);
		return 1;
	}
	if (s < 5) {
		fprintf(stderr, "%s: We need at least 5 systems.\n", argv[0]);
		return 1;
	}
	if (r > n) {
		fprintf(stderr, "%s: Warning: changing r=%d to %d (n=%d).\n", argv[0], r, n, n);
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
	
	printf("%d %d\n", n, s);
	for (int i = 0; i < n; i++) {
		printf("%d\n", events[i]);
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
	system("echo \"Usage:\"");
	system("echo \"generator [-n $(tput bold)nevents$(tput sgr0)] [-s $(tput bold)nsystems$(tput sgr0)] [-r $(tput bold)effsystems$(tput sgr0)]\"");
	system("echo");
	system("echo \"$(tput bold)nevents$(tput sgr0):\tNumber of events captured by BVET.\"");
	system("echo \"$(tput bold)nsystems$(tput sgr0):\tNumber of systems tracked by BVET.\"");
	system("echo \"$(tput bold)effsystems$(tput sgr0):\tNumber of systems with an event captured by BVET.\"");
}