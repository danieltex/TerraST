#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <Rcpp.h>
#include <terralib/st.h>
#include <terralib/geometry.h>

std::vector<Rcpp::Datetime> getTime();
Rcpp::NumericMatrix getPoints();

#endif // WRAPPERS_H
