#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int,int> jobScheduling(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for(auto job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slot(maxDeadline + 1, -1);

    int countJobs = 0, totalProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = jobs[i].id;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {countJobs, totalProfit};
}

int main() {
    vector<Job> jobs = {
        {1,2,100}, {2,1,19}, {3,2,27}, {4,1,25}, {5,3,15}
    };

    auto res = jobScheduling(jobs, jobs.size());

    cout << "Max Jobs: " << res.first << endl;
    cout << "Max Profit: " << res.second << endl;
}