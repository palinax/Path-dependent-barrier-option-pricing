#include <Rcpp.h>
#include "EuropeanInOutOption.h"
#include "getOneGaussianByBoxMueller.h"

// [[Rcpp::export]]
double priceEuropeanOption(int nInt, double barrier, double strike, double spot, double vol, double r, double expiry, int nReps) {
    EuropeanInOutOption myOption(nInt, barrier, strike, spot, vol, r, expiry);
    return myOption.getPrice(nReps);
}