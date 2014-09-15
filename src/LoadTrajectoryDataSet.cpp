// TerraLib
#include <terralib/dataaccess.h>
#include <terralib/datatype.h>
#include <terralib/st.h>
#include <terralib/stmemory.h>

// Examples
#include "STExamples.h"

// STL
#include <iostream>

using namespace te::st;
SEXP LoadTrajectoryDataSet(const TrajectoryDataSetInfo& tjinfo)
{
  try
  {    
    TrajectoryDataSet* dataset = STDataLoader::getDataSet(tjinfo).release();
    dataset->moveBeforeFirst();
  
    Rcpp::XPtr<TrajectoryDataSet> dsPtr(dataset);
    return dsPtr;
  }
  catch(const std::exception& e)
  {
    std::cout << std::endl << "An exception has occurried in LoadTrajectoryDataSet: " << e.what() << std::endl;
  }
  catch(...)
  {
    std::cout << std::endl << "An unexpected exception has occurried in LoadTrajectoryDataSet!" << std::endl;
  }
}