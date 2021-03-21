#ifndef AI_STARTER_PACK_IN_CPP_STATE_H
#define AI_STARTER_PACK_IN_CPP_STATE_H

#define WIDTH  100
#define HEIGHT  100

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class State {
public:
    State();

    State(int x, int y, bool lights);

    void setFree(int x, int y, bool flag);

    int getY() const;

    int getX() const;

    bool isFree(int x, int y);

    void setX(int x);

    void setY(int y);

    State operator=(State other);

    bool operator==(const State &other) const;

    friend bool operator<(const State &left, const State &right);

    string toString() const;

    bool turnOn(State &nextState);

    bool turnOff(State &nextState);

    bool goUp(State &nextState);

    bool goDown(State &nextState);

    bool goLeft(State &nextState);

    bool goRight(State &nextState);

    vector<State *> expand();

    int getDepth();

    void setHeuristicValue(double);

    double getHeuristicValue();

    int heuristic(State *);

    void setActionName(string s) { actionName = s; }

    string getActionName() const { return actionName; }

    void setPrevious(State *p) { previous = p; }

    State *getPrevious() const { return previous; }

    unsigned long getKey() {
        unsigned long k = xCoordinate * 1000000 + yCoordinate * 1000;
        if (lights) k += 1;
        return k;
    }

    friend ostream &operator<<(ostream &, const State &);

protected:

private:
    int xCoordinate, yCoordinate;
    bool free[WIDTH][HEIGHT];
    double heuristicValue;
    string actionName;
    State *previous;
    bool lights;
};

class StateComparator {
public:
    int operator()(State *leftStatePointer, State *rightStatePointer) const {
        return leftStatePointer->getHeuristicValue() > rightStatePointer->getHeuristicValue();
    }
};

#endif //AI_STARTER_PACK_IN_CPP_STATE_H
