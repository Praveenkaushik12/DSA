#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int>vec;
public:
    void push(int val){ //O(log n)
        //step1-Insert
        vec.push_back(val);

        //step2--fix heap
        int x=vec.size()-1;
        int partInd=(x-1)/2;

        while(partInd>=0 && vec[x]>vec[partInd]){
            swap(vec[x],vec[partInd]);
            x=partInd;
            partInd=(x-1)/2;
        }

    }
     
    void heapify(int i){

        if(i>=vec.size()){
            return;
        }

        int l=2*i+1;
        int r=2*i+2;

        int maxInd=i;
        if(l<vec.size() && vec[l] > vec[maxInd]){
            maxInd=l;
        }

        if(r<vec.size() && vec[r] > vec[maxInd]){
            maxInd=r;
        }

        swap(vec[i],vec[maxInd]);

        if(maxInd!=i){
            heapify(maxInd);
        } 
    }

    void pop(){
        //step1-swap with the last element
        swap(vec[0],vec[vec.size()-1]);

        //step2- delete last element
        vec.pop_back();

        //step3- fix heap
        heapify(0);


    }

    int top(){
        return vec[0];

    }

    bool empty(){
        return vec.size()==0;
    }

 
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(100);
    heap.push(10);

    cout<<heap.top()<<endl;

    heap.pop();

    cout<<heap.top();


    return 0;
}