#include <iostream>
#include "Prog3.h"

using namespace Prog3;
const char* msgs[] = { " [0] Exit",
                       " [1] Set + Set",
                       " [2] Set + char",
                       " [3] Set * Set",
                       " [4] Set - Set",
                       " [5] Set message in set1 and set2",
                       " [6] Get message in set1 and set2\n"


};

const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int (*functions[])(Set&, Set&, Set&) = { nullptr, dialogSumm, dialogSummChar, dialogMultiplication, dialogSubtraction, dialogSetMessage, dialogGetArr };

int main() {
    try {
        Set S1("amigo"), S2(" lab_BIG"), S3;
        int rc;
        while ((rc = dialog(msgs, NMsgs))) {
            if (!functions[rc](S1, S2, S3))
                break;
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
