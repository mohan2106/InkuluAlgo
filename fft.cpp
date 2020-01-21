#include<bits/stdc++.h>
#include<complex>
using namespace std;

const double PI = acos(-1);

using cd = complex<double>;
void fft(vector<cd> &arr,bool inevrt){
    int n = arr.size();
    if(n==1) return;
    vector<cd> a0(n/2),a1(n/2);
    for(int i=0;2*i < n;i++){
        a0[i] = arr[i*2];
        a1[i] = arr[2*i + 1];
    }
    fft(a0,inevrt);
    fft(a1,inevrt);

    double ang = (2*PI/n)*((inevrt)?-1:1);
    cd w(1),wn(cos(ang),sin(ang));
    for(int i=0; 2*i <n ; i++){
        arr[i] = a0[i] + w*a1[i];
        arr[i + n/2] = a0[i] - w*a1[i];
        if(inevrt){
            arr[i] /= 2;
            arr[i+ n/2] /= 2;
        }
        w*=wn;
    }
}
vector<int> multiply(vector<int> &A, vector<int> &B){
    vector<cd> fa(A.begin(),A.end()),fb(B.begin(),B.end());
    int n=1;
    while(n < A.size() + B.size()){
        n<<=1;
    }
    // n<<=1;

    fa.resize(n);
    fb.resize(n);
    fft(fa,false);
    fft(fb,false);
    for(int i=0;i<n;i++){
        fa[i] *= fb[i];
    }
    fft(fa,true); //inverse fft for calculating c;
    vector<int> result(n);
    for(int i=0;i<n;i++){
        result[i] = round(fa[i].real());
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> temp(2*n -1);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    for(int i=0;i< (2*n -1);i++){
        
    }
    vector<int> result = multiply(A,B);
    for(int i=0;i<(2*n -1);i++){
        cout<<result[i]<<" ";
    }

    return 0;
}