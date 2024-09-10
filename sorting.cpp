#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)
        {
            if (a[mini] > a[j])
            {
                mini = j;
            }
        }
        int temp = a[mini];
        a[mini] = a[i];
        a[i] = temp;
    }
}

void bubble_sort(int a[],int n){   
    for(int i=n-1;i>=1;i--){

        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            int temp= a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertion_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" ";
    }
    return 0;
}