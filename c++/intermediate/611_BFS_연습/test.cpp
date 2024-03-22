#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int ll;
ll S,T;
set <ll> s;
map <ll,pair<ll,char>> m;
queue <pair<ll,ll>> Q;
ll BFS(){
    Q.push({S,0});
    s.insert(S);
    while(!Q.empty()){
        auto[n,d]=Q.front();
        Q.pop();
        if(n>1e9)continue;
        if(n==T)return d;
        if(s.find(n*n)==s.end()){Q.push({n*n,d+1});s.insert(n*n);m[n*n]={n,'*'};}
        if(s.find(n*2)==s.end()){Q.push({n*2,d+1});s.insert(n*2);m[n*2]={n,'+'};}
        if(s.find(1)==s.end()){Q.push({1,d+1});s.insert(1);m[1]={n,'/'};}
    }
    return -1;
}
void track(int x){
    if(x==S){
        return;
    }
    track(m[x].first);
    printf("%c",m[x].second);
}
int main()
{
    scanf("%d%d",&S,&T);
    if(S==T)printf("0");
    else if(BFS()==-1)printf("-1");
    else track(T);
    //printf("%lld",BFS());
    printf("\n");
    return 0;
}
