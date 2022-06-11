#include <bits/stdc++.h>
using namespace std;
int _max;
int love[4][3] = {{0, 4, 30}, {0, 7, 22}, {0, 1, 4}, {0, 37, 45}}, x;
string name[4][2] = {{"戴天悦", "王艺萱"}, {"葛璎漫", "彭飞扬"}, {"蔡子坤", "陈子涵"}, {"杨奕辰", "周婉茗"}};
int main()
{
	srand(time(0));
	cin >> _max;
	for (int i = 1; i <= _max; i++)
	{
		x = rand() % 4;
		if (love[x][1] < 10) cout << "0" << love[x][1] << " = ";
		else cout << love[x][1] << " = ";
		if (love[x][2] < 10) cout << "0" << love[x][2] << "!" << endl;
		else cout << love[x][2] << "!" << endl;
		love[x][0]++; 
	}
	cout << endl;
	double MAX = -1;
	int _MAX[4] = {}; 
	for (int i = 0; i < 4; i++)
	{
		cout << name[i][0] << "与" << name[i][1] << "的爱情占比为";
		if (100.0 * love[i][0] / _max >= 10) 
			cout << fixed << setprecision(48) << 100.0 * love[i][0] / _max << "%" << endl;
		else cout << "0" <<  fixed << setprecision(48) << 100.0 * love[i][0] / _max << "%" << endl;
		if (100.0 * love[i][0] / _max > MAX)
		{
			MAX = 100.0 * love[i][0] / _max;
			for (int j = 0; j < 4; j++)
				if (j != i) _MAX[j] = 0;
				else _MAX[j] = 114514;
		}
		else if (100.0 * love[i][0] / _max == MAX) _MAX[i] = 114514;
	}
	cout << endl << "事实证明：" << endl;
	for (int i = 0; i < 4; i++)
		if (_MAX[i] == 114514) cout << name[i][0] << "与" << name[i][1] << endl;
	cout << "的爱情最为深刻！";
	return 0;
}
