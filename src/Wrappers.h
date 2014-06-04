#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <Rcpp.h>
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <terralib/st.h>
#include "STExamples.h"

std::vector<Rcpp::Datetime> getTime();

#endif // WRAPPERS_H
