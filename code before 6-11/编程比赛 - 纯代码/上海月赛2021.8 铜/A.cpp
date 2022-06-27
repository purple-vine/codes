#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int n;
string  a[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"},
		b[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
		c[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","DM"},
		d[10]={"","M","MM","MMM"};
int main(){
	cin >> n;
	cout << d[n/1000] << c[(n/100)%10] << b[(n/10)%10] << a[n%10];
}
