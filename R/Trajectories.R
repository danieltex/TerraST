getTrajectories <- function()
{
	sp = getPoints()
	#colnames(sp) = list('x', 'y', 'z')
	colnames(sp) = list('x', 'y')
	sp = SpatialPoints(sp)
	t = getTime()
	
	STI(sp, t)
}
