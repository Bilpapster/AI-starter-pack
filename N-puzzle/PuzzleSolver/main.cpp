#include <iostream>
#include <random>
#include <N-puzzle/Statistics/StatisticsWizard.h>
#include "N-puzzle/SearchAlgorithms/SearchExpert.h"

/**
 * The driving code for the N-puzzle solver. Just initializes the
 * initial snapshot of the puzzle and the goal one, invoking the
 * search functions to run on them and solve the puzzle.
 *
 * @return 0 as normal execution code
 */
int main() {

    bool solveRandomPuzzle = true;  // set to false for the default puzzle

    State *initial = new State();
    State *goal = new State(true);

    if (solveRandomPuzzle) StatisticsWizard::initializeRandomPuzzle(initial);

    cout << "Randomly generated puzzle to solve:" << endl << initial->toString() << endl;

    SearchExpert::executeAvailableAlgorithms(initial, goal);

    delete initial;
    delete goal;

    return 0;
}
