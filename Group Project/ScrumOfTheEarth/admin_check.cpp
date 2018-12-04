
#include "window.h" //not 100% sure what header file to use
#include <fstream>
using namespace std;

bool Window::Check_Admin(string file, string username, string password)
{
  string adminPassword;
  string adminUser;
  ifstream fin;
  bool admin = false;
  fin.open(file.c_str());
  while(getline(fin,adminUser))
  {
    getline(fin,adminPassword);
    fin.ignore(1,'\n');
    if(adminUser == username)
    {
        if(adminPassword == password)
        {
            admin = true;
            break;
        }
    }
  }

  fin.close();
  return admin;
}
