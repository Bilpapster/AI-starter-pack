#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
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
        double millisElapsedOnSearch = (clock() - start);
//        printResultsToConsole(searchAlgorithm, solution,
//                              numberOfExaminedStates,
//                              volumeOfAllocatedMemory,
//                              millisElapsedOnSearch);

        printResultsToFile(searchAlgorithm, solution,
                              numberOfExaminedStates,
                              volumeOfAllocatedMemory,
                              millisElapsedOnSearch);
    }
    changeLineInFile();
    destructSearchAlgorithms(searchAlgorithms);

}

void SearchExpert::initializeSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms) {
    searchAlgorithms->push_back(new DepthFirstSearchAlgorithm());
    searchAlgorithms->push_back(new BreadthFirstSearchAlgorithm());
    searchAlgorithms->push_back(new BestFirstSearchAlgorithm());
    searchAlgorithms->push_back(new AStarSearchAlgorithm());
}

void SearchExpert::printResultsToConsole(const SearchAlgorithm *searchAlgorithm,
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

void SearchExpert::printResultsToFile(const SearchAlgorithm *searchAlgorithm, const State *solutionState,
                                      const long long int &numberOfExaminedStates,
                                      const long long int &volumeOfAllocatedMemory,
                                      const double &millisElapsedOnSearch) {
    ofstream outputFile;
    outputFile.open("Reports.txt", ios_base::app);
    if (solutionState) {
        outputFile << numberOfExaminedStates << " "
                   << volumeOfAllocatedMemory << " "
                   << solutionState->getDepth() << " ";
    } else
        outputFile << "Unsolvable" << " ";
    outputFile.close();
}

void SearchExpert::destructSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms) {
    for (SearchAlgorithm *searchAlgorithm : (*searchAlgorithms)) {
        delete searchAlgorithm;
    }

    delete searchAlgorithms;
}

void SearchExpert::changeLineInFile() {
    ofstream outputFile;
    outputFile.open("Reports.txt", ios_base::app);
    outputFile << endl;
    outputFile.close();

}
