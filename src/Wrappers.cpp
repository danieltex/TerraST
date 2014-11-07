#include "Wrappers.h"
#include "STExamples.h"
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <locale>
#include <iostream>
#define FORMAT_TIME "%Y-%b-%d %H:%M:%S"

using namespace Rcpp;

// [[Rcpp::export(.getTrajectorySpaceTimeFeatures)]]
List getTrajectorySpaceTimeFeatures(SEXP datasetSEXP)
{
	// Time conversion is locale dependent
	// std::locale l("");
	// std::setlocale(LC_ALL,"en_US.UTF-8");

	XPtr<te::st::TrajectoryDataSet> dataset(datasetSEXP);
	std::size_t size = dataset->size();
	NumericVector x(size);
	NumericVector y(size);	
	CharacterVector posixct(size);
	//std::vector<Datetime> datetime;
	//datetime.reserve(dataset->size());

	// Move to begin
	dataset->moveBeforeFirst();
	std::size_t i = 0;
	std::string previous_datetime = "";
	while(dataset->moveNext())
	{
		std::auto_ptr<te::dt::DateTime> time = dataset->getTime();		
		std::string current_datetime = time->toString();
		if(previous_datetime != current_datetime)
		{
			previous_datetime = current_datetime;
			std::auto_ptr<te::gm::Geometry> geom = dataset->getGeometry();
			te::gm::Point *point = dynamic_cast<te::gm::Point *>(geom.get());
			x[i] = point->getX();
			y[i] = point->getY();
			posixct[i] = current_datetime;
			++i;
		}
	}
	dataset->moveLast();
	int SRID = dataset->getGeometry()->getSRID();
	if(i < size)
	{
		x.erase(i, size);
		y.erase(i, size);
		posixct.erase(i, size);
	}
	
	NumericMatrix points(x.size(), 2);
	points(_,0) = x;
	points(_,1) = y;

	// Reseting to native locale
	// std::setlocale(LC_ALL, l.name().c_str());

	// return List::create(Named("points") = points, Named("time") = datetime);
	return List::create(Named("points") = points, 
						Named("time") = posixct,
						Named("srid") = SRID);
}