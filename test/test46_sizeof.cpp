//
// Created by lixiaoqing on 2022/8/24.
//

#include <iostream>


struct TRACK_PT {
    uint64_t timestamp;//时间戳
    int key;//对应到的视频索引
};

int main() {
    printf("sizeof(TRACK_PT)=%d\n", sizeof(TRACK_PT));
    return 0;
}