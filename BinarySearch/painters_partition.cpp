#include <bits/stdc++.h>
using namespace std;


#define int long long 

int n,x;
int arr[100000];

signed  check(int mid){
    //we assume w ehave no one to paint wall right now so no time also so both are set to zero 

      int last_painter_time_left=0;
      int number_of_painter_used=0;

      //then we go to 1st walll
      for(int i=0;i<n;i++){
        // at start this is false as zero tha so we then call one painter from else statement 
        if(last_painter_time_left>=arr[i]){
            last_painter_time_left-=arr[i];
        }
        else{
            number_of_painter_used++;
            if(number_of_painter_used>x){
                return 0;
            }
            //we give mid time to a painter always 
            last_painter_time_left=mid;
            if(last_painter_time_left>=arr[i]){
                last_painter_time_left-=arr[i];
        }else{
            return 0;
        }
      }
    }
      return 1;
}

signed  sum(int arr[], int n){
    int sum = 0; // initialize sum

    // Iterate through all elements
    // and add them to sum
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}




signed  main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<"no of painters:"<<endl;
    cin>>x;
    int l=0;
    int h=sum(arr,n);
    int ans=0;
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

