#ifndef PATH_RESULT_H
#define PATH_RESULT_H

#include<iostream>

class PathResult{

public:

    std:: vector<long long> dist;
    std:: vector<int> parent;
    std:: vector<int> visitedOrder;
};

#endif
