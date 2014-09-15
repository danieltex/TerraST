#ifndef MAPWRAPPER_H
#define MAPWRAPPER_H

namespace Rcpp{
	template <> std::map<std::string, std::string> as(SEXP sexp);
}

#include "MapWrapper.hpp"
#endif // MAPWRAPPER_H