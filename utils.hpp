#ifndef UTILS_HPP
#define UTILS_HPP
#include <vector>
using namespace std;

int generateRandPortNum(void);
vector<wstring> split(const wstring &s, unsigned char delim);
vector<wstring> initialize_commands_list(vector<wstring> &commands);

#endif
