#include <iostream>
#include "PrettyPrinter.h"

void PrettyPrinter::printResults(State *solutionState,
                                 const long long int &volumeOfAllocatedMemory,
                                 const long long int &numberOfExaminedStates) {
    if (solutionState != nullptr) {
        cout << "depth = " << solutionState->getDepth()
             << ", Mem: " << volumeOfAllocatedMemory
             << ", Examined: " << numberOfExaminedStates << endl;
    } else
        cout << "Problem unsolvable" << endl;
}
