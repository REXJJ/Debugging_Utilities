#ifndef DEBUGGING_UTILITIES_H
#define DEBUGGING_UTILITIES_H
#include <iostream>
#include <chrono>
#include <stdio.h>

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

#define dbg(...)                                                    \
    do {                                                                 \
    	  printf("DBG: %s:%d %s():",__FILE__,__LINE__,__func__);         \
    	  printf(__VA_ARGS__);                                           \
    	  printf("%s", _NORMAL_);              \
    } while(0)

#define whereami()                                                       \
    do {                                                                 \
            dbg_color(_MAGENTA_);                                        \
     	      printf("HERE: %s:%d %s()\n",__FILE__,__LINE__,__func__);       \
     	      dbg_color(_NORMAL_);                                        \
     	} while(0)

//Python like print function.
#define print(args...) { string s = #args; replace(s.begin(), s.end(), ',', ' '); stringstream ss(s); istream_iterator<string> it(ss); err(it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  dbg_color(_RED);
  cerr << *it << " = " << a << endl;
  err(++it, args...);
  dbg_color(_NORMAL);
}
/******************************************************************/
//Functions to find the running time of code blocks.
/*******************************************************************/

#define tic() std::chrono::high_resolution_clock::time_point END_TIME,START_TIME=std::chrono::high_resolution_clock::now()

#define reset() START_TIME=std::chrono::high_resolution_clock::now()


#define toc()                                                       \
           do {                                                          \
           	      dbg_color(_GREEN_);                                    \
                  END_TIME=std::chrono::high_resolution_clock::now();    \
                  std::cout << " Time elapsed in "<<__func__<<"() : "      \
                  << std::chrono::duration_cast<std::chrono::microseconds>(END_TIME - START_TIME).count() << " microseconds.\n"; \
                  dbg_color(_NORMAL_);                                   \
              }while(0)
#endif
