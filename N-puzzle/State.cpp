#include <iostream>
#include "State.h"

#define BLANK 0

State::State() {
    setActionName("");
    setPrevious(nullptr);
}

State::State(bool isFinal) : State() {
    if (isFinal) { this->setFinal(); }
}

bool State::moveBlankTileUp(State &nextState) {
    if (blankTileRow > 0) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithUp() << " down." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

unsigned short int State::swapBlankTileWithUp() {
    unsigned short int numberMovingDown = table[blankTileRow - 1][blankTileColumn];
    table[blankTileRow][blankTileColumn] = numberMovingDown;
    table[--blankTileRow][blankTileColumn] = BLANK;
    return numberMovingDown;
}

bool State::moveBlankTileDown(State &nextState) {
    if (blankTileRow < HEIGHT - 1) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithDown() << " up." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

unsigned short int State::swapBlankTileWithDown() {
    unsigned short int numberMovingUp = table[blankTileRow + 1][blankTileColumn];
    table[blankTileRow][blankTileColumn] = numberMovingUp;
    table[++blankTileRow][blankTileColumn] = BLANK;
    return numberMovingUp;
}

bool State::moveBlankTileLeft(State &nextState) {
    if (blankTileColumn > 0) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithLeft() << " right." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

unsigned short int State::swapBlankTileWithLeft() {
    unsigned short int numberMovingRight = table[blankTileRow][blankTileColumn - 1];
    table[blankTileRow][blankTileColumn] = numberMovingRight;
    table[blankTileRow][--blankTileColumn] = BLANK;
    return numberMovingRight;
}

bool State::moveBlankTileRight(State &nextState) {
    if (blankTileColumn < WIDTH - 1) {
        nextState = *this;
        stringstream actionDescription;
        actionDescription << "Move tile number " << nextState.swapBlankTileWithRight() << " left." << endl;
        nextState.setActionName(actionDescription.str());
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

unsigned short int State::swapBlankTileWithRight() {
    unsigned short int numberMovingLeft = table[blankTileRow][blankTileColumn + 1];
    table[blankTileRow][blankTileColumn] = numberMovingLeft;
    table[blankTileRow][++blankTileColumn] = BLANK;
    return numberMovingLeft;
}

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

unsigned short int State::getDepth() {
    unsigned short int depth = 0;
    State *previousState = this;
    while (previousState->previous != nullptr) {
        previousState = previousState->previous;
        depth++;
    }
    return depth;
}

string State::toString() const {
    stringstream stateDescription;
    for (unsigned short int row = 0; row < HEIGHT; row++) {
        for (unsigned short int column = 0; column < WIDTH; column++) {
            stateDescription << this->table[row][column] << " ";
        }
        stateDescription << endl;
    }
    stateDescription << "Blank tile: ("
                     << this->blankTileRow << ", " << this->blankTileColumn
                     << ")" << endl;
    return stateDescription.str();
}

unsigned short int State::heuristic(State *goalState) {

    unsigned short int distance = 0, row, correctRow, column, correctColumn;
    table[blankTileRow][blankTileColumn] = WIDTH * HEIGHT;

    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            correctRow = (this->table[row][column] - 1) / WIDTH;
            correctColumn = (this->table[row][column] - 1) % WIDTH;
            distance += abs(row - correctRow) + abs(column - correctColumn);
        }
    }
    table[blankTileRow][blankTileColumn] = BLANK;
    return distance;
}

void State::setHeuristicValue(unsigned short int value) {
    heuristicValue = value;
}

unsigned short int State::getHeuristicValue() const {
    return heuristicValue;
}

string State::getUniqueRepresentation() const {
    stringstream dashboardRepresentation;
    for (auto &row : this->table) {
        for (unsigned short column : row) {
            dashboardRepresentation << column << "-";
        }
    }
    return dashboardRepresentation.str();
}

void State::setFinal() {
    unsigned short number = 1;
    for (auto &row : this->table) {
        for (unsigned short &column : row) {
            column = number++;
        }
    }
    this->blankTileRow = HEIGHT - 1;
    this->blankTileColumn = WIDTH - 1;
    this->table[blankTileRow][blankTileColumn] = BLANK;
}

State &State::operator=(const State &other) {
    if (this == &other) { return *this; }

    unsigned short row, column;
    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            this->table[row][column] = other.table[row][column];
        }
    }
    this->blankTileRow = other.blankTileRow;
    this->blankTileColumn = other.blankTileColumn;
    this->previous = other.previous;
    this->actionName = other.actionName;
    return *this;
}

bool State::operator==(const State &other) const {
    if (this->blankTileRow != other.blankTileRow) { return false; }

    if (this->blankTileColumn != other.blankTileColumn) { return false; }

    unsigned short row, column;
    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            if (this->table[row][column] != other.table[row][column]) { return false; }
        }
    }
    return true;
}

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




