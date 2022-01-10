#include<iostream>
#include<map>
#include<set>
#include<queue>
using namespace std;

void report(multimap<set<int>, int>& GBIC) {
	set<int> id;
	int gd;
	while (true) {
		int n; cin >> n;
		if (n < 0) {
			gd = n; break; 
		}
		else if (n > 0) {
			id.insert(n);
		}
	}
	GBIC.insert(make_pair(id, gd));
}

void query(const multimap<set<int>, int>& GBIC) {
	set<int> id;
	while (true) {
		int n; cin >> n;
		if (n == 0) {
			break;
		}
		id.insert(n);
	}

	set<int, greater<int>> gds;
	if (GBIC.count(id) != 0 ) {
		for (multimap<set<int>, int> ::const_iterator it = GBIC.equal_range(id).first; it != GBIC.equal_range(id).second; it++) {
			gds.insert(it->second);
		}
		for (int gd : gds) {
			cout << gd << " ";
		}
	}
	else {
		cout << "None";
	}
	cout << endl;
}

int main(void) {
	multimap<set<int>, int> GBIC;

	while (true) {
		char mode;
		cin >> mode;
		if (mode == '$') break;

		switch (mode) {
		case 'R':
			report(GBIC);
			break;
		case 'Q':
			query(GBIC);
			break;
		}
	}
	return 0;
}