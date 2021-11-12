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
    if (num==0){
        return 0;
    }
    else if (num==1){
        return 1;
    }
    else {
        int left=1;
        int right = num;
        int middle=0;
        while (left <=right) {
             floor(middle = (left + right)/2);
            if (middle * middle < num) {
                left = middle + 1;
            } else if (middle * middle > num) {
                right = middle - 1;
            } else return middle;
        }
        return right;
    }
}


// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    int n=0;
    for (int i =0;i<values.size();i++){
        if (n==values[i]){
            n++;
        }
    }
    return n;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {

}

