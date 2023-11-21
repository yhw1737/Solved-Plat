#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>a[4];
    a[0].push_back(-1000000001);
    a[1].push_back(-1);
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        a[2].push_back(t);
        int it=lower_bound(a[0].begin(),a[0].end(),t)-a[0].begin();
        if (it==a[0].size()){
            a[0].push_back(t);
            a[1].push_back(i);
        }
        else {
            a[0][it]=t;
            a[1][it]=i;
        }
        a[3].push_back(a[1][it-1]);
    }
    cout<<a[0].size()-1<<'\n';
    vector<int>T;
    int e=a[3][a[1].back()];
    T.push_back(a[0].back());
    while(e!=-1){
        T.push_back(a[2][e]);
        e=a[3][e];
    }
    while(T.size()>0){
        cout<<T.back()<<' ';
        T.pop_back();
    }
}