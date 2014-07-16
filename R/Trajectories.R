getTrajectories <- function()
{
	sp = getPoints()
	colnames(sp) = list('x', 'y', 'z')
	sp = SpatialPoints(sp)
	t = getTime()
	
	STI(sp, t)
}
