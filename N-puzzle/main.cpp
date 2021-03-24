#include <iostream>

#include "SearchExpert.h"
#include "PrettyPrinter.h"

int main() {
    long long int volumeOfAllocatedMemory, numberOfExaminedStates;

    State *initial = new State();
    State *goal = new State(true);

    State *solution;
    cout << "Initial:" << endl << initial->toString() << endl;
    cout << "Goal:" << endl << goal->toString() << endl;

    cout << endl << "DFS: ";
    solution = SearchExpert::depthFirstSearch2(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
    PrettyPrinter::printResults(solution, volumeOfAllocatedMemory, numberOfExaminedStates);

    cout << endl << "BFS: ";
    solution = SearchExpert::breadthFirstSearch(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
    PrettyPrinter::printResults(solution, volumeOfAllocatedMemory, numberOfExaminedStates);

    cout << endl << "BestFS: ";
    solution = SearchExpert::bestFirstSearch(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
    PrettyPrinter::printResults(solution, volumeOfAllocatedMemory, numberOfExaminedStates);

    delete initial;
    delete goal;

    return 0;
}
