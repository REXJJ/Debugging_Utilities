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
	int b=45;
	std::vector<int> a;
	rep(i,10,2)
	{
		a.push_back(i);
	}
    std::map<std::string,int> marks = { {"CSCI567",100}, {"CSCI561",100}, {"CSCI570",100} };
    std::map<std::string,int> alphabets={{"A",0},{"B",1}};
    std::unordered_set<std::string> animals = {"cat","dog","dinosaurs"};
    std::vector<loc> locations;
    locations.push_back(loc{0,0});
    locations.push_back(loc{1,1});
    std::vector<std::map<std::string,int>> map_vec;
    map_vec.push_back(marks);
    map_vec.push_back(alphabets);
    std::cout<<"Outputs of disp: \n";
    disp(marks);
	disp(x);
    disp(map_vec);
    std::cout<<"Output of print: \n";
    print(locations);
    print(a);
    std::cout<<"Output of debug: \n";
    debug(marks,a,x,b,alphabets,animals);
    expect((b-x+10)*50==100);
	return 0;
}