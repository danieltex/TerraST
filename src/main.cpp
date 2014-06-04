// Examples
#include "STExamples.h"

// TerraLib
#include <terralib/common.h>
#include <terralib/dataaccess.h>
#include <terralib/geometry.h>
#include <terralib/st.h>
#include <terralib/plugin.h>

// STL
#include <cassert>
#include <cstdlib>
#include <exception>

#include <iostream>
#include <Rcpp.h>

class TerraLib_Init
{
public:
	static class _init
	{
	public:
		_init()
		{
			try
			{
				TerraLib::getInstance().initialize();

				//Load Modules and Plugins
				LoadModules();

				//Initialize STDataLoader support
				te::st::STDataLoader::initialize();
			}
			catch(const std::exception& e)
			{
				std::cout << std::endl << "An exception has occurried: " << e.what() << std::endl;

				// std::cout << "Press Enter to exit..." << std::endl;
				// std::cin.get();
			}
			catch(...)
			{
				std::cout << std::endl << "An unexpected exception has occurried!" << std::endl;

				// std::cout << "Press Enter to exit..." << std::endl;
				// std::cin.get();

				// return EXIT_FAILURE;
			}
		}

		~_init()
		{
			try
			{
				//Finalize STDataLoader support
				te::st::STDataLoader::finalize();

				te::plugin::PluginManager::getInstance().unloadAll();

				TerraLib::getInstance().finalize();
			}
			catch(const std::exception& e)
			{
				std::cout << std::endl << "An exception has occurried: " << e.what() << std::endl;

				// std::cout << "Press Enter to exit..." << std::endl;
				// std::cin.get();
			}
			catch(...)
			{
				std::cout << std::endl << "An unexpected exception has occurried!" << std::endl;

				// std::cout << "Press Enter to exit..." << std::endl;
				// std::cin.get();

				// return EXIT_FAILURE;
			}
		}
	} _initializer;
};
TerraLib_Init::_init TerraLib_Init::_initializer;

// [[Rcpp::export]]
void TrajectoryExamples()
{
	try
	{
		//initialize();
		//Output container
		boost::ptr_vector<te::st::TrajectoryDataSet> output;
    
		//Load the trajectories from a KML Data Source
		LoadTrajectoryDataSetFromKML(output);
	
		//Print trajectory data set info: spatial and temporal extent
		PrintTrajectoryDataSetInfo(output);

		PrintTrajectoryDistance(output);

		//finalize();
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "An exception has occurried: " << e.what() << std::endl;
	}
	catch(...)
	{
		std::cout << std::endl << "An unexpected exception has occurried!" << std::endl;
	}
}
