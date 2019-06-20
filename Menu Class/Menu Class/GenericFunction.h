#ifndef GENERICFUNCTION_H_
#define GENERICFUNCTION_H_
template <class ARG>
template <class GENERIC>
class GenericFunction
{
public:
	GENERIC (*function)(ARG arg);
	GenericFunction();
};
#endif
