#include <iostream>
#include "State.h"

#define BLANK 0

State::State() {
    setActionName("");
    setPrevious(nullptr);

//    for (int i = 0; i < WIDTH; i++)
//        for (int j = 0; j < HEIGHT; j++)
//            free[i][j] = true;
}

State::State(int x, int y, bool lights) : State() {
//    xCoordinate = x;
//    yCoordinate = y;
//    this->lights = lights;
//    lights = true;

//    for (int i = 0; i < WIDTH; i++)
//        for (int j = 0; j < HEIGHT; j++)
//            free[i][j] = true;
//    setActionName("");
//    setPrevious(nullptr);

}

void State::setFree(int x, int y, bool flag) {
    free[x][y] = flag;
}

int State::getY() const {
    return yCoordinate;
}

int State::getX() const {
    return xCoordinate;
}

bool State::isFree(int x, int y) {
    return free[x][y];
}

void State::setX(int x) {
    xCoordinate = x;
}

void State::setY(int y) {
    yCoordinate = y;
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

//    this->lights = other.lights;
//    this->xCoordinate = other.xCoordinate;
//    this->yCoordinate = other.yCoordinate;
//    this->previous = other.previous;
//    this->actionName = other.actionName;
//    return *this;
}

bool State::operator==(const State &other) const {
//    return this->getUniqueRepresentation() == other.getUniqueRepresentation();

    if (this->blankTileRow != other.blankTileRow) {
        return false;
    }

    if (this->blankTileColumn != other.blankTileColumn) {
        return false;
    }

    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            if (this->table[row][column] != other.table[row][column]) {
                return false;
            }
        }
    }
    return true;
}

bool operator<(const State &left, const State &right) {
    return (left.getHeuristicValue() < right.getHeuristicValue());
//    return (left.toString() < right.toString());
}

string State::toString() const {

    stringstream output;
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
                output << this->table[row][column] << " ";
        }
        output << endl;
    }
    output << "Blank tile: (" << this->blankTileRow << ", " << this->blankTileColumn << ")" << endl;
    return output.str();

//    stringstream stateDescription;
//    stateDescription << xCoordinate << "-" << yCoordinate << "-";
//    if (lights)
//        stateDescription << "true";
//    else
//        stateDescription << "false";
//    return stateDescription.str();
}

int State::getDepth() {
    int depth = 0;
    State *previousState = this;
    while (previousState->previous != nullptr) {
        previousState = previousState->previous;
        depth++;
    }
    return depth;
    //return path.size();
}

bool State::turnOn(State &nextState) {
    if (!lights) {
        nextState = *this;
        nextState.lights = true;
        nextState.setActionName("SwitchOn");
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

bool State::turnOff(State &nextState) {
    if (lights) {
        nextState = *this;
        nextState.lights = false;
        nextState.setActionName("SwitchOff");
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

bool State::moveBlankTileUp(State &nextState) {
    if (blankTileRow > 0) {
        nextState = *this;
        int temporary = nextState.table[nextState.blankTileRow - 1][nextState.blankTileColumn];
        nextState.table[nextState.blankTileRow - 1][nextState.blankTileColumn] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileRow--;
        nextState.setPrevious(this);
        return true;
    }
    return false;

//    if (getY() > 0 && isFree(getX(), getY() - 1)) {
//        nextState = *this;
//        nextState.setY(nextState.getY() - 1);
//        nextState.setActionName("Up");
//        nextState.setPrevious(this);
//        return true;
//    }
//    return false;
}

bool State::moveBlankTileDown(State &nextState) {
    if (blankTileRow < HEIGHT - 1) {
        // TODO: add action name to all the movements
        nextState = *this;
        int temporary = nextState.table[nextState.blankTileRow + 1][nextState.blankTileColumn];
        nextState.table[nextState.blankTileRow + 1][nextState.blankTileColumn] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileRow++;
        nextState.setPrevious(this);
        return true;
    }
    return false;

//    if (getY() < HEIGHT - 1 && isFree(getX(), getY() + 1)) {
//        nextState = *this;
//        nextState.setY(nextState.getY() + 1);
//        nextState.setActionName("Down");
//        nextState.setPrevious(this);
//        return true;
//    }
//    return false;
}

bool State::moveBlankTileLeft(State &nextState) {
    if (blankTileColumn > 0) {
        nextState = *this;
        int temporary = nextState.table[nextState.blankTileRow][nextState.blankTileColumn - 1];
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn - 1] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileColumn--;
        nextState.setPrevious(this);
        return true;
    }
    return false;

//    if (getX() > 0 && isFree(getX() - 1, getY())) {
//        nextState = *this;
//        nextState.setX(nextState.getX() - 1);
//        nextState.setActionName("Left");
//        nextState.setPrevious(this);
//        return true;
//    }
//    return false;
}

bool State::moveBlankTileRight(State &nextState) {
    if (blankTileColumn < WIDTH - 1) {
        nextState = *this;

        int temporary = nextState.table[nextState.blankTileRow][nextState.blankTileColumn + 1];
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn + 1] = BLANK;
        nextState.table[nextState.blankTileRow][nextState.blankTileColumn] = temporary;
        nextState.blankTileColumn++;
        nextState.setPrevious(this);
        return true;
    }
    return false;

//    if (getX() < WIDTH - 1 && isFree(getX() + 1, getY())) {
//        nextState = *this;
//        nextState.setX(nextState.getX() + 1);
//        nextState.setActionName("Right");
//        nextState.setPrevious(this);
//
// //        nextState.path.push_back("Right");
//        return true;
//    }
//    return false;
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
//    cout << endl;

//    child = new State(*this);
//    if (turnOn(*child))
//        children.push_back(child);
//    else
//        delete child;
//    child = new State(*this);
//    if (turnOff(*child))
//        children.push_back(child);
//    else
//        delete child;
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

//    int distance = abs(goalState->xCoordinate - xCoordinate) + abs(goalState->yCoordinate - yCoordinate);
//    if (lights != goalState->lights) {
//        distance++;
//    }
//    return distance;
};

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


