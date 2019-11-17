#ifndef DEBUGGING_UTILITIES_HPP
#define DEBUGGING_UTILITIES_HPP
#include <iostream>
#include <chrono>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
/*****************************************************************/
//Color Definitions
/****************************************************************/
#define _NORMAL_    "\x1b[0m"
#define _BLACK_     "\x1b[30;47m"
#define _RED_       "\x1b[31;40m"
#define _GREEN_     "\x1b[32;40m"
#define _YELLOW_    "\x1b[33;40m"
#define _BLUE_      "\x1b[34;40m"
#define _MAGENTA_   "\x1b[35;40m"
#define _CYAN_      "\x1b[36;40m"
#define _WHITE_     "\x1b[37;40m"
#define _BRED_      "\x1b[1;31;40m"
#define _BGREEN_    "\x1b[1;32;40m"
#define _BYELLOW_   "\x1b[1;33;40m"
#define _BBLUE_     "\x1b[1;34;40m"
#define _BMAGENTA_  "\x1b[1;35;40m"
#define _BCYAN_     "\x1b[1;36;40m"
#define _BWHITE_    "\x1b[1;37;40m"
/******************************************************************/
//Print Utilities for debugging.
/*******************************************************************/
#define dbg_color(...) do { printf(__VA_ARGS__); } while(0)

#define dbg(...)                                                     \
do {                                                                 \
	  printf("DBG: %s:%d %s():",__FILE__,__LINE__,__func__);         \
	  printf(__VA_ARGS__);                                           \
	  printf("%s", _NORMAL_);                                        \
} while(0)

#define whereami()                                                   \
do {                                                                 \
        dbg_color(_MAGENTA_);                                        \
 	      printf("HERE: %s:%d %s()\n",__FILE__,__LINE__,__func__);   \
 	      dbg_color(_NORMAL_);                                       \
 	} while(0)

#ifdef NDEBUG
#define disp(var)
#else
#define disp(var) { std::cout << #var << ": " << (var) << std::endl; }
#endif

//<< Overloading for map
template<typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, const std::map<T1,T2> &M) 
{
    int count=0;
    out << "Map: { ";
    auto it=M.begin();
    for (;it!=M.end();it++)
    {
        out << it->first << "->" << it->second << ", ";
        if(++count==M.size()-1) break;
    }
    it++;
    out<<it->first<< "->" <<it->second;
    out << " }";
    return out;
}
//<< Overloading for unordered_map
template<typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, const std::unordered_map<T1,T2> &M)
{
    int count=0;
    out << "Map: { ";
    auto it=M.begin();
    for (;it!=M.end();it++)
    {
        out << it->first << "->" << it->second << ", ";
        if(++count==M.size()-1) break;
    }
    it++;
    out<<it->first<< "->" <<it->second;
    out << " }";
    return out;
}
//<< Overloading for set
template<typename T>
std::ostream& operator<< (std::ostream& out, const std::set<T> &M)
{
    int count=0;
    out << "Set: { ";
    auto it=M.begin();
    for (;it!=M.end();it++)
    {
        out <<*it<< ", ";
        if(++count==M.size()-1) break;
    }
    it++;
    out<<*it;
    out << " }";
    return out;
}
//<< Overloading for set
template<typename T>
std::ostream& operator<< (std::ostream& out, const std::unordered_set<T> &M) 
{
    int count=0;
    out << "Set: { ";
    auto it=M.begin();
    for (;it!=M.end();it++)
    {
        out <<*it<< ", ";
        if(++count==M.size()-1) break;
    }
    it++;
    out<<*it;
    out << " }";
    return out;
}
//<< Overloading for vector
template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T> M)
{
    out << "Vector: { ";
    for (int i=0;i<M.size()-1;i++)
    {
        out << i << "->" << M[i] << ", ";
    }
    out<<M.size()-1<<"->" <<M[M.size()-1]<< " }";
    return out;
}

//A more "Pythonic" way to print stuffs.

void print(){}
template<typename T,typename... Args>
void print(T Contents, Args... args) {std::cout<< (Contents) << std::endl;print(args...);}

/******************************************************************/
//Functions to find the running time of code blocks.
/*******************************************************************/

#define tic() std::chrono::high_resolution_clock::time_point END_TIME,START_TIME=std::chrono::high_resolution_clock::now()

#define reset() START_TIME=std::chrono::high_resolution_clock::now()

#define toc()                                                   \
do                                                              \
{                                                               \
	dbg_color(_GREEN_);                                         \
    END_TIME=std::chrono::high_resolution_clock::now();         \
    std::cout << " Time elapsed in "<<__func__<<"() : "         \
    << std::chrono::duration_cast<std::chrono::microseconds>(END_TIME - START_TIME).count() << " microseconds.\n"; \
    dbg_color(_NORMAL_);                                        \
}while(0)

/**********************************************************************/
//Other Utilities...
/*********************************************************************/

#define rep(i,begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int sum() { return 0;}
template<typename T,typename... Args>
T sum(T a, Args... args) { return a+sum(args...);}

#define expect(expression) if(expression==false) std::cerr << "Assertion " << #expression \
" failed at " << __FILE__ << ":" << __LINE__ << std::endl;

#endif