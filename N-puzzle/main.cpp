#include <iostream>
#include <ctime>

#include "SearchExpert.h"
#include "PrettyPrinter.h"

int main() {
    long long int volumeOfAllocatedMemory, numberOfExaminedStates;

//    State *initial = new State(0, 0, false);
//    State *goal = new State(0, 0, true);

    State *initial = new State();
    State *goal = new State();
    goal->setFinal();

//    srand(time(NULL));
//    initial->setX(rand() % WIDTH);
//    initial->setY(rand() % HEIGHT);
//
//    goal->setX(rand() % WIDTH);
//    goal->setY(rand() % HEIGHT);

//    for (int i = 1; i < 100; i++)
//        for (int j = 1; j < 100; j++)
//            if (rand() % 5 == 0)
//                initial->setFree(i, j, false);

    State *solution;
    cout << "Initial:" << endl << initial->toString() << endl;
    cout << "Goal:" << endl << goal->toString() << endl;

    cout << endl << "DFS: ";
    solution = SearchExpert::depthFirstSearch2(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
    PrettyPrinter::printResults(solution, volumeOfAllocatedMemory, numberOfExaminedStates);
    cout << endl << solution->toString();

    cout << endl << "BFS: ";
    solution = SearchExpert::breadthFirstSearch(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
    PrettyPrinter::printResults(solution, volumeOfAllocatedMemory, numberOfExaminedStates);
    cout << endl << solution->toString();


    cout << endl << "BestFS: ";
    solution = SearchExpert::bestFirstSearch(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
    PrettyPrinter::printResults(solution, volumeOfAllocatedMemory, numberOfExaminedStates);
    cout << endl << solution->toString();

    delete initial;
    delete goal;

    return 0;
}
