#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
};

#define UP 1
#define DOWN 2 
#define RIGHT 3

unordered_map<string,unordered_map<int,vector<Point>>> getCoordsTable(vector<Point> coords){
	unordered_map<string,unordered_map<int,vector<Point>>> coordsTable({
		{"x",unordered_map<int,vector<Point>>{}},
		{"y",unordered_map<int,vector<Point>>{}}
	});
	for(auto coord:coords) {
		if(coordsTable["x"].find(coord.x)==coordsTable["x"].end())
			coordsTable["x"].insert({coord.x,vector<Point>{}});
		if(coordsTable["y"].find(coord.y)==coordsTable["y"].end())
			coordsTable["y"].insert({coord.y,vector<Point>{}});
		coordsTable["x"][coord.x].push_back(coord);
		coordsTable["y"][coord.y].push_back(coord);
	}
	return coordsTable;
}

int clockwiseCountRectangle(Point coord,unordered_map<string,unordered_map<int,vector<Point>>> coordsTable,int direction,Point origin) {
	if(direction==DOWN) {
		for(auto coord2:coordsTable["x"][coord.x])
			if(coord2.y==origin.y)
				return 1;
		return 0;
	} else {
		int rectangleCount=0;
		if(direction==UP){
			for(auto coord2:coordsTable["x"][coord.x])
				if(coord2.y>coord.y)
					rectangleCount+=clockwiseCountRectangle(coord2,coordsTable,RIGHT,origin);
		} else if(direction==RIGHT) {
			for(auto coord2:coordsTable["y"][coord.y])
				if(coord2.x>coord.x)
					rectangleCount+=clockwiseCountRectangle(coord2,coordsTable,DOWN,origin);
		}
		return rectangleCount;
	}
	
}

int getRectangleCount(unordered_map<string,unordered_map<int,vector<Point>>> coordsTable,vector<Point> coords) {
	int rectangleCount=0;
	for(auto coord:coords)
		rectangleCount+=clockwiseCountRectangle(coord,coordsTable,UP,coord);
	return rectangleCount;
}

int rectangleMania(vector<Point> coords) {
  unordered_map<string,unordered_map<int,vector<Point>>> coordsTable = getCoordsTable(coords);
	int rectangleCount = getRectangleCount(coordsTable,coords);
  return rectangleCount;
}
