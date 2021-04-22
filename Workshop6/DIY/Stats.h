#include <iostream>
#ifndef SDDS_STATS_H__
#define SDDS_STATS_H__
namespace sdds {

   class Stats {
	   Stats* stat{nullptr};
	   double zero = 0.0;
	   char* m_filename{ nullptr };
	   double* m_nums{0};
	   unsigned m_noOfNums{0};
	   void setFilename(const char* fname, bool isCopy = false);
	   void setNoOfNums();
	   void loadNums();
	   void setEmpty();
   public:
	   Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
	   Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
	   ~Stats();
	   double& operator[](unsigned idx);
	   double operator[](unsigned idx)const;
	   void sort(bool ascending);
	   unsigned size()const;
	   const char* name()const;
	   unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
	   std::ostream& view(std::ostream& ostr)const;
	   std::istream& getFile(std::istream& istr);
   };
	std::istream& operator>>(std::istream& istr, Stats& text);
	std::ostream& operator<<(std::ostream& ostr, const Stats& text);
}
#endif