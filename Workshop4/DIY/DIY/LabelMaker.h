
#ifndef SDDS_LABEL_MAKER_H
#define SDDS_LABEL_MAKER_H
#include <iostream>
#include "Label.h"
namespace sdds {
	class LabelMaker{
		Label* m_labels;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif
