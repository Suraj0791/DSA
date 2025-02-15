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

//2nd approach wihtout for loop
void backtrack(int index, vector<int>& candidates, int target, vector<int>& currentCombination, vector<vector<int>>& result) {
    // Base cases
    if (target == 0) {  // Target achieved
        result.push_back(currentCombination);
        return;
    }
    if (index >= candidates.size() || target < 0) {  // Out of bounds or target < 0
        return;
    }

    // **Include the current candidate**
    currentCombination.push_back(candidates[index]);  // Add the candidate
    backtrack(index, candidates, target - candidates[index], currentCombination, result);  // Recurse with the same index
    currentCombination.pop_back();  // Backtrack (undo the addition)

    // **Exclude the current candidate and move to the next**
    backtrack(index + 1, candidates, target, currentCombination, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> currentCombination;
    backtrack(0, candidates, target, currentCombination, result);
    return result;
}
