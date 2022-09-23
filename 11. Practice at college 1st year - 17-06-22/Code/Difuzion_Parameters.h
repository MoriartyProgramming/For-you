#ifndef DIFUZION_PARAMETERS
#define DIFUZION_PARAMETERS
#include <iostream>
#include <vector>
#include "Struct_definer.h"

namespace difuzion
{
	void maxTimeDifuzion(const std::vector<Difuzion>& difuzions);

	void minTimeDifuzion(const std::vector<Difuzion>& difuzions);

	void numOfShowsPerChannel(std::vector<Difuzion>& difuzions);

	void mostPopularShow(std::vector<Difuzion>& difuzions);
}
#endif // !DIFUZION_PARAMETERS

