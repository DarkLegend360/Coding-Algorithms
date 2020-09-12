#include <bits/stdc++.h>
using namespace std;

class AirportNode {
	public:
		string airport;
		vector<string> connections;
		bool isReachable;
		vector<string> unreachableConnections;
		AirportNode(string airport) {
			this->airport = airport;
			isReachable=true;
		}
};

unordered_map<string,AirportNode *> createAirportGraph(vector<string> airports, vector<vector<string>> routes) {
	unordered_map<string,AirportNode *> airportGraph;
	for(auto airport:airports)
		airportGraph[airport] = new AirportNode(airport);
	for(auto route:routes)
		(airportGraph[route[0]])->connections.push_back(route[1]);
	return airportGraph;
}

void depthFirstSearch(unordered_map<string,AirportNode *> &airportGraph,string airport,unordered_map<string,bool> &visitedAirports) {
	if(visitedAirports.find(airport)!=visitedAirports.end())
			return;
	visitedAirports[airport]=true;
	for(auto connection:airportGraph[airport]->connections)
		depthFirstSearch(airportGraph,connection,visitedAirports);
}

vector<AirportNode *> getUnreachableAirportNodes(unordered_map<string,AirportNode *> &airportGraph,vector<string> airports,string startingAirport) {
	unordered_map<string,bool> visitedAirports;
	depthFirstSearch(airportGraph,startingAirport,visitedAirports);
	vector<AirportNode *> unreachableAirportNode;
	for(auto airport:airports) {
		if(visitedAirports.find(airport)!=visitedAirports.end())
			continue;
		airportGraph[airport]->isReachable = false;
		unreachableAirportNode.push_back(airportGraph[airport]);
	}
	return unreachableAirportNode;
}

void depthFirstSearch2(unordered_map<string,AirportNode *> &airportGraph,string airport,vector<string> &unreachableConnections,unordered_map<string,bool> &visitedAirports) {
	if(airportGraph[airport]->isReachable)
		return;
	if(visitedAirports.find(airport)!=visitedAirports.end())
		return;
	visitedAirports[airport]=true;
	unreachableConnections.push_back(airport);
	for(auto connection:airportGraph[airport]->connections)
		depthFirstSearch2(airportGraph,connection,unreachableConnections,visitedAirports);
}
void markUnreachableConnections(unordered_map<string,AirportNode *> &airportGraph , vector<AirportNode *> &unreachableAirportNodes) {
	for(auto airportNode:unreachableAirportNodes) {
		vector<string> unreachableConnections;
		unordered_map<string,bool> visitedAirports;
		depthFirstSearch2(airportGraph,airportNode->airport,unreachableConnections,visitedAirports);
		airportNode->unreachableConnections = unreachableConnections;
	}
}

bool comp(AirportNode *a , AirportNode *b) {
	return a->unreachableConnections.size() > b->unreachableConnections.size();
}

int getMinNumberOfNewConnections(unordered_map<string,AirportNode *> &airportGraph,vector<AirportNode *> &unreachableAirportNodes) {
	sort(unreachableAirportNodes.begin(),unreachableAirportNodes.end(),comp);
	int numberOfNewConnections=0;
	for(auto airportNode : unreachableAirportNodes) {
		if(airportNode->isReachable)
			continue;
		numberOfNewConnections++;
		for(auto connection:airportNode->unreachableConnections)
			airportGraph[connection]->isReachable = true;
	}
	return numberOfNewConnections;
}

int airportConnections(vector<string> airports, vector<vector<string>> routes,string startingAirport) {
	unordered_map<string,AirportNode *> airportGraph = createAirportGraph(airports,routes);
	vector<AirportNode *> unreachableAirportNodes = getUnreachableAirportNodes(airportGraph,airports,startingAirport);
	markUnreachableConnections(airportGraph , unreachableAirportNodes);
	int minNumberOfNewConnections=getMinNumberOfNewConnections(airportGraph,unreachableAirportNodes);
	return minNumberOfNewConnections;
}

int main() {
    vector<string> airports = { "BGI","CDG","DEL","DOH","DSM","EWR","EYW","HND","ICN","JFK","LGA","LHR","ORD","SAN","SFO","SIN","TLV","BUD"};
    vector<vector<string>> routes = {
    {"DSM", "ORD"},
    {"ORD", "BGI"},
    {"BGI", "LGA"},
    {"SIN", "CDG"},
    {"CDG", "SIN"},
    {"CDG", "BUD"},
    {"DEL", "DOH"},
    {"DEL", "CDG"},
    {"TLV", "DEL"},
    {"EWR", "HND"},
    {"HND", "ICN"},
    {"HND", "JFK"},
    {"ICN", "JFK"},
    {"JFK", "LGA"},
    {"EYW", "LHR"},
    {"LHR", "SFO"},
    {"SFO", "SAN"},
    {"SFO", "DSM"},
    {"SAN", "EYW"}
    };
    string startingAirport = "LGA";
    cout<<airportConnections(airports,routes,startingAirport)<<endl;
}