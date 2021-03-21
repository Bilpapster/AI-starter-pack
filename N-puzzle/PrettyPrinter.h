#ifndef AI_STARTER_PACK_IN_CPP_PRETTY_PRINTER_H
#define AI_STARTER_PACK_IN_CPP_PRETTY_PRINTER_H

#include "State.h"

class PrettyPrinter {
public:
    static void printResults(State *solutionState,
                             const long long int &volumeOfAllocatedMemory,
                             const long long int &numberOfExaminedStates);
};

#endif //AI_STARTER_PACK_IN_CPP_PRETTY_PRINTER_H
