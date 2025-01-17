#include<bits/stdc++.h>
using namespace std;


//in any recursion problem , identify which task you have to do mainly like here we wanted to have a swap from recurison fucntion and then l++ r-- from calling recrusive fucntion . that was the main task .

void reverse(int a[],int n,int l,int r){
        cout<<"3"<<endl;

    if(l>=r) return ;
    else{
            cout<<"4"<<endl;

        swap(a[l],a[r]);
            cout<<"5"<<endl;

        reverse(a,n,l+1,r-1);
            cout<<"6"<<endl;

    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"1"<<endl;
    int l=0;
    int r=n-1;
    reverse(a,n,l,r);
        cout<<"2"<<endl;

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


//we can reduce the number of varibales 
// for i=0 we are swappig it with last index n-i-1 so overall f(i,n-i-1);