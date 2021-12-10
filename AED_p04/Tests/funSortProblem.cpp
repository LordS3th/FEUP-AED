#include "funSortProblem.h"
#include <algorithm>
using namespace std;
FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------
struct {
    bool operator()(Product const &a, Product const &b) {
        return ((a.getPrice() < b.getPrice()) || (a.getPrice() == b.getPrice() && a.getWeight() < b.getWeight()));
    }
}comp;
// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(),products.end(), comp);
    if (products.size()>k){
    products.erase(products.begin()+k, products.end());
}}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if(values.size()<nc){
        return -1;
    }
    else{
        vector<unsigned int> v1= values;
        sort(v1.begin(), v1.end());
        int dif=v1[nc-1]-v1[0];
        for (int i=0; i<v1.size()-nc;i++){
            if(v1[i+nc-1]-v1[i]<dif) {
                dif = v1[i+nc-1]-v1[i];
            }
        }
    return dif;
    }
}

// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    int res=1;
    vector<float> v1;
    v1 = departure;
    sort(v1.begin(), v1.end());
    for (int i = 0; i < arrival.size();i++){
        int a= 1;
        for (int j = 1 ; j <arrival.size();j++){
            if ( arrival[j] > arrival[i] && arrival[j] <= v1[i]){
                a++;
            }
        }
        if ( a > res){
            res= a;
        }
    }
    return res;
}
// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

