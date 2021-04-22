#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include "Stats.h"
#include "cstring.h"
using namespace std;
namespace sdds {

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {}

	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		if (filename != nullptr) {
			setFilename(filename);
			setNoOfNums();
			loadNums();
		}
	}

	Stats::~Stats(){
		setEmpty();
	}

	void Stats::setEmpty() {
		zero = 0.0;
		m_filename= nullptr;
		m_nums = nullptr;
		m_noOfNums = 0;
	}

	void Stats::setFilename(const char* fname, bool isCopy) {
		delete[] m_filename;
		m_filename = nullptr;
		if (!isCopy) {
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
		else {
			m_filename = new char[strLen(fname) + 3];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
	}

	void Stats::loadNums() {
		int i = 0;
		if (m_filename != nullptr) {
			delete[] stat;
			stat = nullptr;
			stat = new Stats[m_noOfNums];
			ifstream file(m_filename);
			string line;
			while (getline(file, line)) {
				stat[i++] = line.c_str();
			}
			m_noOfNums = i;
		}
	}

	void Stats::setNoOfNums() {
		ifstream file(m_filename);
		while (file) {
			m_noOfNums += (file.get() == '\n');
		}
		if (m_noOfNums == 0) {
			delete[]m_filename;
			m_filename = nullptr;
		}
		else {
			m_noOfNums += 1;
		}
	}

	double& Stats::operator[](unsigned idx) {
		double* ret = &zero;
		if (this) {
			ret = &m_nums[idx % m_noOfNums];
		}
		return *ret;
	}

	double Stats::operator[](unsigned idx)const {
		const double* ret = &zero;
		if (this) {
			ret = &m_nums[idx % m_noOfNums];
		}
		return *ret;
	}

	void Stats::sort(bool ascending) {
		if (ascending) {
			int i, j;
			Stats temp;
			for (i = m_noOfNums - 1; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (stat[j].m_nums > stat[j + 1].m_nums) {
						temp = stat[j];
						stat[j] = stat[j + 1];
						stat[j + 1] = temp;
					}
				}
			}
		}
		else {
			int i, j;
			Stats temp;
			for (i = m_noOfNums - 1; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (stat[j].m_nums < stat[j + 1].m_nums) {
						temp = stat[j];
						stat[j] = stat[j + 1];
						stat[j + 1] = temp;
					}
				}
			}
		}
	}

	unsigned Stats::size()const {
		return m_noOfNums;
	}

	const char* Stats::name()const {
		return m_filename;
	}

	unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
		if (m_noOfNums > min && m_noOfNums < max) {
			ostr << m_noOfNums << endl;
			ostr << m_nums << endl;
		}
		return 0;
	}

	std::istream& Stats::getFile(std::istream& istr) {
		string get;
		getline(istr, get);
		setFilename(get.c_str());
		setNoOfNums();
		loadNums();
		return istr;
	}

	std::ostream& Stats::view(std::ostream& ostr)const {
		if (m_nums != nullptr) {
			cout << m_filename << endl;
			int a = strLen(m_filename);
			for (int j = 0; j < a; j++) {
				cout << "=";
			}
			cout << endl;
			int b = m_noOfNums;
			for (int i = 0; i < b; i++) {
				cout << m_nums[i] << endl;
			}
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Stats& text) {
		return text.getFile(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, const Stats& text){
		return text.view(ostr);
	}
}