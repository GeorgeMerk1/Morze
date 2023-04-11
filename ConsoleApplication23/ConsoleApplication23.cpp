#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
struct bukva {
	int size;
	int* code;
};
bukva* Alfabet = new bukva[32]{
	{2,new int[2] {0,1}},//a
	{4, new int[4] {1,0,0,0}},//b
	{3, new int[3] {0,1,1} },
	{3,new int[3] {1,1,0}},
	{3,new int[3] {1,0,0}},
	{1, new int[1] {0}},
	{4,new int[4] {0,0,0,1}},
	{4,new int[4] {0,0,1,1}},
	{2,new int[2] {0,0} },
	{4,new int[4] {0,1,1,1}},
	{3,new int[3] {1,0,1}},
	{4,new int[4] {0,1,0,0}},
	{2,new int[2] {1,1}},
	{2,new int[2] {1,0}},
	{3,new int[3] {1,1,1}},
	{4,new int[4] {0,1,1,0}},
	{3,new int[3] {0,1,0}},
	{3, new int[3] {0,0,0}},
	{1,new int[1] {1}},
	{3,new int[3] {0,0,1}},
	{4,new int[4] {0,0,1}},
	{4,new int[4] {0,0,0,0}},
	{4,new int[4] {1,0,1,0}},
	{4,new int[4] {1,1,1,0}},
	{4,new int[4] {1,1,1,1}},
	{4, new int[4] {1,1,0,1}},
	{6,new int[6] {0,1,1,0,1,0}},
	{4,new int[4] {1,0,1,1}},
	{5,new int[5] {1,0,0,1}},
	{5,new int[5] {0,0,1,0,0}},
	{4,new int[4] {0,0,1,1}},
	{4,new int[4] {0,1,0,1}}
};


void playBukva(int i) {
	bukva b = Alfabet[i];
	for (int i = 0; i < b.size; i++) {
		int duration = b.code[i] == 0 ? 400 : 400 * 2;
		Beep(800, duration);
	}
}
string lofwersstring(string s) {
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		res += tolower(s[i]);
	}
	return res;
}
void playString(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i]==' '|| s[i]=='\n') {
			Sleep(300);
		}
		else if (-33 < s[i] && s[i] < 0) {
		playBukva(s[i] + 32);
		}
	}

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string s;
	cin >> s;
	cout << s << endl;
	s = lofwersstring(s);
	playString(s);
}