#include<bits/stdc++.h>
using namespace std;

vector<int> inter(int a[],int b[],int n1,int n2){
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;

}
void print(std::vector<int> const &input)
{
    for (auto it = input.cbegin(); it != input.cend(); it++) {
        std::cout << *it << ' ';
    }
}


 int main(){
    int n1,n2,answer;
    cin>>n1>>n2;
    int a[n1],b[n2];
    cout<<"Enter the sorted arr1:"<<endl;
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    cout<<"Enter the sorted arr2:"<<endl;
    for(int j=0;j<n2;j++){
        cin>>b[j];
    }

   vector<int> result = inter(a, b, n1, n2);
   print(result);

    // cout << "Intersection of the two arrays: ";
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    return 0;

}


