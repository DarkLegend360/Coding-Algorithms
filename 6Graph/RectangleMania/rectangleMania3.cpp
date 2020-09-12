#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x;
  int y;
};

string stringify(Point coord) {
	return to_string(coord.x)+"x"+to_string(coord.y);
}

unordered_set<string> getCoordsTable(vector<Point> coords) {
	unordered_set<string> coordsTable;
	for(auto coord:coords)
		coordsTable.insert(stringify(coord));
	return coordsTable;
}

int getRectangleCount(vector<Point> coords,unordered_set<string> coordsTable) {
	int rectangleCount=0;
	for(auto coord1:coords) {
		for(auto coord2:coords) {
			if(coord2.x > coord1.x && coord2.y>coord1.y) {
				string upperLeft = stringify(Point({coord1.x,coord2.y}));
				string lowerRight = stringify(Point({coord2.x,coord1.y}));
				if(coordsTable.find(upperLeft)!=coordsTable.end() && coordsTable.find(lowerRight)!=coordsTable.end())
					rectangleCount++;
			}
		}
	}
	return rectangleCount;
}

int rectangleMania(vector<Point> coords) {
  unordered_set<string> coordsTable = getCoordsTable(coords);
	int rectangleCount = getRectangleCount(coords,coordsTable);
  return rectangleCount;
}
