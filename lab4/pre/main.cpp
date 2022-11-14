#include "preprocess.h"

int main(){
    preprocess pre;
    pre.set_args();
    folder* fd = pre.init_folder();
    sets sts;
    sts.resize(fd->get_num());
    pre.find_same(*fd, sts);
    fd->display();
    sts.display();
    return 0;
}