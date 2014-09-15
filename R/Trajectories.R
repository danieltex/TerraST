loadTrajectories <- function(dsinfo)
{	
	mod = Module('mod', 'TerraST')
	dataset = mod$loadTrajectoryDataSet(dsinfo)
	st = getTrajectorySpaceTimeFeatures(dataset)

	Sys.setlocale(category = "LC_ALL", locale = "en_US.UTF-8")
	time = as.POSIXct(st$time, format="%Y-%b-%d %H:%M:%S", tz="GMT")
	#non_zero = diff(as.numeric(index(time))) != 0
	#time= time[non_zero]
	Sys.setlocale(category = "LC_ALL", locale = "")

	points = st$points
	colnames(points) = list('x', 'y')
	sp = SpatialPoints(points)
	# sp = sp[non_zero]

	STI(sp, time)
}