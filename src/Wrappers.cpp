#include "Wrappers.h"
#include "STExamples.h"
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
    
	// Load the trajectories from a KML Data Source
	LoadTrajectoryDataSetFromKML(outputs);
	te::st::TrajectoryDataSet &output = outputs[0];
	
	std::vector<Rcpp::Datetime> datetime;

	// Inicio do dataset
	output.moveBeforeFirst();
	while(output.moveNext())
	{
		// std::auto_ptr<String> id = output->getID();
		std::auto_ptr<te::dt::DateTime> time = output.getTime();		
		Rcpp::Datetime dt(time->toString(), FORMAT_TIME);
		datetime.push_back(dt);
	}
	
	std::setlocale(LC_ALL, l.name().c_str());

	return datetime;
}

// [[Rcpp::export]]
Rcpp::NumericMatrix getPoints()
{
	boost::ptr_vector<te::st::TrajectoryDataSet> outputs;
    
	// Load the trajectories from a KML Data Source
	LoadTrajectoryDataSetFromKML(outputs);
	te::st::TrajectoryDataSet &output = outputs[0];

	Rcpp::NumericVector x;
	Rcpp::NumericVector y;
	Rcpp::NumericVector z;

	// Inicio do dataset
	output.moveBeforeFirst();
	while(output.moveNext())
	{
		// std::auto_ptr<String> id = output->getID();

		std::auto_ptr<te::gm::Geometry> geom = output.getGeometry();
		te::gm::Point *point = dynamic_cast<te::gm::Point *>(geom.get());
		
		x.push_back(point->getX());
		y.push_back(point->getY());
		z.push_back(point->getZ());
		// std::cout << "Date and Time: " <<  time->toString() << std::endl;
	}

	// Rcpp::List dimnames = Rcpp::List::create( Rcpp::CharacterVector::create("x", "y", "z"), Rcpp::CharacterVector::create());
	Rcpp::NumericMatrix points(x.size(), 3);
	// points.attr("dimnames") = dimnames;
	points(Rcpp::_,0) = x;
	points(Rcpp::_,1) = y;
	points(Rcpp::_,2) = z;

	return points;
}