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
	datetime.reserve(output.size());

	// Move to begin
	output.moveBeforeFirst();
	while(output.moveNext())
	{
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

	std::size_t size = output.size();
	Rcpp::NumericVector x(size);
	Rcpp::NumericVector y(size);

	// Move to begin
	output.moveBeforeFirst();
	std::size_t i = 0;
	while(output.moveNext())
	{
		std::auto_ptr<te::gm::Geometry> geom = output.getGeometry();
		te::gm::Point *point = dynamic_cast<te::gm::Point *>(geom.get());
		
		x[i] = point->getX();
		y[i] = point->getY();
		++i;
	}

	// Rcpp::List dimnames = Rcpp::List::create( 
	// 	Rcpp::CharacterVector::create("x", "y", "z"), Rcpp::CharacterVector::create());
	Rcpp::NumericMatrix points(x.size(), 2);
	points(Rcpp::_,0) = x;
	points(Rcpp::_,1) = y;

	return points;
}
