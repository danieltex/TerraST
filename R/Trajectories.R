getTrajectories <- function(source, feature ,id)
{
	tjds = LoadTrajectoryDataSetFromKML(source, feature ,id)
	#("/home/danielsan/Downloads/data/st/trajectory/t_40_41.kml", "40: locations", "40")
	t = getTime(tjds)
	sp = getPoints(tjds)
	
	colnames(sp) = list('x', 'y')
	sp = SpatialPoints(sp)
	
	STI(sp, t)
}
