#ifndef DELANDREFRESH
#define DELANDREFRESH
#include <vector>;
#include "Struct_definer.h"

namespace del
{
	void delShow(std::vector<Shows>& shows);
	void delChannel(std::vector<Channels>& channels);
}

namespace refresh
{
	void refreshDataShow(std::vector<Shows>& shows);
	void refreshDataChannel(std::vector<Channels>& channels);
}

#endif // !DELANDREFRESH

