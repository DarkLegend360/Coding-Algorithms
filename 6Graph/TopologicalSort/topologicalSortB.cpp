#include<bits/stdc++.h>
using namespace std;

class JobNode {
    public:
    int job;
    vector<JobNode *> deps;
    int noOfPreReqs;
    JobNode(int job) {
        this->job=job;
        this->deps={};
        noOfPreReqs=0;
    }
};

class JobGraph {
    public:
    vector<JobNode *> nodes;
    unordered_map<int,JobNode *> graph;
    JobGraph(vector<int> jobs) {
        nodes={};
        for(auto job: jobs)
            this->addNode(job);
    }
    void addNode(int job) {
        graph[job]=new JobNode(job);
        nodes.push_back(graph[job]);
    }
    void addDep(int job,int dep) {
        JobNode *jobNode = getNode(job);
        JobNode *depNode = getNode(dep);
        jobNode->deps.push_back(depNode);
        depNode->noOfPreReqs++;
    }
    JobNode *getNode(int job) {
        return graph[job];
    }
};

JobGraph *createJobGraph(vector<int> jobs,vector<vector<int>> deps) {
    JobGraph *graph = new JobGraph(jobs);
    for(auto dep : deps)
        graph->addDep(dep[0],dep[1]);
    return graph;
}

void removeDeps(JobNode *node, vector<JobNode *> &nodeswithNoPreReq) {
    while(node->deps.size()) {
        JobNode *dep = node->deps.back();
        node->deps.pop_back();
        dep->noOfPreReqs--;
        if(!dep->noOfPreReqs)
            nodeswithNoPreReq.push_back(dep);
    }
}

vector<int> getOrderedJobs(JobGraph *graph) {
    vector<int> orderedJobs;
    vector<JobNode *> nodes = graph->nodes;
    vector<JobNode *> nodesWithNoPreReq(nodes.size());
    auto it = copy_if(nodes.begin(),nodes.end(),nodesWithNoPreReq.begin(),[](JobNode *node){return node->noOfPreReqs==0;});
    nodesWithNoPreReq.resize(distance(nodesWithNoPreReq.begin(),it));

    while(nodesWithNoPreReq.size()) {
        JobNode *node = nodesWithNoPreReq.back();
        nodesWithNoPreReq.pop_back();
        orderedJobs.push_back(node->job);
        removeDeps(node ,nodesWithNoPreReq);
    }
    bool  graphHasEdges = false;
    for(auto *node : graph->nodes)
        if(node->noOfPreReqs)
            graphHasEdges=true;
    return graphHasEdges?vector<int>{}:orderedJobs;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
    JobGraph *graph = createJobGraph(jobs,deps);
    vector<int> orderedJobs = getOrderedJobs(graph);
    return orderedJobs;
}   

int main() {
    vector<int> jobs = {1, 2, 3, 4};
    vector<vector<int>> deps = {{1, 2}, {1, 3}, {3, 2}, {4, 2}, {4, 3}};
    vector<int> result = topologicalSort(jobs,deps);
    for(auto x: result)
        cout<<x<<endl;
    return 0;
}