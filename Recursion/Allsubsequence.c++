#include<bits/stdc++.h>
using namespace std;



void printsub(int ind , vector<int> &ds,int arr[],int n){
   if(ind>=n) {
    for(auto it:ds){
        cout<<it<<" ";
    }
    if(ds.size()==0){
        cout<<"{ }";
    }
    cout<<endl;
    return;
   }
   ds.push_back(arr[ind]);
   printsub(ind+1,ds,arr,n);
   ds.pop_back();



}

int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int> ds;
    printsub(0,ds,arr,3);
    return 0 ;
}