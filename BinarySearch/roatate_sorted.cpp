#include <bits/stdc++.h>
using namespace std;


//number of time a array is roatated asked 
//its basically same as finding the index of minm elem , so we need ot covert the array given to 0 nd 1 such that minm elem se 1 ka range start ho
//we just need to change check funtion conditon rest all same a slower uppeer bound


int n,x;
int arr[1000];

int check(int mid){
    if(arr[mid]<arr[0]) return 1;
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
}