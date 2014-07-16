// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// TrajectoryExamples
void TrajectoryExamples();
RcppExport SEXP TerraST_TrajectoryExamples() {
BEGIN_RCPP
    {
        Rcpp::RNGScope __rngScope;
        TrajectoryExamples();
    }
    return R_NilValue;
END_RCPP
}
// getTime
std::vector<Rcpp::Datetime> getTime();
RcppExport SEXP TerraST_getTime() {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        std::vector<Rcpp::Datetime> __result = getTime();
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// getPoints
Rcpp::NumericMatrix getPoints();
RcppExport SEXP TerraST_getPoints() {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::NumericMatrix __result = getPoints();
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
