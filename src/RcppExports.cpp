// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// LoadTrajectoryDataSetFromKML
SEXP LoadTrajectoryDataSetFromKML(const std::string& URI, const std::string& dsName, const std::string& dsID);
RcppExport SEXP TerraST_LoadTrajectoryDataSetFromKML(SEXP URISEXP, SEXP dsNameSEXP, SEXP dsIDSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< const std::string& >::type URI(URISEXP );
        Rcpp::traits::input_parameter< const std::string& >::type dsName(dsNameSEXP );
        Rcpp::traits::input_parameter< const std::string& >::type dsID(dsIDSEXP );
        SEXP __result = LoadTrajectoryDataSetFromKML(URI, dsName, dsID);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// getTrajectorySpaceTimeFeatures
List getTrajectorySpaceTimeFeatures(SEXP datasetSEXP);
RcppExport SEXP TerraST_getTrajectorySpaceTimeFeatures(SEXP datasetSEXPSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type datasetSEXP(datasetSEXPSEXP );
        List __result = getTrajectorySpaceTimeFeatures(datasetSEXP);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
