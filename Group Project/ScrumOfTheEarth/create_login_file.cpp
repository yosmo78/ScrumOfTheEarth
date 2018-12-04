#include "window.h"
#include <fstream>
void Window::create_login_file()
{
    std::ofstream fout;
    fout.open("admin_list.txt");
    fout << "admin\nadmin\n\nchris\npersyvall\n\nanthony\ncsmaster\n\nchris\ncsmaster\n\njustice\nscrum\n\nbredon\nscrum2\n\njosh\nscrum3";
    fout.close();
}
