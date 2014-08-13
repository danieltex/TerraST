#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <Rcpp.h>
#include <terralib/st.h>
#include <terralib/geometry.h>

std::vector<Rcpp::Datetime> getTime(SEXP datasetSEXP);
Rcpp::NumericMatrix getPoints(SEXP datasetSEXP);

#endif // WRAPPERS_H
