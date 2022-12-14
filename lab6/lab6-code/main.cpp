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

    string root_path = ".";
    string root_name = "input";
    folder* root = new folder(root_path, root_name);
    string inpath = "./input";
    root->read_file_name();
    // num of the folders
    int loop = root->get_num();
    for(int fdn = 0;fdn < loop;fdn++){
        string fdn_name = root->get_file_name(fdn);
        preprocess* pre = new preprocess(inpath, fdn_name);
        pre->display_args();
        //folder* fd =  new folder{};
        folder* fd = pre->init_folder();
        //fd->display();
        sets *sts = new sets{};
        sts->resize(fd->get_num());
        pre->find_same(*fd, *sts);

        string testcase_path = inpath + "/" + fd->get_name();
        string testcase_name = "stdin_format.txt";
        testcase* tc = new testcase(testcase_path, testcase_name);
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