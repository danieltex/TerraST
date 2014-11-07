interporlation = function(sti)
{
	x = sti@sp@coords[,"x"]
	y = sti@sp@coords[,"y"]
	instants = as.numeric(as.POSIXct(rownames(as.data.frame(sti@time))))
	x.ap = splinefun(instants, x)
	y.ap = splinefun(instants, y)
	
}
# long2UTM <- function(long) {
#     (floor((long + 180)/6) %% 60) + 1
# }