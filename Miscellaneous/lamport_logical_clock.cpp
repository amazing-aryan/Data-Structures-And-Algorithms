#include<bits/stdc++.h>
using namespace std;
#define mp make_pair

void update_sequence(map<pair<int, int>, int> & Clock)
{
  for(auto & C : Clock)
  {
    if(C.first.second - 1 > 0)
    {
      C.second = max(C.second, Clock[mp(C.first.first, C.first.second-1)] + 1);
    }
  }
}

int main()
{
  int n;
  cout << "Enter Number Of Processes\n";
  cin >> n;

  map<pair<int, int>, int> Clock;
  for(int i=1; i<=n; i++)
  {
    int x;
    cout << "Enter Number Of Events In Process " << i << endl;
    cin >> x;

    for(int j=1; j<=x; j++)
    {
      Clock[mp(i, j)] = j;
    }
  }

  int events = 0;
  cout << "Enter Number Of Events Occured \n";
  cin >> events;

  cout << "Enter Event As Sending-Process Event Receiving-Process Event  \n";

  map<pair<int,int>, vector<pair<int,int>> > E_Vec;
  for(int i=1; i<=events; i++)
  {
    int p1,e1,p2,e2;
    cin >> p1 >> e1 >> p2 >> e2;
    E_Vec[mp(p1,e1)].push_back(mp(p2,e2));
  }

  for(auto & E : E_Vec)
  {
    sort(E.second.begin(), E.second.end());
  }

  for(auto & E : E_Vec)
  {
    for(auto p : E.second)
    {
      int p1,e1,p2,e2;
      p1 = E.first.first;
      e1 = E.first.second;
      p2 = p.first;
      e2 = p.second;
      
      Clock[mp(p2, e2)] = max(Clock[mp(p2, e2)], Clock[mp(p1, e1)] + 1);
      update_sequence(Clock);
    }
  }

  for(auto & C : Clock)
  {
    pair<int, int> p = C.first;
    int time = C.second;
    cout << "Process : " << p.first << " Event : " << p.second << " Time : " << time << endl;
  }

  return 0;
}