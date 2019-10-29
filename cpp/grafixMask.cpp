//https://community.topcoder.com/tc?module=ProblemDetail&rd=5857&pm=2998

#include "bits/stdc++.h"
#include <sstream> 

using namespace std;

int pic[400][600];

class node {public: int x,y;}

int doFill(int x,int y) {
	int result = 0;
	stack<node> s;
	s.push(node(x,y));
	while(s.empty()==false) {
		node top=s.top();
		s.pop();
		if(top.x<0 || top.x>=400) continue;
		if(top.y<0 || top.y>=600) continue;
		if(pic[top.x][top.y]==1) continue;
		pic[top.x][top.y]=1;
		result++;
		s.push(node(top.x+1,top.y));
		s.push(node(top.x-1,top.y));
		s.push(node(top.x,top.y+1));
		s.push(node(top.x,top.y-1));
	}
	return result;
}

class grafixMask {
public:
	vector <int> sortedAreas(vector <string> rectangles) {
		for(int y=0;y<400;y++)
			for(int x=0;x<600;x++)
				pic[y][x]=0;
		for(int i=0;i<rectangles.size();i++) {
			istringstream ss(rectangles[i]);
			int x1,y1,x2,y2;
			ss >> y1 >> x1 >> y2 >> x2;
			for(int y=y1;y<=y2;y++)
				for(int x=x1;x<=x2;x++)
					pic[y][x]=1;
		}
		vector <int> result;
		for(int x=0;x<400;x++)
			for(int y=0;y<600;y++) {
				if(pic[x][y]==0)
					result.push_back(doFill(x,y));
			}
			sort(result.begin(),result.end(),greater<int>());
			return result;
	}
}
