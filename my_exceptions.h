
#ifndef SOURCE_MY_EXCEPTIONS_H
#define SOURCE_MY_EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <string>

// TODO Apparently the commented-out definitions are invalid because of the concatenation in the constructor's return exception. If it worked this would be more useful than the current implementation of my exceptions, since we can pass information to the exception when it's called.

using namespace std;
class TargetNotFoundException: public exception{
public:
//	TargetNotFoundException(const string& message = "") : exception("Target not found: " + message){
//		// todo implementation??
//	} // TODO are we allowed to use strings yet :(
	virtual const char* what() const throw(){
		return "Target not found";
	}
};

class PreconditionViolatedException: public exception{
public:
//	PreconditionViolatedException(const string& message = "") : exception("Violation of precondition: " + message.c_str()){
//		// todo implementation??
//	} // TODO are we allowed to use strings yet :(
	virtual const char* what() const throw(){
		return "Violation of precondition for usage";
	}
};

class NotFoundException: public exception{
public:
//	NotFound(const string& message = "") : exception("Not found: " + message.c_str()){
//		// todo implementation??
//	} // TODO are we allowed to use strings yet :(
	virtual const char* what() const throw(){
		return "Not found";
	}
};

#endif //SOURCE_MY_EXCEPTIONS_H
