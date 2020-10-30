#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:

	int n;
	vector<int> lo;
	vector<int> hi;
	vector<int> min;
	vector<int> delta;

	SegmentTree(int n) {
		this.n = n;
		lo.resize(4*n+1);
		hi.resize(4*n+1);
		min.resize(4*n+1);
		delta.resize(4*n+1);

		init(1, 0, n-1);
	}

	void increment(int a, int b, int val) {
		increment(1, a, b, val);
	}

	int minimum(int a, int b) {
		minimum(1, a, b);
	}

	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		
		if( a == b) return;

		int m = (a+b)/2;
		init(2*i, a, m);
		init(2*i+1, m+1, b);

		update(i);
	}

	void prop(int i) {
		delta[2*i] += delta[i];
		delta[2*i+1] += delta[i];
		delta[i] = 0;
	}

	void update(int i) {
		min[i] = min(min[2*i] + delta[2*i], min[2*i+1] + delta[2*i+1]);
	}

	void increment(int i, int a, int b, int val) {
		if(b < lo[i] || hi[i] < a) return;

		if(a <= lo[i] && hi[i] <= b) {
			delta[i] += val;
			return;
		}

		prop(i);

		increment(2*i, a, b, val);
		increment(2*i+1, a, b, val);

		update(i);
	}

	void minimum(int i, int a, int b) {
		if(b < lo[i] || hi[i] < a) return INT_MAX;
		
		if(a <= lo[i] && hi[i] <= b) return min[i] + delta[i];

		prop(i);

		int minLeft = minimum(2*i, a, b);
		int minRight = minimum(2*i+1, a, b);

		update(i);

		return min(minLeft, minRight);	
	}

}