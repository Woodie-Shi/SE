#include "data_structure.h"
#include "preprocess.h"
#include "judge.h"
#include "output.h"
#include<filesystem>
#include<fstream>

const int TEST_NUM = 10;

int main(){
    // create output dir
    string outpath = "./output";
    
    if(!filesystem::exists(outpath)) filesystem::create_directory(outpath);
    ofstream equ(outpath + "/equal.csv");
    ofstream inequ(outpath + "/inequal.csv");
    equ << "file1" << "," << "file2" << endl;
    inequ << "file1" << "," << "file2" << endl;
    equ.close();
    inequ.close();

    folder* root = new folder(".", "input");
    string inpath = "./input";
    root->read_file_name();
    // num of the folders
    int loop = root->get_num();
    for(int fdn = 0;fdn < loop;fdn++){
        preprocess* pre = new preprocess(inpath, root->get_file_name(fdn));
        pre->display_args();
        folder* fd =  new folder{};
        fd = pre->init_folder();
        //fd->display();
        sets *sts = new sets{};
        sts->resize(fd->get_num());
        pre->find_same(*fd, *sts);

        testcase* tc = new testcase(inpath + "/" + fd->get_name(), "stdin_format.txt");
        tc->read_data();
        tc->read_format();
        tc->create(TEST_NUM);

        judge* judgement = new judge{};
        bool exe = judgement->execute(*fd, TEST_NUM);
        if(!exe) cout<<"error in executing."<<endl;
        else{
            judgement->compare(*fd, *sts);

            cout << "compare finished" << endl;

            output* result = new output{};
            bool success = result->save(*fd, *sts);
            if(success) cout << "finished" <<endl << endl;
            else cout << "failed" <<endl << endl;
            delete result;
        }
        tc->delcases();
        delete pre, fd, sts, tc, judgement;
    }
    delete root;
}