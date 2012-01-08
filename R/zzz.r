".First.lib" <-function (lib, pkg)
{
#cat ("Loading package: Lib is ",lib, " and Pack is ",pack,"\n");
#Loading C library
  library.dynam ("mcga", pkg, lib);

}
