#include <string>
#include "foo.h"

std::string bar()
{
	return "bar " + foo();
}
