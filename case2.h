/*
 * Case2.h
 *
 *  Created on: Mar 4, 2015
 *      Author: pankajm
 */

#ifndef CASE2_H_
#define CASE2_H_

namespace learndalang {

class Case2 {
public:
	Case2();
	explicit Case2(int param);
	virtual ~Case2();
};

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
} /* namespace learndalang */

#endif /* CASE2_H_ */
