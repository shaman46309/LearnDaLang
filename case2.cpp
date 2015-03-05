/*
 * Case2.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: pankajm
 */

#include "Case2.h"

#include <iostream>

namespace learndalang {

Case2::Case2() {
	std::cout << "Default constructor of Case2 invoked" << std::endl;
}

Case2::Case2(int param) {
	std::cout << "Parameterized constructor of Case2 invoked with "
			<< param << std::endl;
}

Case2::~Case2() {
	std::cout << "Destructor of Case2 invoked " << std::endl;
}

} /* namespace learndalang */
