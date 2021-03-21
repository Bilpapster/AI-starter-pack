#include "State.h"

State::State() {
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            free[i][j] = true;
    setActionName("");
    setPrevious(nullptr);
}

State::State(int x, int y, bool lights) : State() {
    xCoordinate = x;
    yCoordinate = y;
    this->lights = lights;
    lights = true;

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

State State::operator=(State other) {
    this->lights = other.lights;
    this->xCoordinate = other.xCoordinate;
    this->yCoordinate = other.yCoordinate;
    this->previous = other.previous;
    this->actionName = other.actionName;
    return *this;
}

bool State::operator==(const State &other) const {
    return (xCoordinate == other.xCoordinate && yCoordinate == other.yCoordinate && lights == other.lights);
}

bool operator<(const State &left, const State &right) {
    return (left.toString() < right.toString());
}

string State::toString() const {
    stringstream stateDescription;
    stateDescription << xCoordinate << "-" << yCoordinate << "-";
    if (lights)
        stateDescription << "true";
    else
        stateDescription << "false";
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

bool State::goUp(State &nextState) {
    if (getY() > 0 && isFree(getX(), getY() - 1)) {
        nextState = *this;
        nextState.setY(nextState.getY() - 1);
        nextState.setActionName("Up");
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

bool State::goDown(State &nextState) {
    if (getY() < HEIGHT - 1 && isFree(getX(), getY() + 1)) {
        nextState = *this;
        nextState.setY(nextState.getY() + 1);
        nextState.setActionName("Down");
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

bool State::goLeft(State &nextState) {
    if (getX() > 0 && isFree(getX() - 1, getY())) {
        nextState = *this;
        nextState.setX(nextState.getX() - 1);
        nextState.setActionName("Left");
        nextState.setPrevious(this);
        return true;
    }
    return false;
}

bool State::goRight(State &nextState) {
    if (getX() < WIDTH - 1 && isFree(getX() + 1, getY())) {
        nextState = *this;
        nextState.setX(nextState.getX() + 1);
        nextState.setActionName("Right");
        nextState.setPrevious(this);

//        nextState.path.push_back("Right");
        return true;
    }
    return false;
}

vector<State *> State::expand() {
    vector<State *> children;
    State *child;
    child = new State(*this);
    if (goUp(*child))
        children.push_back(child);
    else
        delete child;
    child = new State(*this);
    if (goDown(*child))
        children.push_back(child);
    else
        delete child;
    child = new State(*this);
    if (goLeft(*child))
        children.push_back(child);
    else
        delete child;
    child = new State(*this);
    if (goRight(*child))
        children.push_back(child);
    else
        delete child;
    child = new State(*this);
    if (turnOn(*child))
        children.push_back(child);
    else
        delete child;
    child = new State(*this);
    if (turnOff(*child))
        children.push_back(child);
    else
        delete child;
    return children;
}

int State::heuristic(State *goalState) {
    int distance = abs(goalState->xCoordinate - xCoordinate) + abs(goalState->yCoordinate - yCoordinate);
    if (lights != goalState->lights)
        distance++;
    return distance;
};

void State::setHeuristicValue(double value) {
    heuristicValue = value;
}

double State::getHeuristicValue() {
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


