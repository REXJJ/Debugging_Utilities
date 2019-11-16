#include <bits/stdc++.h>
#include <string>
#include <map>
#include "debugging_utilities.hpp"


struct loc
{
    int x,y;
};

std::ostream& operator<< (std::ostream& out, const loc l) {
    out<<"x: "<<l.x<<" "<<"y: "<<l.y;
    return out;
}

int main()
{
	int x=sum(1,2,3,4,5);
	print(x);
	int b=45;
	std::vector<int> a;
	rep(i,2,10)
	{
		a.push_back(i);
	}
    print(a);
    std::map<std::string,int> marks = { {"CSCI567",100}, {"CSCI561",100}, {"CSCI570",100} };
    std::unordered_map<std::string,int> alphabets={{"A",0},{"B",1}};
    std::unordered_set<std::string> animals = {"cat","dog","dinosaurs"};
    print(marks);
    debug(marks,a,x,b,alphabets,animals);
    std::vector<loc> locations;
    locations.push_back(loc{0,0});
    locations.push_back(loc{1,1});
    print(locations);
    expect(b==x+10);
	return 0;
}