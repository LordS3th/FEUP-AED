#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

// TODO
int FunSearchProblem::facingSun(const vector<int> & values) {
    for(int i=0; i < values.size();i++){
        if (values[i]>values[i+1]){
            return i+1;
        }
    }
    return values.size();
}

// TODO
int FunSearchProblem::squareR(int num) {
    return 0;
}


// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    return 0;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    return 0;
}

