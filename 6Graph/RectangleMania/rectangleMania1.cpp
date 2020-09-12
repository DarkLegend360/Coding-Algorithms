#include <bits/stdc++.h>
using namespace std;

#define NONE 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

struct Point {
  	int x;
  	int y;
	bool operator==(Point p) { return x == p.x && y==p.y;}
};

string stringifyCoords(Point a) {
	return to_string(a.x)+"x"+to_string(a.y);
}

int getCoordDirection(Point a,Point b) {
	if(a.x==b.x) {
		if(a.y<b.y) {
			return UP;
		} else if(a.y>b.y) {
			return DOWN;
		}
	}
	else if(a.y==b.y){
		
		if(a.x<b.x) {
			return RIGHT;
		} else if(a.x>b.x) {
			return LEFT;
		}
	}
	return 0;
}

unordered_map<string,unordered_map<int,vector<Point>>> getCoordsTable(vector<Point> coords) {
	unordered_map<string,unordered_map<int,vector<Point>>> coordTable;
	for(auto coord1:coords) {
		unordered_map<int,vector<Point>> coord1Direction({
			{UP,vector<Point>{}},
			{LEFT,vector<Point>{}},
			{RIGHT,vector<Point>{}},
			{DOWN,vector<Point>{}}
		});
		for(auto coord2:coords) {
			int coord2Direction = getCoordDirection(coord1,coord2);
			if(coord1Direction.find(coord2Direction)!=coord1Direction.end()){
				coord1Direction[coord2Direction].push_back(coord2);
			}
		}
		coordTable[stringifyCoords(coord1)]=coord1Direction;
	}
	return coordTable;
}

int nextDirection(int direction) {
	switch(direction) {
		case UP: return RIGHT;
		case RIGHT: return DOWN;
		case DOWN: return LEFT;
		default: return 0;
	}
}

int clockwiseCountRectangle(Point coord,unordered_map<string,
														 unordered_map<int,vector<Point>>> coordTable,int direction,Point origin) {
	string key = stringifyCoords(coord);
	if(direction==NONE) return 0;
	if(direction==LEFT) {
		bool rectangleFound = find(coordTable[key][LEFT].begin(),
						coordTable[key][LEFT].end(),origin)!=coordTable[key][LEFT].end();
		return rectangleFound?1:0;
	} else {
		int rectangleCount=0;
		for(auto nextCoord:coordTable[key][direction])
			rectangleCount+=clockwiseCountRectangle(nextCoord,coordTable,nextDirection(direction),origin);
		return rectangleCount;
	}
}

int getRectangleCount(vector<Point> coords,unordered_map<string,unordered_map<int,vector<Point>>> coordTable) {
	int rectangleCount=0;
	for(auto coord:coords)
		rectangleCount+=clockwiseCountRectangle(coord,coordTable,UP,coord);
	return rectangleCount;
}

int rectangleMania(vector<Point> coords) {
	unordered_map<string,unordered_map<int,vector<Point>>> coordsTable = getCoordsTable(coords);
	int rectangleCount = getRectangleCount(coords,coordsTable);
  return rectangleCount;
}