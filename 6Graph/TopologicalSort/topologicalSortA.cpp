#include<bits/stdc++.h>
using namespace std;

class JobNode {
    public:
    int job;
    vector<JobNode *> preReq;
    bool visited;
    bool isVisiting;
    JobNode(int job) {
        this->job=job;
        this->preReq={};
        this->visited = false;
        this->isVisiting = false;
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
    void addPreReq(int preReq,int job) {
        JobNode *jobNode = getNode(job);
        JobNode *preReqNode = getNode(preReq);
        jobNode->preReq.push_back(preReqNode);
    }
    JobNode *getNode(int job) {
        return graph[job];
    }
};

JobGraph *createJobGraph(vector<int> jobs,vector<vector<int>> deps) {
    JobGraph *graph = new JobGraph(jobs);
    for(auto dep : deps)
        graph->addPreReq(dep[0],dep[1]);
    return graph;
}

bool depthFirstSearch(JobNode *node,vector<int> &orderedJobs) {
    if(node->visited)
        return false;
    if(node->isVisiting)
        return true;
    node->isVisiting=true;
    for(auto preReqNode : node->preReq) {
        bool containsCycle = depthFirstSearch(preReqNode,orderedJobs);
        if(containsCycle)
            return true;
    }
    node->isVisiting=false;
    node->visited=true;
    orderedJobs.push_back(node->job);
    return false;
}

vector<int> getOrderedJobs(JobGraph *graph) {
    vector<int> orderedJobs;
    vector<JobNode *> nodes = graph->nodes;
    while(nodes.size()) {
        JobNode *node = nodes.back();
        nodes.pop_back();
        bool containsCycle = depthFirstSearch(node,orderedJobs);
        if(containsCycle)
            return {};
    }
    return orderedJobs;
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