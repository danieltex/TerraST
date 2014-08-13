#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <Rcpp.h>
#include <terralib/st.h>
#include <terralib/geometry.h>

std::vector<Rcpp::Datetime> getTime(te::st::TrajectoryDataSet &dataset);
Rcpp::NumericMatrix getPoints(te::st::TrajectoryDataSet &dataset);

#endif // WRAPPERS_H
