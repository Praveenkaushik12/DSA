#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    int index;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->index = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> Pair) {
    int n = Pair.size();
    vector<Job> jobs;

    for (int i = 0; i < n; i++) {
        jobs.emplace_back(i, Pair[i].first, Pair[i].second);
    }

    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    });

    int maxDeadline=0;
    for(const auto &job: jobs){
        maxDeadline=max(maxDeadline,job.deadline);
    }

    vector<int>time(maxDeadline+1,-1);
    int profit=0;
    int count=0;

    for(int i=0;i<n;i++){
        while(jobs[i].deadline>0){
            if(time[jobs[i].deadline]==-1){
                cout<<"Job"<<jobs[i].index<<endl;
                time[jobs[i].deadline]=jobs[i].index;
                profit+=jobs[i].profit;
                count++;
                break;
            }
            jobs[i].deadline--;
        }   
    }


    cout << "Max Profit: " << profit << endl;
    return profit;
}

int main() {
    vector<pair<int, int>> job = {{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};

    maxProfit(job);

    return 0;
}
