//
// Created by devilish on 10/20/20.
//


#include "math.h"

int demonic::true_rand() {
    auto duration = std::chrono::system_clock::now().time_since_epoch();
    int time = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    srand(time);
    return rand();
}