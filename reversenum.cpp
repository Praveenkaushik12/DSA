#include <bits\stdc++.h>

using namespace std;

int main()
// {
//     int num,count=0;
//     int r=0,rem=0;
//     cin>>num;
//     count = (int)(log10(num)+1);
//     while(num>0){
//         r=num%10;
//         rem=r*pow(10,count-1)+rem;
//         count--;
//         num=num/10;
//     }
//     cout<<rem;

//     return 0;
// }

{
    int num;
    int rem=0,ld;
    cin>>num;
    while(num>0){
        ld=num%10;
        rem=rem*10+ld;
        num=num/10;
    }
    cout<<rem;

    return 0;
}