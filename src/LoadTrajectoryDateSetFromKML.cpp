// TerraLib
#include <terralib/dataaccess.h>
#include <terralib/stmemory.h>
#include <terralib/st.h>
#include <terralib/datatype.h>

// Examples
#include "STExamples.h"

// STL
#include <iostream>
//#include <Rcpp.h>
// void LoadTrajectoryDataSetFromKML(boost::ptr_vector<te::st::TrajectoryDataSet>& output)
// [[Rcpp::export]]
SEXP LoadTrajectoryDataSetFromKML(const std::string& URI,
                                  const std::string& dsName,
                                  const std::string& dsID)
{
  try
  { 
    //Indicates the data source
    te::da::DataSourceInfo dsinfo;

    std::map<std::string, std::string> connInfo;
    // connInfo["URI"] = ""TE_DATA_EXAMPLE_DIR"/data/st/trajectory/t_40_41.kml" ;
    connInfo["URI"] = URI;
    dsinfo.setConnInfo(connInfo);
    dsinfo.setType("OGR");

    //It creates a new Data Source and put it into the manager
    CreateDataSourceAndUpdateManager(dsinfo);

    //Indicates how the trajectories are stored in the data source -> This structure is fixed for OGR driver
    int phTimeIdx = 3;  /* property name: timestamp */
    int geomIdx = 12;    /* property name: geom */
    
    te::st::TrajectoryDataSetInfo tjinfo(dsinfo, dsName, phTimeIdx, geomIdx, -1, dsID);
    te::st::TrajectoryDataSet* dataset = te::st::STDataLoader::getDataSet(tjinfo).release();
    dataset->moveBeforeFirst();
  
    Rcpp::XPtr<te::st::TrajectoryDataSet> dsPtr(dataset);
    return dsPtr;
  }
  catch(const std::exception& e)
  {
    std::cout << std::endl << "An exception has occurried in TrajectoryExamplesFromKML: " << e.what() << std::endl;
  }
  catch(...)
  {
    std::cout << std::endl << "An unexpected exception has occurried in TrajectoryExamplesFromKML!" << std::endl;
  }
}

