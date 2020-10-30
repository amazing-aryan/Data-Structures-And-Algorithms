#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
	int size;
	vector<int> table;

	BIT(int size) {
		table.resize(size+1);
		this->size = size;
	}

	void update(int i, int delta) {
		while(i<=size) {
			table[i] += delta;
			i += (i & -i);
		}
	}

// reading a single value
	int readSingle(int i) { 
		int sum = table[i];
		if(i>0) {
			int z = i - (i & -i);
			i--;
			while(i!=z) {
				sum -= table[i];
				i -= (i & -i);
			}
		}
		return sum;
	}

// get sum till given index
	int sum(int i) {
		int sum = 0;
		while(i>0) {
			sum += table[i];
			i -= (i & -i);
		}
		return sum;
	}

// get sum between a given range
	int rangeSum(int i, int j) {
		return sum(j) - sum(i-1);
	}

// scale all values by a constant
	void scale(int c) {
		for(int i=1;i<=size;i++) {
			table[i] = table[i]*c;
		}
	}
};