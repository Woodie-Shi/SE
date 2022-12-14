#include "judge.h"
#include<stdlib.h>
#include <filesystem>

bool judge::compile(file &f, int num){
    if(f.get_same()) return true;
    string path = f.get_path();         // path = ./input/dir
    string name = f.get_name();    //name = f1.cpp
    string pgpath = path + "/" + name;                     // pgpath = ./input/dir/f1.cpp
    string testpath = path + "/testcases/";                // testpath = ./input/dir/testcases/

    string compiler = "g++ -o ";
    string command = pgpath;                                   // command = ./input/dir/f1.cpp
    command.erase(command.length() - 4, 4);  // command = ./input/dir/f1
    string dirname = command;                                // dirname = ./input/dir/f1
    command += ".exe";                                               // command = ./input/dir/f1.exe
    compiler += command;                                        // compiler = g++ -o ./input/dir/f1.exe
    compiler += " ";
    compiler += pgpath;                     // compiler = g++ -o ./input/dir/f1.exe ./input/dir/f1.cpp
    
    bool b1 = system(compiler.c_str());
    if(!b1){
        //create a dir for each program
        bool success = filesystem::create_directory(dirname);
        if(!success){
            cout << "Error to create " << dirname << " dir." << endl;
        }
        else{
            command += " <";                          // command = ./input/dir/f1.exe <
            // for each testcase, run program and get the output
            //bool b2 = 0;
            for(int i = 0;i < num;i++){
                //b2 = 1;
                string cmd = command;         // cmd = ./input/dir/f1.exe <
                cmd += testpath;                       // cmd = ./input/dir/f1.exe <./input/dir/testcases/
                cmd += to_string(i);                 // cmd = ./input/dir/f1.exe <./input/dir/testcases/i
                cmd += ".txt >";                          // cmd = ./input/dir/f1.exe <./input/dir/testcases/i.txt >
                cmd += dirname;                      // cmd = ./input/dir/f1.exe <./input/dir/testcases/i.txt >./input/dir/f1
                cmd += "/";                                  // cmd = ./input/dir/f1.exe <./input/dir/testcases/i.txt >./input/dir/f1/
                cmd += to_string(i);                 // cmd = ./input/dir/f1.exe <./input/dir/testcases/i.txt >./input/dir/f1/i
                cmd += ".txt";                             // cmd = ./input/dir/f1.exe <./input/dir/testcases/i.txt >./input/dir/f1/i.txt
                bool b2 = system(cmd.c_str());
                if(b2) cout << "program " << dirname << ".exe with testcase" << i << ".txt error." <<endl;
            }
        }
        return true;
    }
    else cout << "Compile error." << endl;
    return false;
}

bool judge::execute(folder& fd, int num){
    bool normal = 1;
    for(auto it = fd._files.begin(); it != fd._files.end();it++){
        normal = normal && compile(*it, num);
    }
    if(!normal){
        cout << "error in executing." << endl;
        return false;
    }
    return true;
}

void judge::compare(folder &fd, sets& sts){
    int n = fd.get_num();
    for(int i = 0;i < n - 1;i++){
        file* fa = fd.get_file(i);
        if(fa->get_same()) continue;
        string fafdname = fa->get_name();
        fafdname.erase(fafdname.length() - 4, 4);
        string fda_path = fa->get_path();
        folder *fda = new folder(fda_path, fafdname);
        fda->read_file();
        for(int j = i + 1;j < n;j++){
            // already equivalent
            if(sts.find(i, j)) continue;

            file* fb = fd.get_file(j);
            if(fb->get_same()) continue;
            string fbfdname = fb->get_name();
            fbfdname.erase(fbfdname.length() - 4, 4);
            string fdb_path = fb->get_path();
            folder *fdb = new folder(fdb_path, fbfdname);
            fdb->read_file();

            if(fda->get_num() != fdb->get_num()){
                cout << "cannot compare " << i << "and " << j << ", the num of testcases' outputs are not equal" << endl;
                continue;
            }
            cout << "compare " << fa->get_name() << " & " << fb->get_name() << endl;
            bool euqivant = 1;
            for(int t = 0;t < fda->get_num();t++){
                file* ta = fda->get_file(t);
                file* tb = fdb->get_file(t);
                if(ta->get_data().compare(tb->get_data()) != 0){
                    euqivant = 0;
                    break;
                }
            }
            if(euqivant) sts.add_to(i, j);
        }
        //delete dir
        string deda = "rm -r ";
        deda += (fda->get_path() + "/" + fda->get_name());
        system(deda.c_str());
        delete fda;
    }
    file* ff = fd.get_file(n - 1);
    if(!ff->get_same()){
        string ffdname = ff->get_name();
        ffdname.erase(ffdname.length() - 4, 4);
        string del = "rm -r ";
        del += (ff->get_path() + "/" + ffdname);
        system(del.c_str());
    }
}