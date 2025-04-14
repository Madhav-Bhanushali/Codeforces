#include <bits\stdc++.h>
using namespace std;
const int m=1e9+7;

int main(){
long long int a,b,c,d;
cin>>a>>b>>c;

long long int s[]={a,b,b-a,-a,-b,-b+a};
cout<<(s[c%6-1]+m)%m;

    return 0;
}

