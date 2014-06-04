#include "Wrappers.h"

#define FORMAT_TIME "%Y-%b-%d %H:%M:%S"

// [[Rcpp::export]]
std::vector<Rcpp::Datetime> getTime()
{
	boost::ptr_vector<te::st::TrajectoryDataSet> outputs;
    
	//Load the trajectories from a KML Data Source
	LoadTrajectoryDataSetFromKML(outputs);
	te::st::TrajectoryDataSet &output = outputs[0];
	
	std::vector<Rcpp::Datetime> dt_vec;
	// Inicio do dataset
	output.moveBeforeFirst();
	while(output.moveNext())
	{
//		std::auto_ptr<String> id = output->getID();
		std::auto_ptr<te::dt::DateTime> time = output.getTime();
		Rcpp::Datetime dt(time->toString(), FORMAT_TIME);
		dt_vec.push_back(dt);
//		std::auto_ptr<te::gm::Geometry> geom = output->getGeometry();

//		std::cout << "Date and Time: " <<  time->toString() << std::endl;
//		std::cout << "Geometry: " <<  geom->toString()  << std::endl << std::endl;
	}
	
	return dt_vec;
}
