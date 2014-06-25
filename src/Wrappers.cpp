#include "Wrappers.h"
#include "STExamples.h"
#include <terralib/st.h>
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <locale>

#define FORMAT_TIME "%Y-%b-%d %H:%M:%S"

// [[Rcpp::export]]
std::vector<Rcpp::Datetime> getTime()
{

	std::locale l("");
	std::setlocale(LC_ALL,"en_US.UTF-8");

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
		std::cout << time->toString() << std::endl;
		Rcpp::Datetime dt(time->toString(), FORMAT_TIME);
		dt_vec.push_back(dt);
		std::auto_ptr<te::gm::Geometry> geom = output.getGeometry();

//		std::cout << "Date and Time: " <<  time->toString() << std::endl;
		std::cout << "Geometry: " <<  geom->toString()  << std::endl << std::endl;
	}
	
	std::setlocale(LC_ALL, l.name().c_str());
	
	return dt_vec;
}
