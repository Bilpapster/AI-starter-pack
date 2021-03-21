#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>

#include "SearchExpert.h"

void prettyPrintResults(State *solution,
                        const long long int &volumeOfMemoryAllocated,
                        const long long int &numberOfExaminedStates);

using namespace std;

int main() {
    long long volumeOfMemoryAllocated, numberOfExaminedStates;

    State *initial = new State(0, 0, false);
    State *goal = new State(0, 0, true);

    srand(time(NULL));
    initial->setX(rand() % 100);
    initial->setY(rand() % 100);

    goal->setX(rand() % 100);
    goal->setY(rand() % 100);

    for (int i = 1; i < 100; i++)
        for (int j = 1; j < 100; j++)
            if (rand() % 5 == 0)
                initial->setFree(i, j, false);

    State *solution;
    cout << "Initial:" << endl << initial->toString() << endl;
    cout << "Goal:" << endl << goal->toString() << endl;

    cout << endl << "DFS: ";
    solution = SearchExpert::DFS2(initial, goal, numberOfExaminedStates, volumeOfMemoryAllocated);
    prettyPrintResults(solution, volumeOfMemoryAllocated, numberOfExaminedStates);

    cout << endl << "BFS: ";
    solution = SearchExpert::BFS2(initial, goal, numberOfExaminedStates, volumeOfMemoryAllocated);
    prettyPrintResults(solution, volumeOfMemoryAllocated, numberOfExaminedStates);

    cout << endl << "BestFS: ";
    solution = SearchExpert::BestFS2(initial, goal, numberOfExaminedStates, volumeOfMemoryAllocated);
    prettyPrintResults(solution, volumeOfMemoryAllocated, numberOfExaminedStates);

    delete initial;
    delete goal;

    return 0;
}

void prettyPrintResults(State *solution,
                        const long long int &volumeOfMemoryAllocated,
                        const long long int &numberOfExaminedStates) {
    if (solution != nullptr) {
        cout << "depth = " << solution->getDepth()
             << ", Mem: " << volumeOfMemoryAllocated
             << ", Examined: " << numberOfExaminedStates << endl;
    } else
        cout << "Problem unsolvable" << endl;
}
