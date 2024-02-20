#ifndef EUROPEANINOUTOPTION_H
#define EUROPEANINOUTOPTION_H

#include <vector>
#include <algorithm> // Needed for std::max_element

class EuropeanInOutOption {
public:
  EuropeanInOutOption(
    int nInt,
    double barrier,
    double strike,
    double spot,
    double vol,
    double r,
    double expiry
  );

  ~EuropeanInOutOption() {};

  void generatePath();
  bool isBarrierBreached() const;
  double getPayoff() const;
  double getPrice(int nReps);

private:
  std::vector<double> thisPath;
  int nInt;
  double barrier;
  double strike;
  double spot;
  double vol;
  double r;
  double expiry;
};

#endif // EUROPEANINOUTOPTION_H