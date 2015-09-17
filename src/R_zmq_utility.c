#include "R_zmq.h"


/* Internal. */
SEXP AsInt(int C_x){
	SEXP R_x;

	PROTECT(R_x = allocVector(INTSXP, 1));
	INTEGER(R_x)[0] = C_x;
	UNPROTECT(1);
	return(R_x);
} /* End of AsInt().


/* Error related. */
SEXP R_zmq_strerror(SEXP R_errno){
	SEXP R_strerror;

	PROTECT(R_strerror = allocVector(STRSXP, 1));
	SET_STRING_ELT(R_strerror, 0, mkChar(zmq_strerror(INTEGER(R_errno)[0])));
	UNPROTECT(1);
	return(R_strerror);
} /* End of R_zmq_strerror(). */


/* Version. */
SEXP R_zmq_version(){
	int major, minor, patch;
	
	zmq_version(&major, &minor, &patch);
	Rprintf("Current ZeroMQ version is %d.%d.%d\n", major, minor, patch);

	return(R_NilValue);
} /* End of R_zmq_version(). */