#include<bits/stdc++.h>
using namespace std;


void solve(int n, int sour, int help, int dest)  {
        if(n==1) {
           cout << "move disk " << n << " from rod " << sour << " to rod " << dest << endl;
           return;
       }
       solve(n-1,sour,dest,help);
       cout << "move disk " << n << " from rod " << sour << " to rod " << dest << endl;
       solve(n-1,help,sour,dest);
    }
    long long toh(int n, int from, int to, int aux) {
        solve(n,from,aux,to);
        return pow(2,n) - 1;
    }