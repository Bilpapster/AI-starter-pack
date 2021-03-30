#include <iostream>
#include <sstream>
#include "State.h"

#define BLANK 0

/**
 * Constructs an idle state. The parent state is set to null and
 * the action name is initialized to a blank string.
 * The puzzle has the default form, the one presented in the
 * wording of the assignment.
 */
State::State() {
    setActionName("");
    setPrevious(nullptr);
}

/**
 * Constructs a state with given attribute. In case the state is
 * defined as final, the puzzle is initialized to the default
 * solution form, where the numbers are placed in ascending order
 * (starting from 1) and the blank tile is at the bottom left corner
 * of the puzzle.
 *
 * @param isFinal the flag that determines whether the state will be
 *                initialized as final or default (as presented in
 *                the wording of the assignment).
 */
State::State(bool isFinal) : State() {
    if (isFinal) { this->setFinal(); }
}

State::State(const unsigned short *array) : State() {
    this->setFromArray(array);
}

/**
 * Checks whether moving the blank tile one row up is a valid action,
 * based on the current state.
 *
 * In case the action is valid, the passed reference derives the current
 * state, when the up-movement is applied on it. At the end of the
 * function execution, the passed reference has all the appropriate
 * attributes that come along with the up-movement.
 *
 * In case the action is invalid, the passed reference remains intact.
 *
 * @param nextState the state that emerges when applying an up-movement
 *                  on the current state. It is passed by reference and
 *                  edited inside the function, in case the up-movement
 *                  is valid.
 *                  Otherwise, no changes are made on the passed reference.
 * @return true if the up-movement is valid, else false.
 */
