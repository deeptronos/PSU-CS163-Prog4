
#ifndef SOURCE_MY_EXCEPTIONS_H
#define SOURCE_MY_EXCEPTIONS_H

#include <iostream>
#include <stdexcept>
#include <string>

// TODO Apparently the commented-out definitions are invalid because of the concatenation in the constructor's return exception. If it worked this would be more useful than the current implementation of my exceptions, since we can pass information to the exception when it's called.

using namespace std;
//class TargetNotFoundException: public exception{
//public:
////	TargetNotFoundException(const string& message = "") : exception("Target not found: " + message){
////		// todo implementation??
////	} // TODO are we allowed to use strings yet :(
////	virtual const char* what() const throw(){
//	virtual const char* what() const throw(){
//		return "Target not found";
//	}
//	virtual ~TargetNotFoundException();
//};

class TargetNotFoundException : public logic_error{
public:
//	TargetNotFoundException(const string& message = "") : exception("Target not found: " + (message.c_str())){}
	TargetNotFoundException(const string& message = "") : logic_error("Target not found: " + (message)){}
};

class PreconditionViolatedException: public logic_error{
public:
	PreconditionViolatedException(const string& message = "") : logic_error("Violation of precondition: " + message){
	} // TODO are we allowed to use strings yet :(

};

class NotFoundException: public logic_error{
public:
	NotFoundException(const string& message = "") : logic_error("Not found: " + message){
	} // TODO are we allowed to use strings yet :(

};

#endif //SOURCE_MY_EXCEPTIONS_H

