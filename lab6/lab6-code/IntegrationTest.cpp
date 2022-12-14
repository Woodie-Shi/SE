#include "data_structure.h"
#include "preprocess.h"
#include "judge.h"
#include "output.h"
#include "gtest/gtest.h"
#include<filesystem>
#include <fstream>

class IntegrationTest: public::testing::Test
{
protected:
    void SetUp() override {
        string outpath = "./output";
        if(!filesystem::exists(outpath)) filesystem::create_directory(outpath);
        ofstream equ(outpath + "/equal.csv");
        ofstream inequ(outpath + "/inequal.csv");
        equ << "file1" << "," << "file2" << endl;
        inequ << "file1" << "," << "file2" << endl;
        equ.close();
        inequ.close();
    }
    void TearDown() override {
        delete root;
    }

    string root_path = ".";
    string root_name = "input";
    folder* root = new folder(root_path, root_name);
    
};

TEST_F(IntegrationTest, testAll){
    EXPECT_EQ(0, root->get_num());
    root->read_file_name();
    EXPECT_EQ(5, root->get_num());
    int loop = root->get_num();
    string inpath = "./input";
    for(int fdn = 0;fdn < loop;fdn++){
        string fdn_name = root->get_file_name(fdn);
        preprocess* pre = new preprocess(inpath, fdn_name);

        folder* fd = pre->init_folder();
        EXPECT_STREQ(inpath.c_str(), fd->get_path().c_str());
        EXPECT_STREQ(fdn_name.c_str(), fd->get_name().c_str());
        sets *sts = new sets{};
        sts->resize(fd->get_num());
        pre->find_same(*fd, *sts);
        if(fdn_name.compare("Fd2") == 0){
            EXPECT_TRUE(sts->find(0, 1));
            EXPECT_TRUE(sts->find(0, 2));
            EXPECT_TRUE(sts->find(0, 3));
            EXPECT_TRUE(sts->find(1, 0));
            EXPECT_TRUE(sts->find(1, 2));
            EXPECT_TRUE(sts->find(1, 3));
            EXPECT_TRUE(sts->find(2, 0));
            EXPECT_TRUE(sts->find(2, 1));
            EXPECT_TRUE(sts->find(2, 3));
            EXPECT_TRUE(sts->find(3, 0));
            EXPECT_TRUE(sts->find(3, 1));
            EXPECT_TRUE(sts->find(3, 2));
        }
        
        string testcase_path = inpath + "/" + fd->get_name();
        string testcase_name = "stdin_format.txt";
        testcase* tc = new testcase(testcase_path, testcase_name);
        tc->read_data();
        tc->read_format();
        tc->create(10);

        judge* judgement = new judge{};
        bool exe = judgement->execute(*fd, 10);
        EXPECT_TRUE(exe);

        judgement->compare(*fd, *sts);

        output* result = new output{};
        bool success = result->save(*fd, *sts);
        EXPECT_TRUE(success);
        
        tc->delcases();
        delete pre, fd, sts, tc, judgement, result;
    }
    int equals = 0, inequals = 0;
    ifstream fpe("./output/equal.csv");
    ifstream fpine("./output/inequal.csv");
    string line;
    getline(fpe, line);
    while (getline(fpe, line)) equals++;
    getline(fpine, line);
    while(getline(fpine, line)) inequals++;
    EXPECT_EQ(31, equals+inequals);
}

int main() 
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}