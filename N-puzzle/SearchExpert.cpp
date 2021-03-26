#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <ctime>

#include "DepthFirstSearchAlgorithm.h"
#include "BreadthFirstSearchAlgorithm.h"
#include "BestFirstSearchAlgorithm.h"
#include "AStarSearchAlgorithm.h"
#include "SearchExpert.h"
#include "PrettyPrinter.h"

void SearchExpert::executeAvailableAlgorithms(State *initial, State *goal) {

    long long int numberOfExaminedStates, volumeOfAllocatedMemory;
    auto *searchAlgorithms = new vector<SearchAlgorithm *>;
    initializeSearchAlgorithms(searchAlgorithms);

    State *solution;
    for (SearchAlgorithm *searchAlgorithm : (*searchAlgorithms)) {
        clock_t start = clock();
        solution = searchAlgorithm->search(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
        double timeElapsedOnSearch = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;
        cout << searchAlgorithm->getAlgorithmName() << ":" << endl;
        PrettyPrinter::printResults(solution, volumeOfAllocatedMemory, numberOfExaminedStates);
        cout << "Search time: " << timeElapsedOnSearch << "millis" << endl;
    }

}

void SearchExpert::initializeSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms) {
    searchAlgorithms->push_back(new DepthFirstSearchAlgorithm());
    searchAlgorithms->push_back(new BreadthFirstSearchAlgorithm());
    searchAlgorithms->push_back(new BestFirstSearchAlgorithm());
    searchAlgorithms->push_back(new AStarSearchAlgorithm());
}
