#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <ctime>
#include "State.h"
#include <queue>
#include <stack>
#include <algorithm>
#include "SearchExpert.h"

State *SearchExpert::DFS2(State *initial, State *goal, long long int &examined, long long int &mem) {
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

State *SearchExpert::BFS2(State *initial, State *goal, long long int &examined, long long int &mem) {
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

State *SearchExpert::BFS(State *initial, State *goal, long long int &examined, long long int &mem) {
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

State *SearchExpert::BestFS2(State *initial, State *goal, long long int &examined, long long int &mem) {
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
