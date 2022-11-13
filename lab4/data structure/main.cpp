#include "data_structure.h"

int main(){
    folder fd("../input", "50A");
    fd.read_file_name();
    cout << "num: " << fd.get_num() << endl;
    fd.display();
    string testname = "stdin_format.txt";
    testcase tc(fd.get_path() + "/" + fd.get_name(), testname);
    tc.read_data();
    tc.read_format();
    tc.create(20);
}