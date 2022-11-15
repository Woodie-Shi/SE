#include "preprocess.h"

preprocess::preprocess() {}

preprocess::preprocess(string path, string name)
    :   _path(path)
    ,   _name(name) {}

void preprocess::display_args(){
    cout << "文件夹路径: " << _path << endl;
    cout << "文件夹名: " << _name << endl;
}

folder* preprocess::init_folder(){
    folder* fd = new folder(_path, _name);
    fd->read_file();
    return fd;
}

void preprocess::find_same(folder &fd, sets &sts){
    bool hassame = 0;
    int num = fd.get_num();
    for(int i = 0;i < num - 1;i++){
        for(int j = i + 1;j < num;j++){
            if(fd.get_file(i)->get_same() || fd.get_file(j)->get_same()) continue;
            if(fd.get_file(i)->get_data().compare(fd.get_file(j)->get_data()) == 0){
                hassame = 1;
                fd.get_file(j)->set_same();
                sts.add_to(i, j);
                cout << "file " << fd.get_file(i)->get_name() << " and file " << fd.get_file(j)->get_name() << " are the same." << endl;
            }
        }
    }
    if(!hassame) cout << "No same files in folder " << fd.get_name() << endl; 
}