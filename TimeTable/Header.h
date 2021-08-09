#ifndef Header_h
#define Header_h
#include <string>
#include <cstdio>
#include <vector>
 
using namespace std;

class Tutu{
private:
    pair<string, int> name;
    pair<string, string> route;
    pair<int, int> departure;
    pair<int, int> arrival;
public:
    Tutu();
    void get();
    void set();
    void random_route();
    pair<int, int> get_time();
};
#endif 

