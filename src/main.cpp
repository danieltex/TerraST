// Examples
#include "STExamples.h"

// TerraLib
#include <terralib/common.h>
#include <terralib/dataaccess.h>
#include <terralib/geometry.h>
#include <terralib/st.h>

#include <iostream>
#include <Rcpp.h>

//'  Justa a simple Hello World
// [[Rcpp::export]]
void oi()
{
	std::cout << "Oi mundo" << std::endl;
}

// [[Rcpp::export]]
void TrajectoryExamples()
{
	//Output container
	boost::ptr_vector<te::st::TrajectoryDataSet> output;
    
	//Load the trajectories from a KML Data Source
	//LoadTrajectoryDataSetFromKML(output);
	
	//Print trajectory data set info: spatial and temporal extent
	//PrintTrajectoryDataSetInfo(output);
}
