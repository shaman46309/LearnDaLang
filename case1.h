/*
 * case1.h
 *
 *  Created on: Mar 4, 2015
 *      Author: pankajm
 */

#ifndef CASE1_H_
#define CASE1_H_

#include <string>

namespace learndalang {

/*
 * This class demonstrates how to achieve a 'final' paradigm.
 *
 * We have a second member variable trimmed_ which we want to
 * keep as const but the initial value needs to be calculated
 * from full_. We have a private member function Trimmed which
 * does this calculation. The most important c++ feature to keep
 * in mind is that member variable initialization is different
 * from assignment. The initialization list syntax takes the value
 * of Trimmed() and passes it to the constructor of trimmed_. This
 * achieves exactly what we do in a constructor in java.
 * <java-code>
 * public Case1() {
 * final String trimmed_ = Trimmed();
 * }
 * </java-code>.
 *
 * To understand what goes behind the scene refer Case2 where
 * we print the invocation of the default constructor.
 */
class Case1 {
public:
	Case1(const std::string& full) : full_(full),
	trimmed_(Trimmed()) {};
	virtual ~Case1();
	const std::string* GetTrimmed() const {
		return &trimmed_;
	}

private:
	const std::string& full_;
	const std::string trimmed_;
	const std::string Trimmed() const;
};

} /* namespace learndalang */

#endif /* CASE1_H_ */
