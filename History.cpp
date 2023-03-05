//
// Created by Edward Eckelberry on 12/11/22.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

void History::push(const HistoryNode &historyNode)
{
    stack.push(historyNode);
}

void History::pop()
{
    stack.pop();
}

HistoryNode &History::top()
{
    return stack.top();
}

unsigned int History::getSize()
{
    return stack.size();
}


