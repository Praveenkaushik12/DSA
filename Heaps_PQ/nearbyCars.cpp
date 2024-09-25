#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Car{
public:
    int idx;
    int distsq;

    Car(int idx,int distsq){
        this->idx=idx;
        this->distsq=distsq;
    }

    bool operator < (const Car &obj) const{
        return this->distsq > obj.distsq;
    }

};

void nearbyCars(vector<pair<int,int>>pos,int k){
    vector<Car>cars;
    
    //step1
    for(int i=0;i<pos.size();i++){
        int distsq= pos[i].first * pos[i].first + pos[i].second * pos[i].second;
        cars.push_back(Car(i,distsq));
    }
   
    //step2
    priority_queue<Car>pq(cars.begin(),cars.end()); //O(n)

    //step3
    for(int i=0;i<k;i++){ //O(K *log n)
        cout<<"car"<<pq.top().idx<<endl;
        pq.pop(); //O(log n)
    }

}

int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));
    

    int K=2;

    nearbyCars(pos,K);
    

    return 0;
}