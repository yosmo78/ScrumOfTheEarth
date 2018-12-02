
#include "window.h" //not 100% sure what header file to use
#include <fstream>
using namespace std;

Window::Check_Admin(string file, string username, string password)
{
  string adminPassword;
  string adminUser;
  ifstream fin;
  bool admin = false;
  bool found = false;

  fin.open(file.c_str());

  while((!fin.eof()) && (!found)) {
    getline(fin, adminUser);
    getline(fin, adminPassword);

    if(adminUser == username) {
      if(adminPassword == password) {
        admin = true;
        found = true;
      }
    }
    fin.ignore(1000, '\n');
  }

  return admin;
}
