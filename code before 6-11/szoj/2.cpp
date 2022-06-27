#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T>
inline void debug(const char *format, T t){
	cout << '=' << first << "\n";
}

template <class F, class... R>
inline void debug(const char *format, F f, R r){
	while(*format != ',') cout << *format++;
	cout << '=' << f << ",";
	debug(format + 1, rest...);
}
