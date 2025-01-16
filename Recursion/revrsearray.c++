#include<bits/stdc++.h>
using namespace std;

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
//12345 54321 
//swap(i,)