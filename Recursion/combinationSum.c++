#include<bits/stdc++.h>
using namespace std;


void combinationsum(vector<int> ds,int arr[],int n,int i,int s){
   if(i==n){
    if(s==0){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<endl;
    }
   }
  
  if(s>=arr[i]) {
     ds.push_back(arr[i]);
    combinationsum(ds,arr,n,i,s-arr[i]);
    ds.pop_back();
  }

  combinationsum(ds,arr,n,i+1,s);

   
}

int  main(){
    int arr[]={2,3,6,7};
    int k=7;
    int n=4;
    vector<int> ds;
    combinationsum(ds,arr,n,0,k);

}