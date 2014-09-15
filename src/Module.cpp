// Rcpp
#include <Rcpp.h>
#include "MapWrapper.h"

// STL
#include <map>
#include <string>

// TerraLib
#include <terralib/dataaccess.h>
#include <terralib/st.h>
#include <terralib/stmemory.h>
#include "STExamples.h"

using namespace Rcpp;
using namespace te::da;
using namespace te::st;

RCPP_EXPOSED_CLASS_NODECL(DataSourceInfo)
RCPP_EXPOSED_CLASS_NODECL(TrajectoryDataSetInfo)

RCPP_MODULE(mod) {
	class_<DataSourceInfo>("DataSourceInfo")
	.default_constructor()
	.property("id", &DataSourceInfo::getId,&DataSourceInfo::setId)
	.property("type", &DataSourceInfo::getType,&DataSourceInfo::setType)
	.property("accessDriver", &DataSourceInfo::getAccessDriver, &DataSourceInfo::setAccessDriver)
	.property("title", &DataSourceInfo::getTitle, &DataSourceInfo::setTitle)
	.property("description", &DataSourceInfo::getDescription, &DataSourceInfo::setDescription)
	.property("connInfo", &DataSourceInfo::getConnInfo, &DataSourceInfo::setConnInfo)
	// .method("getId", 			&DataSourceInfo::getId)
	// .method("setId", 			&DataSourceInfo::setId)
	// .method("getType", 			&DataSourceInfo::getType)
	// .method("setType", 			&DataSourceInfo::setType)
	// .method("getAccessDriver", 	&DataSourceInfo::getAccessDriver)
	// .method("setAccessDriver", 	&DataSourceInfo::setAccessDriver)
	// .method("getTitle", 		&DataSourceInfo::getTitle)
	// .method("setTitle", 		&DataSourceInfo::setTitle)
	// .method("getDescription", 	&DataSourceInfo::getDescription)
	// .method("setDescription", 	&DataSourceInfo::setDescription)
	// .nonconst_method("getConnInfo",	&DataSourceInfo::getConnInfo)
	// .method("setConnInfo", 		&DataSourceInfo::setConnInfo)
	;

	class_<TrajectoryDataSetInfo>("TrajectoryDataSetInfo")
	.constructor<DataSourceInfo, std::string, int, int, int, std::string>()
	.property("dataSourceInfo", &TrajectoryDataSetInfo::getDataSourceInfo)
	.property("timePropIdxs",	 &TrajectoryDataSetInfo::getTimePropIdxs)
	.property("geomPropIdx",	 &TrajectoryDataSetInfo::getGeomPropIdx)
	.property("id",			 &TrajectoryDataSetInfo::getId)
	// .method("getDataSourceInfo", &TrajectoryDataSetInfo::getDataSourceInfo)
	// .method("getTimePropIdxs",	 &TrajectoryDataSetInfo::getTimePropIdxs)
	// .method("getGeomPropIdx",	 &TrajectoryDataSetInfo::getGeomPropIdx)
	// .method("getId",			 &TrajectoryDataSetInfo::getId)
	;

	function("createDataSourceAndUpdateManager", &CreateDataSourceAndUpdateManager);
	function("loadTrajectoryDataSet", &LoadTrajectoryDataSet);
}