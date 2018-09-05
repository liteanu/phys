#include <iostream>
#include "G4LegendrePolynomial.hh"
#include "gsl/gsl_sf_legendre.h"

using namespace std;

int main()
{
  G4LegendrePolynomial lp;

  gsl_sf_legendre_t norm = GSL_SF_LEGENDRE_SPHARM;
  size_t ll = 2;
  size_t mm = 1;
  vector<double> result_array(gsl_sf_legendre_array_n(ll));
  double xx = 0.5;
  gsl_sf_legendre_array(norm, ll, xx, &(result_array[0]));
  cout << lp.EvalAssocLegendrePoly(ll, mm, xx) << " vs. " << result_array[gsl_sf_legendre_array_index(ll, mm)] << endl;
  return 0;
}

