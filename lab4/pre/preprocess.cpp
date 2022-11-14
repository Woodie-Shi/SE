#include "preprocess.h"

void preprocess::set_args(){
    cout << "请输入文件夹路径: ";
    cin >> _path;
    cout << endl << "请输入文件夹名: ";
    cin >> _name;
}

folder* preprocess::init_folder(){
    folder* fd = new folder(_path, _name);
    fd->read_file_name();
    return fd;
}

void preprocess::find_same(folder &fd, sets &sts){
    bool hassame = 0;
    int num = fd.get_num();
    for(int i = 0;i < num - 1;i++){
        for(int j = i + 1;j < num;j++){
            if(fd._files[i].get_same() || fd._files[j].get_same()) continue;
            if(fd._files[i].get_data().compare(fd._files[j].get_data()) == 0){
                hassame = 1;
                fd._files[j].set_same();
                sts.add_to(i, j);
                cout << "file " << fd._files[i].get_name() << " and file " << fd._files[j].get_name() << " are the same." << endl;
            }
        }
    }
    if(!hassame) cout << "No same files in folder " << fd.get_name() << endl; 
}