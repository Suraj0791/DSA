#include <bits/stdc++.h>
using namespace std;


//lower_bound
//for upeerbound just do  if(arr[mid]>x) return 1;

int n,x;
int arr[10000000];

int check(int mid){
    if(arr[mid]>=x) return 1;
    else return 0;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>x;
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