#include "map.h"

#include<iostream>
#include<map>

using namespace std;

void addMap(){
  map <float, float> mapXY;
  int n; //кол-во пар точек
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      float x, y;
      cin >> x; cin >> y;
      mapXY.insert(make_pair(x, y));

    }

}
