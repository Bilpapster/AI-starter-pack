#include <iostream>
#include "PuzzleSolver.h"
#include "N-puzzle/StateModel/State.h"
#include "N-puzzle/Statistics/StatisticsWizard.h"
#include "N-puzzle/SearchAlgorithms/SearchExpert.h"

/**
 * The driving code for the N-puzzle solver. Just initializes the
 * initial snapshot of the puzzle and the goal one, invoking the
 * search functions to run on them and solve the puzzle.
 */
void PuzzleSolver::start() {
    State *initial = new State();
    State *goal = new State(true);

    if (solveRandomPuzzle) StatisticsWizard::initializeRandomPuzzle(initial);

    cout << "Randomly generated puzzle to solve:" << endl << initial->toString() << endl;

    SearchExpert::executeAvailableAlgorithms(initial, goal);

    delete initial;
    delete goal;
}
