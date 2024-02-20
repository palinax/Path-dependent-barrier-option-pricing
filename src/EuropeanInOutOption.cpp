#include "EuropeanInOutOption.h"
#include "getOneGaussianByBoxMueller.h"
#include <cmath>
#include <vector>

// Implementing constructor 
EuropeanInOutOption::EuropeanInOutOption(
    int nInt_, 
    double barrier_,
    double strike_, 
    double spot_, 
    double vol_, 
    double r_, 
    double expiry_)
  : nInt(nInt_), barrier(barrier_), strike(strike_), spot(spot_),
    vol(vol_), r(r_), expiry(expiry_) {}

// generatePath method: Generating a path for the underlying asset price
void EuropeanInOutOption::generatePath() {
  thisPath.clear();
  double thisDrift = (r - 0.5 * vol * vol) * (expiry / double(nInt));
  double cumShocks = 0;
  for (int i = 0; i < nInt; ++i) {
    cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * getOneGaussianByBoxMueller());
    thisPath.push_back(spot * exp(cumShocks));
  }
}

// isBarrierBreached method: Checking if the barrier is breached in the generated path
bool EuropeanInOutOption::isBarrierBreached() const {
  for (double price : thisPath) {
    if (price >= barrier) {
      return true;
    }
  }
  return false;
}

// getPayoff method: Calculating the payoff of the option if the barrier is breached
double EuropeanInOutOption::getPayoff() const {
  if (isBarrierBreached()) {
    double finalPrice = thisPath.back();
    return (finalPrice > strike) ? (finalPrice - strike) : 0.0;
  }
  return 0.0;
}

// getPrice method: Calculating the option's price using Monte Carlo simulation
double EuropeanInOutOption::getPrice(int nReps) {
  double rollingSum = 0.0;
  for (int i = 0; i < nReps; i++) {
    generatePath();
    rollingSum += getPayoff();
  }
  return exp(-r * expiry) * (rollingSum / double(nReps));
}