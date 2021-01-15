#include <bits/stdc++.h>
using namespace std;

class OrgChart {
    public:
    char name;
    vector<OrgChart *> directReports;
    OrgChart(char name) {
        this->name = name;
        this->directReports = {};
    }
    void addDirectReports(vector<OrgChart *> directReports) {
        for (OrgChart *directReport : directReports)
            this->directReports.push_back(directReport);
    }
};

class OrgInfo {
    public:
    OrgChart *lowestCommonManager;
    int numOfImportantReports;
};

OrgInfo helper(OrgChart *manager, OrgChart *reportOne, OrgChart *reportTwo) {
    int noOfReports=0;
    for(auto report : manager->directReports) {
        OrgInfo orgInfo = helper(report, reportOne, reportTwo);
        if(orgInfo.lowestCommonManager)
            return orgInfo;
        noOfReports+=orgInfo.numOfImportantReports;
    }
    if(manager==reportOne || manager==reportTwo)
        noOfReports+=1;
    if(noOfReports==2)
        return OrgInfo({manager,noOfReports});
    return OrgInfo({NULL,noOfReports});
}

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne, OrgChart *reportTwo) {
    return helper(topManager, reportOne, reportTwo).lowestCommonManager;
}

unordered_map<char, OrgChart *> getOrgcharts() {
    unordered_map<char, OrgChart *> orgCharts;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char a : alphabet)
        orgCharts.insert({a, new OrgChart(a)});
    orgCharts.at('X')->addDirectReports({
        orgCharts.at('Z'),
    });
    return orgCharts;
}

int main() {
auto orgCharts = getOrgcharts();
    orgCharts.at('A')->addDirectReports(
        {orgCharts.at('B'), orgCharts.at('C')});
    orgCharts.at('B')->addDirectReports(
        {orgCharts.at('D'), orgCharts.at('E')});
    orgCharts.at('C')->addDirectReports(
        {orgCharts.at('F'), orgCharts.at('G')});
    orgCharts.at('D')->addDirectReports(
        {orgCharts.at('H'), orgCharts.at('I')});

    OrgChart *lcm = getLowestCommonManager(
        orgCharts.at('A'), orgCharts.at('E'), orgCharts.at('I'));
    cout<<(lcm == orgCharts.at('B'))<<endl;;
    return 0;
}