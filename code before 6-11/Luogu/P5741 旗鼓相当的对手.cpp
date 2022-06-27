#include <iostream>
#include <cmath>
using namespace std;
struct student{
	char name[10];
	int eng=0,
	math=0,
	chi=0;
}stu[1005];
bool check(student a,student b){
	if(abs(a.chi-b.chi)<=5&&abs(a.eng-b.eng)<=5&&abs(a.math-b.math)<=5&&abs(a.chi+a.eng+a.math-b.chi-b.eng-b.math)<=10){
		return 1;
	}
	return 0;
}
int n;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> stu[i].name >> stu[i].chi >> stu[i].eng >> stu[i].math;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++) if(check(stu[i],stu[j])) cout << stu[i].name <<" "<< stu[j].name<<endl;
	}
	return 0;
}
