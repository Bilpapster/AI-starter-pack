#include <iostream>
#include "State.h"

#define BLANK 0

State::State() {
    setActionName("");
    setPrevious(nullptr);
}

State &State::operator=(State other) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
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

    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            if (this->table[row][column] != other.table[row][column]) { return false; }
        }
    }
    return true;
}

string State::toString() const {
    stringstream stateDescription;
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            stateDescription << this->table[row][column] << " ";
        }
        stateDescription << endl;
    }
    stateDescription << "Blank tile: ("
                     << this->blankTileRow << ", " << this->blankTileColumn
                     << ")" << endl;
    return stateDescription.str();
}

int State::getDepth() {
    int depth = 0;
    State *previousState = this;
    while (previousState->previous != nullptr) {
        previousState = previousState->previous;
        depth++;
    }
    return depth;
}

bool State::moveBlankTileUp(State &nextState) {
    if (blankTileRow > 0) {
        nextState = *this;
        int temporary = nextState.table[nextState.blankTileRow - 1][nextState.blankTileColumn];
        nextState.table[nextState.blankTileRow - 1][nextState.blankTileColumn] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileRow--;
        nextState.setPrevious(this);

        stringstream actionName;
        actionName << "Move tile number " << temporary << " down.";
        nextState.setActionName(actionName.str());
        return true;
    }
    return false;
}

bool State::moveBlankTileDown(State &nextState) {
    if (blankTileRow < HEIGHT - 1) {
        nextState = *this;
        int temporary = nextState.table[nextState.blankTileRow + 1][nextState.blankTileColumn];
        nextState.table[nextState.blankTileRow + 1][nextState.blankTileColumn] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileRow++;
        nextState.setPrevious(this);

        stringstream actionName;
        actionName << "Move tile number " << temporary << " up.";
        nextState.setActionName(actionName.str());
        return true;
    }
    return false;
}

bool State::moveBlankTileLeft(State &nextState) {
    if (blankTileColumn > 0) {
        nextState = *this;
        int temporary = nextState.table[nextState.blankTileRow][nextState.blankTileColumn - 1];
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn - 1] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileColumn--;
        nextState.setPrevious(this);

        stringstream actionName;
        actionName << "Move tile number " << temporary << " right.";
        nextState.setActionName(actionName.str());
        return true;
    }
    return false;
}

bool State::moveBlankTileRight(State &nextState) {
    if (blankTileColumn < WIDTH - 1) {
        nextState = *this;

        int temporary = nextState.table[nextState.blankTileRow][nextState.blankTileColumn + 1];
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn + 1] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileColumn++;
        nextState.setPrevious(this);

        stringstream actionName;
        actionName << "Move tile number " << temporary << " left.";
        nextState.setActionName(actionName.str());
        return true;
    }
    return false;
}

vector<State *> State::expand() {
    vector<State *> children;
    State *child;
    child = new State(*this);
    if (moveBlankTileUp(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    child = new State(*this);
    if (moveBlankTileDown(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    child = new State(*this);
    if (moveBlankTileLeft(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    child = new State(*this);
    if (moveBlankTileRight(*child)) {
        children.push_back(child);
    } else {
        delete child;
    }
    return children;
}

int State::heuristic(State *goalState) const {

    int distance = 0;

    for (int row = 0; row <= blankTileRow; row++) {
        for (int column = 0; column < blankTileColumn; column++) {
            long long int correctRow = (this->table[row][column] - 1) / WIDTH;
            long long int correctColumn = (this->table[row][column] - 1) % WIDTH;
            distance += abs(row - correctRow) + abs(column - correctColumn);
        }
    }

    distance += abs(blankTileRow - HEIGHT + 1) + abs(blankTileColumn - WIDTH + 1);

    for (int row = blankTileRow; row < HEIGHT; row++) {
        for (int column = blankTileColumn + 1; column < WIDTH; column++) {
            long long int correctRow = (this->table[row][column] - 1) / WIDTH;
            long long int correctColumn = (this->table[row][column] - 1) % WIDTH;
            distance += abs(row - correctRow) + abs(column - correctColumn);
        }
    }
    return distance;
}

void State::setHeuristicValue(double value) {
    heuristicValue = value;
}

double State::getHeuristicValue() const {
    return heuristicValue;
}

ostream &operator<<(ostream &stream, const State &stateToPrint) {
    string stringToPrint = "";

    stringToPrint = stateToPrint.getActionName();
    State *previousState = stateToPrint.getPrevious();

    while (previousState != nullptr) {
        stringToPrint = previousState->getActionName() + " " + stringToPrint;
        previousState = previousState->getPrevious();
    }
    stream << stringToPrint;
    return stream;
}

string State::getUniqueRepresentation() const {
    stringstream dashboardRepresentation;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            dashboardRepresentation << this->table[row][column] << "-";
        }
    }
    return dashboardRepresentation.str();
}

void State::setFinal() {
    int number = 1;
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            this->table[row][column] = number++;
        }
    }
    this->blankTileRow = HEIGHT - 1;
    this->blankTileColumn = WIDTH - 1;
    this->table[blankTileRow][blankTileColumn] = BLANK;
}


