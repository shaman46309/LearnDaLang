/*
 * case1.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: pankajm
 */

#include "case1.h"

namespace learndalang {

Case1::~Case1() {
}

const std::string Case1::Trimmed() const {
	std::string trimmed_at_start = full_.substr(6);
	int pos = trimmed_at_start.find(" ", 0);
	std::string trimmed = trimmed_at_start.substr(0, pos);
	return trimmed;
}

} /* namespace learndalang */
