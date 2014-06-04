// Examples
#include "STExamples.h"

// TerraLib
#include <terralib/dataaccess.h>
#include <terralib/datatype.h>
#include <terralib/geometry.h>
#include <terralib/st.h>

// STL
#include <iostream>

void PrintTrajectoryDataSet(boost::ptr_vector<te::st::TrajectoryDataSet>& output)
{
  for(std::size_t i=0; i<output.size(); ++i)
  {
	  std::cout << "Printing observations of the trajectory data set" << i << " :" << std::endl;
    PrintTrajectoryDataSet(&output[i]);
  }
}

void PrintTrajectoryDataSet(te::st::TrajectoryDataSet* output)
{
  if(output == 0)
  {
    std::cout << "Trajectory Data Set is NULL!" << std::endl;
    return;
  }
  
  PrintTrajectoryDataSetInfo(output);
  
  std::cout << "Trajectory observations: " <<  std::endl;
  
  output->moveBeforeFirst();
  
  while(output->moveNext())
  {
    std::auto_ptr<te::dt::DateTime> time = output->getTime();
    std::auto_ptr<te::gm::Geometry> geom = output->getGeometry();
    
    std::cout << "Date and Time: " <<  time->toString() << std::endl;
    std::cout << "Geometry: " <<  geom->toString()  << std::endl << std::endl;
  }
}

void PrintTrajectoryDataSetInfo(boost::ptr_vector<te::st::TrajectoryDataSet>& output)
{
  for(std::size_t i=0; i<output.size(); ++i)
  {
	  std::cout << "Printing information about the trajectory data set " << i << " :" << std::endl;
    PrintTrajectoryDataSetInfo(&output[i]);
  }
}

void PrintTrajectoryDataSetInfo(te::st::TrajectoryDataSet* output)
{
  te::dt::DateTimePeriod* textent = output->getTemporalExtent();
  std::cout << "Temporal Extent: " << textent->toString() << std::endl;

  const te::gm::Envelope sextent = output->getSpatialExtent();
  std::cout << "Spatial Extent: " << sextent.getLowerLeftX() << std::endl;
}

void PrintTrajectoryDistance(boost::ptr_vector<te::st::TrajectoryDataSet>& output)
{
  //Get the trajectories from the trajectory data sets to execute other operations 
    boost::ptr_vector<te::st::Trajectory> trajectories;
    for(std::size_t i=0; i<output.size(); ++i)
    {
      te::st::TrajectoryDataSet& ds = output[i];
      ds.moveBeforeFirst();
      std::auto_ptr<te::st::Trajectory> tj = ds.getTrajectory();
      trajectories.push_back(tj);
    }
  
    //Calculate and print the distance between the two first trajectories
    if(trajectories.size()>1)
      TrajectoryDistance(&trajectories[0], &trajectories[1]);
    
    //Calculate the intersection between the first trajectory and a geometry
    //Load the geometry from a shapefile
    std::map<std::string, std::string> connInfo;
    connInfo["URI"] = ""TE_DATA_EXAMPLE_DIR"/data/st/trajectory/t41_region.shp" ; 
    
    std::auto_ptr<te::da::DataSource> ds(te::da::DataSourceFactory::make("OGR"));
    ds->setConnectionInfo(connInfo); 
    ds->open();
    
    std::auto_ptr<te::da::DataSet> dSet = ds->getDataSet("t41_region"); 
    std::auto_ptr<te::gm::Geometry> geom; 
    dSet->moveBeforeFirst();
    if(dSet->moveNext())
    {
      std::size_t geomPos = te::da::GetFirstPropertyPos(dSet.get(), te::dt::GEOMETRY_TYPE);
      geom = dSet->getGeometry(geomPos);

      //Calculate the intersection and print the result!
      TrajectoryIntersection(&trajectories[1], geom.get());
    }
}
