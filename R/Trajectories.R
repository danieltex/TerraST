mod <- Module('mod', 'TerraST')

loadTrajectories <- function(dsinfo)
{	
	#mod = Module('mod', 'TerraST')
	dataset = mod$loadTrajectoryDataSet(dsinfo)
	st = .getTrajectorySpaceTimeFeatures(dataset)

	Sys.setlocale(category = "LC_ALL", locale = "en_US.UTF-8")
	time = as.POSIXct(st$time, format="%Y-%b-%d %H:%M:%S", tz="GMT")
	#non_zero = diff(as.numeric(index(time))) != 0
	#time= time[non_zero]
	Sys.setlocale(category = "LC_ALL", locale = "")

	points = st$points
	colnames(points) = list('x', 'y')
	sp = SpatialPoints(points, proj4string=CRS(paste("+init=epsg:", st$srid, sep="")))
	# sp = sp[non_zero]

	df = data.frame(co2 = rnorm(length(time)))
	# df = data.frame(v = rep(1, length(time)))
	# df = data.frame(data.frame(id = c(paste("ID", rep(dsinfo$id, each=length(time))))))
	sti= STI(sp, time)
}