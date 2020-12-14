///        Saniuzzaman Robin           ///
///        CSE'08, Comilla University  ///

#include<bits/stdc++.h>
using namespace std;

const int sz = 100007;
int a[sz], tree[4*sz];

void build(int index, int l, int r)
{
    if(l>r)                    ///invalid segment
        return;
    if(l==r)
    {
        tree[index] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(2*index, l, m);                        ///2*index stands for left child, 2*index+1 stands for right child
    build(2*index+1, m+1, r);
    tree[index] = tree[2*index] + tree[2*index+1];
    return;
}

void update(int index, int l, int r, int pos, int val)
{
    if(pos<l or pos>r)          ///target pos doesn't lie inside the current segment
        return;
    if(l==r)                   ///exact position for the point update
    {
        tree[index] = val;
        return;
    }
    int m = (l+r)/2;
    update(2*index, l, m, pos, val);
    update(2*index+1, m+1, r, pos, val);
    tree[index] = tree[2*index] + tree[2*index+1];
    return;
}

int query(int index, int l, int r, int qs, int qe)
{
    if(qs>r or qe<l)                 ///segment outside of query range
        return 0;

    if(l>=qs and r<=qe)              /// segment completely in query range
        return tree[index];

    int m = (l+r)/2;
    int lans = query(2*index, l, m, qs, qe);
    int rans = query(2*index+1, m+1, r, qs, qe);
    return lans+rans;
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        build(1, 0, n-1);
        int q
        cin>>q;
        while(q--)
        {
            int l, r;
            cin>>l>>r;
            cout<<query(1, 0, n-1, l-1, r-1)<<endl;         ///l-1 and r-1 as index of the array is 0 based, else query(1, 0, n-1, l, r)
        }
    }
    return 0;
}
