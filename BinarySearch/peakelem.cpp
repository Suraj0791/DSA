#include <bits/stdc++.h>
using namespace std;


//peak elem;
//just check funcn changed rest all same 

int n,x;
int arr[10000000];

int check(int mid){
    //this is a edge case as mid+1 will go out of bound 
    if(mid==n-1) return 1;
    if(arr[mid]>arr[mid+1]) return 1;
    else return 0;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    int l=0;
    int h=n-1;
    int ans=n;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(check(mid)==1){
             ans=mid;
             h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}