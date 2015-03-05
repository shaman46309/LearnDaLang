/*
 * Case2.h
 *
 *  Created on: Mar 4, 2015
 *      Author: pankajm
 */

#ifndef CASE2_BUGGY_H_
#define CASE2_BUGGY_H_

#include <iostream>

namespace learndalang_buggy {

// Try forward declaration of learndalang_buggy::Case2 here.

class Case2;

class Case2User {

public:
	Case2User(const int param) : c_(Case2(param)) {}

	// The C++ way of adding another constructor with same
	// signature. Can we do better?
	Case2User(const int param, const int unused) {
		c_ = Case2(param);
	}

	~Case2User() {}
private:
	Case2 c_;
};



class Case2 {
public:
	Case2() {
		std::cout << "Default constructor of Case2 invoked" << std::endl;
	}
	explicit Case2(int param) {
		std::cout << "Parameterized constructor of Case2 invoked with "
				<< param << std::endl;
	}
	virtual ~Case2() {
		std::cout << "Destructor of Case2 invoked " << std::endl;
	}
};

} /* namespace learndalang_buggy */

#endif /* CASE2_BUGGY_H_ */
