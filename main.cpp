


#include "my_exceptions.h"

int main(){ // Testing my_exceptions:
	throw TargetNotFoundException();
	throw PreconditionViolatedException();
	throw NotFoundException();
}