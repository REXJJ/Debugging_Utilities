#include <bits/stdc++.h>

using namespace std;

int sum() { return 0;}
template<typename T,typename... Args>
T sum(T a, Args... args) { return a+sum(args...);}

#define print(args...) { string s = #args; replace(s.begin(), s.end(), ',', ' '); stringstream ss(s); istream_iterator<string> it(ss); err(it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define rep(i,begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main()
{
	int x=sum(1,2,3,4,5);
	print(x);
	int b=45;
	print(x,b);
	vector<int> a;
	rep(i,2,10)
	{
		a.push_back(i);
	}
	rep(i,0,a.size())
	{
		print(a[i]);
	}
	return 0;
}