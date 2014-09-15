loadTrajectories <- function(dsinfo)
{	
	mod = Module('mod', 'TerraST')
	dataset = mod$loadTrajectoryDataSet(dsinfo)
	st = getTrajectorySpaceTimeFeatures(dataset)
	time = st$time
	points = st$points
	colnames(points) = list('x', 'y')
	sp = SpatialPoints(points)

	STI(sp, time)
}