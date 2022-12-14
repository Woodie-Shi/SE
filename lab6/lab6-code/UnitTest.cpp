#include "data_structure.h"
#include "gtest/gtest.h"
#include <set>
#include <fstream>

class InputFolderTest :public::testing::Test
{
protected:
    void SetUp() override {
        fd->read_file_name();
    }
    void TearDown() override {
        delete fd;
    }
    string fd_path = "./";
    string fd_name = "input";
    folder * fd = new folder(fd_path, fd_name);
};

class FolderTest: public::testing::Test{
protected:
    void SetUp() override {
        fd->read_file();
    }
    void TearDown() override {
        delete fd;
    }

    string fd_path = "./input";
    string fd_name = "Fd1";
    folder * fd = new folder(fd_path, fd_name);
};

class FileTest: public::testing::Test {
protected:
    void SetUp() override {
        f->read_data();
    }
    void TearDown() override {
        delete f;
    }

    string f_path = "./input/Fd1";
    string f_name = "108793.cpp";
    file* f = new file(f_path, f_name);
};

class setsTest: public::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
        delete s;
    }

    sets* s = new sets();
};

class testcaseTest: public::testing::Test {
protected:
    void SetUp() override {
        tc->read_data();
        tc->read_format();
    }
    void TearDown() override {
        tc->delcases();
        delete tc;
    }
    string testcase_path = "./input/Fd1";
    string testcase_name = "stdin_format.txt";
    testcase* tc = new testcase(testcase_path, testcase_name);
};

// test the root folder input
//----------------------------------------------------------------------------------------
TEST_F(InputFolderTest, testGetPath){
    EXPECT_STREQ(fd_path.c_str(), fd->get_path().c_str());
}

TEST_F(InputFolderTest, testGetName){
    EXPECT_STREQ(fd_name.c_str(), fd->get_name().c_str());
}

TEST_F(InputFolderTest, testReadFileNameNum){
    EXPECT_EQ(5, fd->get_num());
}

TEST_F(InputFolderTest, testReadFileName){
    set<string> folder_names;
    for(auto it = 0;it < fd->get_num();it++){
        folder_names.insert(fd->get_file_name(it));
    }
    EXPECT_EQ(1, (int)folder_names.count("Fd1"));
    EXPECT_EQ(1, (int)folder_names.count("Fd2"));
    EXPECT_EQ(1, (int)folder_names.count("Fd3"));
    EXPECT_EQ(1, (int)folder_names.count("Fd4"));
    EXPECT_EQ(1, (int)folder_names.count("Fd5"));
}

// test the folder Fd1
//------------------------------------------------------------------------------------------
TEST_F(FolderTest, testReadFileNum){
    EXPECT_EQ(6, fd->get_num());
}

TEST_F(FolderTest, testReadFile) {
    set<string> file_names;
    for(auto it = 0;it < fd->get_num();it++){
        file_names.insert(fd->_files[it].get_name());
    }
    string file_path = "./input/Fd1";
    EXPECT_STREQ(file_path.c_str(), fd->_files[0].get_path().c_str());
    EXPECT_EQ(1, (int)file_names.count("108793.cpp"));
    EXPECT_EQ(1, (int)file_names.count("130206.cpp"));
    EXPECT_EQ(1, (int)file_names.count("220805.cpp"));
    EXPECT_EQ(1, (int)file_names.count("281291.cpp"));
    EXPECT_EQ(1, (int)file_names.count("680588.cpp"));
    EXPECT_EQ(1, (int)file_names.count("800017.cpp"));
}

//test the file "./input/Fd1/108793.cpp";
//-----------------------------------------------------------------------------------------
TEST_F(FileTest, testGetPath){
    EXPECT_STREQ(f_path.c_str(), f->get_path().c_str());
}

TEST_F(FileTest, testGetName){
    EXPECT_STREQ(f_name.c_str(), f->get_name().c_str());
}

TEST_F(FileTest, testMemberSame){
    EXPECT_FALSE(f->get_same());
    f->set_same();
    EXPECT_TRUE(f->get_same());
}

TEST_F(FileTest, testGetData){
    ifstream ifs("./input/Fd1/108793.cpp");
    string data((std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()));
    ifs.close();
    EXPECT_STREQ(data.c_str(), f->get_data().c_str());
}

// test class sets
//-----------------------------------------------------------------------------------------
TEST_F(setsTest, testResize){
    EXPECT_EQ(0, (int)s->_Sets.size());
    s->_Sets.resize(3);
    EXPECT_EQ(3, (int)s->_Sets.size());
}

TEST_F(setsTest, testInsert){
    s->_Sets.resize(3);
    EXPECT_FALSE(s->find(0, 1));
    EXPECT_FALSE(s->find(2, 0));
    s->add_to(0, 1);
    EXPECT_TRUE(s->find(1, 0));
    s->add_to(1, 2);
    EXPECT_TRUE(s->find(0, 1));
    EXPECT_TRUE(s->find(0, 2));
    EXPECT_TRUE(s->find(1, 0));
    EXPECT_TRUE(s->find(1, 2));
    EXPECT_TRUE(s->find(2, 0));
    EXPECT_TRUE(s->find(2, 1));
}

//test class testcase
//--------------------------------------------------------------------------------------------
TEST_F(testcaseTest, testCreate){
    tc->create(10);
    for(int i = 0;i < 10;i++){
        string p = "./input/Fd1/testcases/";
        p += to_string(i);
        p += ".txt";
        ifstream ifs(p);
        string data((std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()));
        ifs.close();
        int number = atoi(data.c_str());
        EXPECT_TRUE(number >= 1);
        EXPECT_TRUE(number <= 1000);
    }
}

int main() 
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}