#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
struct coww{
	string name;
	int age;
	int year_born;
}cow[101];
int n;
string a[13]={"","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig","Rat"};
int get_num(string s){
	for(int i=1;i<=12;i++) if(a[i]==s) return i;
}
void get(int num){
	string cow1,cow2,year,f,born,in,year2,from;//-1:previous,1:next;
	cin >> cow1 >> born >> in >> f >> year >> year2 >> from >> cow2;
	//if(num==2) cout << (cow2==cow[1].name)<< endl;
	short fl;
	if(f=="previous") fl=-1;
	else fl=1;
	//cout << fl << endl;
	cow[num].name=cow1;
	cow[num].year_born=get_num(year);
	for(int i=1;i<num;i++){
		if(cow[i].name==cow2){
			//cout << i;
			int num2=get_num(year);
			if(fl==-1){
				int time=cow[i].year_born-num2;
				if(time<=0) time+=12;
				cow[num].age=cow[i].age-time;
			}
			else{
				int time=num2-cow[i].year_born;
				if(time<=0) time+=12;
				cow[num].age=cow[i].age+time;
			}
			break;
		}
	}
}
int main(){
	cin >> n;
	cow[1].name="Bessie";
	cow[1].age=0;
	cow[1].year_born=1;
	for(int i=2;i<=n+1;i++) get(i);
	//for(int i=1;i<=n+1;i++) cout << cow[i].name << " " << cow[i].age << " " << cow[i].year_born << endl;
	for(int i=1;i<=n;i++) if(cow[i].name=="Elsie") cout<<abs(cow[i].age);
	return 0;
}
