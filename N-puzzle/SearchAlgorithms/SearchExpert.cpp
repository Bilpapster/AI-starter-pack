#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>
#include <ctime>

#include "DepthFirstSearchAlgorithm.h"
#include "BreadthFirstSearchAlgorithm.h"
#include "BestFirstSearchAlgorithm.h"
#include "AStarSearchAlgorithm.h"
#include "SearchExpert.h"

void SearchExpert::executeAvailableAlgorithms(State *initial, State *goal) {

    long long int numberOfExaminedStates, volumeOfAllocatedMemory;
    auto *searchAlgorithms = new vector<SearchAlgorithm *>;
    initializeSearchAlgorithms(searchAlgorithms);

    State *solution;
    for (SearchAlgorithm *searchAlgorithm : (*searchAlgorithms)) {
        clock_t start = clock();
        solution = searchAlgorithm->search(initial, goal, numberOfExaminedStates, volumeOfAllocatedMemory);
        double millisElapsedOnSearch = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;
        printResults(searchAlgorithm, solution, numberOfExaminedStates, volumeOfAllocatedMemory, millisElapsedOnSearch);
    }

    destructSearchAlgorithms(searchAlgorithms);

}

void SearchExpert::initializeSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms) {
    searchAlgorithms->push_back(new DepthFirstSearchAlgorithm());
    searchAlgorithms->push_back(new BreadthFirstSearchAlgorithm());
    searchAlgorithms->push_back(new BestFirstSearchAlgorithm());
    searchAlgorithms->push_back(new AStarSearchAlgorithm());
}

void SearchExpert::printResults(const SearchAlgorithm *searchAlgorithm,
                                const State *solutionState,
                                const long long int &numberOfExaminedStates,
                                const long long int &volumeOfAllocatedMemory,
                                const double &millisElapsedOnSearch) {

    if (solutionState) {
        cout << endl << "  --> " << searchAlgorithm->getAlgorithmName() << endl << endl
             << "Search time      : " << millisElapsedOnSearch << " millis" << endl
             << "Solution depth   : " << solutionState->getDepth() << " actions" << endl
             << "Memory           : " << volumeOfAllocatedMemory << " memory units" << endl
             << "Examined States  : " << numberOfExaminedStates << " states";

    } else {
        cout << "The puzzle is unsolvable!";
    }
    cout << endl << endl;

}

void SearchExpert::destructSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms) {
    for (SearchAlgorithm *searchAlgorithm : (*searchAlgorithms)) {
        delete searchAlgorithm;
    }

    delete searchAlgorithms;
}
