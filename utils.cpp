#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int generateRandPortNum(void) {
  std::srand((unsigned)time(0));
  return (rand() % 10000 + 1000);
}

// vector<wstring> split (const wstring &s, unsigned char delim) {
//     vector<wstring> result;
//     wstringstream ss (s);
//     wstring item;

//     while (getline (ss, item, delim)) {
//         result.push_back (item);
//     }

//     return result;
// }

map<wstring> initialize_commands_list(map<wstring> &commands)
{
  commands.insert(make_pair(L"ADMIN"), void*);
  commands.push_back("AWAY");
  commands.push_back("CNOTICE");
  commands.push_back("CPRIVMSG");
  commands.push_back("CONNECT");
  commands.push_back("DIE");
  commands.push_back("ENCAP");
  commands.push_back("ERROR");
  commands.push_back("HELP");
  commands.push_back("INFO");
  commands.push_back("INVITE");
  commands.push_back("ISON");
  commands.push_back("JOIN");
  commands.push_back("KICK");
  commands.push_back("KILL");
  commands.push_back("KNOCK");
  commands.push_back("LINKS");
  commands.push_back("LIST");
  commands.push_back("LUSERS");
  commands.push_back("MODE");
  commands.push_back("MOTD");
  commands.push_back("NAMES");
  commands.push_back("NAMESX");
  commands.push_back("NICK");
  commands.push_back("NOTICE");
  commands.push_back("OPER");
  commands.push_back("PART");
  commands.push_back("PASS");
  commands.push_back("PING");
  commands.push_back("PONG");
  commands.push_back("PRIVMSG");
  commands.push_back("QUIT");
  commands.push_back("REHASH");
  commands.push_back("RULES");
  commands.push_back("SERVER");
  commands.push_back("SERVICE");
  commands.push_back("SERVLIST");
  commands.push_back("SQUERY");
  commands.push_back("SQUIT");
  commands.push_back("SETNAME");
  commands.push_back("SILENCE");
  commands.push_back("STATS");
  commands.push_back("SUMMON");
  commands.push_back("TIME");
  commands.push_back("TOPIC");
  commands.push_back("TRACE");
  commands.push_back("UHNAMES");
  commands.push_back("USER");
  commands.push_back("USERHOST");
  commands.push_back("USERIP");
  commands.push_back("USERS");
  commands.push_back("VERSION");
  commands.push_back("WALLOPS");
  commands.push_back("WATCH");
  commands.push_back("WHO");
  commands.push_back("WHOIS");
}