bool State::moveBlankTileUp(State &nextState) {
    if (blankTileRow > 0) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithUp()
                          << " down." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

/**
 * A private, auxiliary method that is utilized when executing moveUp action.
 * The function swaps the blank tile with the one place right above it
 * (same column, previous row). Returns the number of the tile moved,
 * except for the blank one.
 *
 * @return the number of the tile that was exchanged with the blank one.
 */
unsigned short int State::swapBlankTileWithUp() {
    unsigned short int numberMovingDown = board[blankTileRow - 1][blankTileColumn];
    board[blankTileRow][blankTileColumn] = numberMovingDown;
    board[--blankTileRow][blankTileColumn] = BLANK;
    return numberMovingDown;
}

/**
 * Checks whether moving the blank tile one row down is a valid action,
 * based on the current state.
 *
 * In case the action is valid, the passed reference derives the current
 * state, when the down-movement is applied on it. At the end of the
 * function execution, the passed reference has all the appropriate
 * attributes that come along with the down-movement.
 *
 * In case the action is invalid, the passed reference remains intact.
 *
 * @param nextState the state that emerges when applying an down-movement
 *                  on the current state. It is passed by reference and
 *                  edited inside the function, in case the down-movement
 *                  is valid.
 *                  Otherwise, no changes are made on the passed reference.
 * @return true if the down-movement is valid, else false.
 */
bool State::moveBlankTileDown(State &nextState) {
    if (blankTileRow < HEIGHT - 1) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithDown()
                          << " up." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

/**
 * A private, auxiliary method that is utilized when executing moveDown action.
 * The function swaps the blank tile with the one place right below it
 * (same column, next row). Returns the number of the tile moved,
 * except for the blank one.
 *
 * @return the number of the tile that was exchanged with the blank one.
 */
unsigned short int State::swapBlankTileWithDown() {
    unsigned short int numberMovingUp = board[blankTileRow + 1][blankTileColumn];
    board[blankTileRow][blankTileColumn] = numberMovingUp;
    board[++blankTileRow][blankTileColumn] = BLANK;
    return numberMovingUp;
}

/**
 * Checks whether moving the blank tile one column left is a valid action,
 * based on the current state.
 *
 * In case the action is valid, the passed reference derives the current
 * state, when the left-movement is applied on it. At the end of the
 * function execution, the passed reference has all the appropriate
 * attributes that come along with the left-movement.
 *
 * In case the action is invalid, the passed reference remains intact.
 *
 * @param nextState the state that emerges when applying an left-movement
 *                  on the current state. It is passed by reference and
 *                  edited inside the function, in case the left-movement
 *                  is valid.
 *                  Otherwise, no changes are made on the passed reference.
 * @return true if the left-movement is valid, else false.
 */
bool State::moveBlankTileLeft(State &nextState) {
    if (blankTileColumn > 0) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithLeft()
                          << " right." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

/**
 * A private, auxiliary method that is utilized when executing moveLeft action.
 * The function swaps the blank tile with the one place right on its left
 * (same row, previous column). Returns the number of the tile moved,
 * except for the blank one.
 *
 * @return the number of the tile that was exchanged with the blank one.
 */
unsigned short int State::swapBlankTileWithLeft() {
    unsigned short int numberMovingRight = board[blankTileRow][blankTileColumn - 1];
    board[blankTileRow][blankTileColumn] = numberMovingRight;
    board[blankTileRow][--blankTileColumn] = BLANK;
    return numberMovingRight;
}

/**
 * Checks whether moving the blank tile one column right is a valid action,
 * based on the current state.
 *
 * In case the action is valid, the passed reference derives the current
 * state, when the right-movement is applied on it. At the end of the
 * function execution, the passed reference has all the appropriate
 * attributes that come along with the right-movement.
 *
 * In case the action is invalid, the passed reference remains intact.
 *
 * @param nextState the state that emerges when applying an right-movement
 *                  on the current state. It is passed by reference and
 *                  edited inside the function, in case the right-movement
 *                  is valid.
 *                  Otherwise, no changes are made on the passed reference.
 * @return true if the right-movement is valid, else false.
 */
bool State::moveBlankTileRight(State &nextState) {
    if (blankTileColumn < WIDTH - 1) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithRight()
                          << " left." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

/**
 * A private, auxiliary method that is utilized when executing moveRight action.
 * The function swaps the blank tile with the one place right on its right
 * (same row, next column). Returns the number of the tile moved,
 * except for the blank one.
 *
 * @return the number of the tile that was exchanged with the blank one.
 */
unsigned short int State::swapBlankTileWithRight() {
    unsigned short int numberMovingLeft = board[blankTileRow][blankTileColumn + 1];
    board[blankTileRow][blankTileColumn] = numberMovingLeft;
    board[blankTileRow][++blankTileColumn] = BLANK;
    return numberMovingLeft;
}

/**
 * Executes all necessary actions in order to expand the current state and
 * produce the derived states. The derived states emerge when applying all
 * valid actions on the current state.
 *
 * @return a vector containing all the derived states from the current.
 *         These states emerge when applying all valid actions on the
 *         current state.
 */
vector<State *> State::expand() {
    vector<State *> children;
    State *child;
    child = new State();
    if (moveBlankTileUp(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    child = new State();
    if (moveBlankTileDown(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    child = new State();
    if (moveBlankTileLeft(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    child = new State();
    if (moveBlankTileRight(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    return children;
}

/**
 * Simple setter for the parent state of the current one. The setter slightly
 * declines from the strict setter model, that dictates the function to only
 * act on the previous field: In case the previous state is not null, the
 * setter also updates the depth of the current node, adding one edge to the
 * depth of the given parent.
 *
 * @param previousState the parent state of the current node.
 */
void State::setPrevious(State *previousState) {
    this->previous = previousState;
    if (previousState) { this->depth = previousState->depth + 1; }
}

/**
 * A utility function that forms the string representation of the current
 * state. The string contains the puzzle snapshot as a board, as well as
 * the row and column position of the blank tile.
 *
 * @return the string representation of the current state.
 */
string State::toString() const {
    stringstream stateDescription;
    for (unsigned short int row = 0; row < HEIGHT; row++) {
        for (unsigned short int column = 0; column < WIDTH; column++) {
            stateDescription << this->board[row][column] << " ";
        }
        stateDescription << endl;
    }
    stateDescription << "Blank tile: ("
                     << this->blankTileRow << ", " << this->blankTileColumn
                     << ")" << endl;
    return stateDescription.str();
}

/**
 * Evaluates the manhattan distance of all the puzzle tiles.
 * The blank tile is included in the calculations, taken that
 * its correct placement is on the bottom right corner of the
 * puzzle.
 *
 * @return the sum of the manhattan distances of all puzzle tiles.
 */
unsigned short int State::manhattanDistance() {

    unsigned short int distance = 0, row, correctRow, column, correctColumn;
    board[blankTileRow][blankTileColumn] = WIDTH * HEIGHT;

    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            correctRow = (this->board[row][column] - 1) / WIDTH;
            correctColumn = (this->board[row][column] - 1) % WIDTH;
            distance += abs(row - correctRow) + abs(column - correctColumn);
        }
    }
    board[blankTileRow][blankTileColumn] = BLANK;
    return distance;
}

/**
 * Evaluates the number of misplaced tiles in the current snapshot of
 * the puzzle. A tile is considered misplaced when either its row or
 * column does not match with the goal state. A puzzle snapshot is
 * considered goal state when all tiles are in ascending order (starting
 * from 1) and the blank tile is placed on the bottom left corner of the
 * puzzle.
 *
 * @return the number of misplaced tiles.
 */
unsigned short int State::misplacedTiles() {
    unsigned short int tilesOutOfPlace = 0, row, correctRow, column, correctColumn;
    board[blankTileRow][blankTileColumn] = WIDTH * HEIGHT;

    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            correctRow = (this->board[row][column] - 1) / WIDTH;
            correctColumn = (this->board[row][column] - 1) % WIDTH;
            if (row != correctRow || column != correctColumn) tilesOutOfPlace++;
        }
    }
    board[blankTileRow][blankTileColumn] = BLANK;
    return tilesOutOfPlace;
}

/**
 * Constructs the unique string encoding of the current state.
 * The string contains the tiles from the upper left corner
 * up to the bottom right corner, separated by dash.
 *
 * @return the unique string encoding of the current state.
 */
string State::getUniqueEncoding() const {
    stringstream dashboardRepresentation;
    for (auto &row : this->board) {
        for (unsigned short column : row) {
            dashboardRepresentation << column << "-";
        }
    }
    return dashboardRepresentation.str();
}

/**
 * A simple utility method that sets the current state to final.
 * The numbers are placed in ascending order (starting from 1)
 * and the blank tile is placed on the bottom right corner of
 * the puzzle.
 */
void State::setFinal() {
    unsigned short number = 1;
    for (auto &row : this->board) {
        for (unsigned short &column : row) {
            column = number++;
        }
    }
    this->blankTileRow = HEIGHT - 1;
    this->blankTileColumn = WIDTH - 1;
    this->board[blankTileRow][blankTileColumn] = BLANK;
}

void State::setFromArray(const unsigned short *array) {
    unsigned short row, column, index = 0, number;

    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            number = array[index++];
            this->board[row][column] = number;
            if (number == BLANK) {
                this->blankTileRow = row;
                this->blankTileColumn = column;
            }
        }
    }
}

/**
 * Overloaded assign operator for state objects.
 * Copies the fields as well as the puzzle dashboard.
 * @param other the state to copy attributes from.
 *
 * @return the current state object.
 */
State &State::operator=(const State &other) {
    if (this == &other) { return *this; }

    unsigned short row, column;
    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            this->board[row][column] = other.board[row][column];
        }
    }
    this->blankTileRow = other.blankTileRow;
    this->blankTileColumn = other.blankTileColumn;
    this->depth = other.depth;
    this->previous = other.previous;
    this->actionName = other.actionName;
    return *this;
}

/**
 * Overloaded equality operator for two state objects.
 * The state objects are deemed equal only in case the numbers
 * in their puzzle snapshot are in the same order.
 *
 * @param other the state object to compare with the current.
 * @return true if the puzzle snapshot is the same between the
 *         two states, else false.
 */
bool State::operator==(const State &other) const {
    if (this->blankTileRow != other.blankTileRow) { return false; }

    if (this->blankTileColumn != other.blankTileColumn) { return false; }

    unsigned short row, column;
    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            if (this->board[row][column] != other.board[row][column]) { return false; }
        }
    }
    return true;
}

/**
 * Overloaded insertion operator for a state object. The constructed
 * stream contains the actions' descriptions in order to reach the current
 * state, starting from the initial one.
 * @param stream
 * @param stateToPrint the state to stream
 * @return the actions' descriptions starting from the initial one up to the current.
 */
ostream &operator<<(ostream &stream, const State &stateToPrint) {
    string actionSeries = stateToPrint.getActionName();
    State *previousState = stateToPrint.getPrevious();

    while (previousState != nullptr) {
        actionSeries.insert(0, previousState->getActionName());
        previousState = previousState->getPrevious();
    }
    stream << actionSeries;
    return stream;
}




