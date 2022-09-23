#ifndef SHOWDATA
#define SHOWDATA

#include <iostream>
#include <vector>
#include "Struct_definer.h"

namespace show
{
	void showDataShow(const std::vector<Shows>& shows);
	void showDataChannel(const std::vector<Channels>& channels);
	void showDataDifuzion(const std::vector<Difuzion>& difuzions);
}

namespace afis
{
	void copyToShowDataShow(const std::vector<Shows>& shows);
	void copyToShowDataChannel(const std::vector<Channels>& channels);
	void copyToShowDataDifuzion(const std::vector<Difuzion>& difuzions);
}

#endif 
