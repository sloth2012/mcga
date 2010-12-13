".First.lib" <- function (lib, pack)

{
	#cat ("Loading package: Lib is ",lib, " and Pack is ",pack,"\n");
	#Loading C++ library
	library.dynam("mcga", pack, lib);

}
