#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct student{
    char name[10];
    int a,b,c;
    int score;
}s[1005];
bool cmp(student i,student j){
    return i.score>j.score;
}
int n,a,b,c;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i].name >> s[i].a >> s[i].b >> s[i].c;
        s[i].score=s[i].a+s[i].b+s[i].c;
    }
    sort(s+1,s+n+1,cmp);
    printf("%s %d %d %d",s[1].name,s[1].a,s[1].b,s[1].c);
    return 0;
}
