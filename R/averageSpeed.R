.posix2numeric <-function(time)
{
	as.numeric(as.POSIXct(rownames(as.data.frame(time))))
}

averageSpeed <- function(sti)
{
	coords_utm = spTransform(sti@sp, CRS=CRS("+init=epsg:32620"))
	x = coords_utm@coords[,"x"]
	y = coords_utm@coords[,"y"]
	instants = .posix2numeric(sti@time)
	x.vel = (c(x[-1], tail(x,1)) - x) / (c(instants[-1], Inf) - instants )
	y.vel = (c(y[-1], tail(y,1)) - y) / (c(instants[-1], Inf) - instants )
	speed = sqrt(x.vel ** 2 + y.vel ** 2)
	return(speed)
}
