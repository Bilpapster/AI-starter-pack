#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <ctime>
#include "State.h"
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

State *DFS2(State *initial, State *goal, long long &examined, long long &mem) {
    stack<State *> agenda;
    unordered_map<unsigned long, State *> closed;

    agenda.push(initial);
    examined = 0;
    mem = 1;
    while (agenda.size() > 0) {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        State *s = agenda.top();
        agenda.pop();
        if (closed.count(s->getKey()) == 0) {
            examined++;
            if (*s == *goal)
                return s;
            pair<unsigned long, State *> k(s->getKey(), s);
            closed.insert(k);
            vector<State *> children = s->expand();
            for (unsigned int i = 0; i < children.size(); i++)
                if (closed.count(children[i]->getKey()) == 0)
                    agenda.push(children[i]);
        }
    }
    return nullptr;
}

State *BFS2(State *initial, State *goal, long long &examined, long long &mem) {
    queue<State *> agenda;
    unordered_map<unsigned long, State *> closed;

    agenda.push(initial);
    examined = 0;
    mem = 1;
    while (agenda.size() > 0) {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        State *s = agenda.front();
        agenda.pop();
        if (closed.count(s->getKey()) == 0) {
            examined++;
            if (*s == *goal)
                return s;
            pair<unsigned long, State *> k(s->getKey(), s);
            closed.insert(k);
            vector<State *> children = s->expand();
            for (unsigned int i = 0; i < children.size(); i++)
                if (closed.count(children[i]->getKey()) == 0)
                    agenda.push(children[i]);
        }
    }
    return nullptr;
}

State *BFS(State *initial, State *goal, long long &examined, long long &mem) {
    queue<State *> agenda;
    vector<State> closed;

    agenda.push(initial);
    examined = 0;
    mem = 1;
    while (agenda.size() > 0) {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        State *s = agenda.front();
        agenda.pop();
        if (find(closed.begin(), closed.end(), *s) == closed.end()) {
            examined++;
            if (*s == *goal)
                return s;
            closed.push_back(*s);
            vector<State *> children = s->expand();
            for (unsigned int i = 0; i < children.size(); i++) {
                if (find(closed.begin(), closed.end(), *children[i]) == closed.end())
                    agenda.push(children[i]);
            }
        }
    }
    return nullptr;
}

State *BestFS2(State *initial, State *goal, long long &examined, long long &mem) {
    priority_queue<State *, vector<State *>, StateComparator> agenda;
    unordered_map<unsigned long, State *> closed;
    agenda.push(initial);
    examined = 0;
    mem = 1;
    while (agenda.size() > 0) {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        State *s = agenda.top();
        agenda.pop();

        if (closed.count(s->getKey()) == 0) {
            examined++;
            if (*s == *goal)
                return s;
            pair<unsigned long, State *> k(s->getKey(), s);
            closed.insert(k);
            vector<State *> children = s->expand();
            for (unsigned int i = 0; i < children.size(); i++) {
                if (closed.count(children[i]->getKey()) == 0) {
                    children.at(i)->setHeuristicValue(children.at(i)->heuristic(goal));
                    agenda.push(children.at(i));
                }
            }
        }
    }
    return nullptr;
}

int main() {
    long long mem, examined;
    State m(0, 0, false);
    State g(0, 0, true);

    srand(time(NULL));

    m.setX(rand() % 100);
    m.setY(rand() % 100);

    g.setX(rand() % 100);
    g.setY(rand() % 100);


    for (int i = 1; i < 100; i++)
        for (int j = 1; j < 100; j++)
            if (rand() % 5 == 0)
                m.setFree(i, j, false);


    State *initial = &m;
    State *goal = &g;
    State *bsol;//= initial;
    cout << "Initial:" << endl << initial->toString() << endl;
    cout << "Goal:" << endl << goal->toString() << endl;

    cout << endl << "DFS: ";
    bsol = DFS2(initial, goal, examined, mem);
    if (bsol != nullptr) {
        cout << "depth = " << bsol->getDepth() << ", Mem: " << mem << ", Examined: " << examined << endl;
    } else
        cout << "Problem unsolvable" << endl;

    cout << endl << "BFS: ";
    bsol = BFS2(initial, goal, examined, mem);
    if (bsol != nullptr) {
        cout << "depth = " << bsol->getDepth() << ", Mem: " << mem << ", Examined: " << examined << endl;
    } else
        cout << "Problem unsolvable" << endl;

    cout << endl << "BestFS: ";
    bsol = BestFS2(initial, goal, examined, mem);
    if (bsol != nullptr) {
        cout << "depth = " << bsol->getDepth() << ", Mem: " << mem << ", Examined: " << examined << endl;
    } else
        cout << "Problem unsolvable" << endl;

    return 0;
}
