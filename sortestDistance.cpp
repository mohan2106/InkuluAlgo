#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
typedef long long lli;
typedef long li;
typedef pair<int,int> PI;
typedef pair<long,int> PLI;
typedef pair<int,long> PIL;
typedef pair<long, long> PL;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef priority_queue<int> PQ;
typedef priority_queue<long> PQL;
typedef priority_queue<long long> PQLL;
#define FAST ios::sync_with_stdio(0)
#define forz(n) for (long i = 0; i < n; i++)
#define forv(i,x,y) for (long i=x; i<y; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define TRAV(it, v) for(auto it = v.begin(); it != v.end(); it++) 
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define SQ(a) (a)*(a)
#define UM unordered_map
#define US unordered_set
#define LB(v,x) lower_bound(v.begin(),v.end(),x);
#define UB(v,x) upper_bound(v.begin(),v.end(),x);
#define CUBE(a) (a)(a)(a)
#define SORT(v) sort(v.begin(),v.end());
#define SORTC(v,c) sort(v.begin(),v.end(),c);
#define Pi 3.14159265358979323846
#define doubleMax = 999999999.9999
bool comp1(PLL a,PLL b){
    return a.F < b.F;
}
bool comp2(PLL a,PLL b){
    return a.S < b.S;
}

double find_minDistance(vector<PLL> &arrx,vector<PLL> &arry,lli s,lli e){
    if(e-s <= 1){
        return (double)99999.999;
    }else if(e-s == 2){
        return sqrt(SQ(arrx[e-1].S - arrx[s].S) + SQ(arrx[e-1].F - arrx[s].F));
    }
    lli mid = (s+e)/2;
    double d1 = find_minDistance(arrx,arry,s,mid+1);
    double d2 = find_minDistance(arrx,arry,mid+1, e);
    double d = min(d1,d2);
    
    vector<PLL> SL,SR;
    forz(arry.size()){
        if(arry[i].F == arrx[mid].F && arry[i].S == arrx[mid].S){
            SL.PB(arry[i]);
            continue;
        }
        if(abs(arry[i].F - arrx[mid].F) <= d){
            if(arry[i].F < arrx[mid].F){
                SL.PB(arry[i]);
            }else{
                SR.PB(arry[i]);
            }
        }
    }
    lli j=0;
    forz(SL.size()){
        while(SR[j].S < SL[i].S + d){
            j++;
            if(j>=SR.size()){
                break;
            }
        }
        j--;
        while(SR[j].S > SL[i].S - d){
            double temp = sqrt(SQ(SR[j].S - SL[i].S) + SQ(SR[j].F - SL[i].F));
            d = min(d,temp);
            j--;
            if(j<0) break;
        }
    }
    return d;
    
}
 
int main(){
    FAST;
    cin.tie(0);
    cout.tie(0);
    lli n;
    cin>>n;
    vector<PLL> arrx(n),arry(n);
    lli x,y;
    forz(n){
        cin>>x>>y;
        arrx[i] = MP(x,y);
        arry[i] = MP(x,y);
    }
    
    SORTC(arrx,comp1);
    SORTC(arry,comp2);
    double d = find_minDistance(arrx,arry,0,n);
    cout<<d<<'\n';
    return 0;
}