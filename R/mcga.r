#R File
mcga<-function(popsize, chsize, elitism=1, minval, maxval, maxiter=10, evalFunc){

	par<-rep(0,chsize);
	population<-rep(0,chsize*popsize);
	envv<-.GlobalEnv;
	result<-.Call("mcga",popsize, chsize, elitism, minval, maxval, maxiter, par, evalFunc,population, envv, PACKAGE="mcga");
	resmat<-matrix(population, ncol=chsize, nrow=popsize);
	return(resmat);
}

