//============================================================================
// Name        : LearnDaLang.cpp
// Author      : Shaman
// Version     :
// Copyright   : Eat me
// Description : Demo of c++ stuff which stumped me.
//============================================================================

#include <iostream>

#include "case1.h"
#include "case2.h"
#include "case3.h"

// Try uncommenting this line to see errors like below. Fix this and comment.
/*
./case2buggy.h:32:8: error: field has incomplete type 'learndalang_buggy::Case2'
        Case2 c_;
              ^
./case2buggy.h:17:7: note: forward declaration of 'learndalang_buggy::Case2'
class Case2;
      ^
./case2buggy.h:22:34: error: 'learndalang_buggy::Case2' is an incomplete type
        Case2User(const int param) : c_(Case2(param)) {}
                                        ^
./case2buggy.h:17:7: note: forward declaration of 'learndalang_buggy::Case2'
class Case2;
      ^
./case2buggy.h:27:8: error: 'learndalang_buggy::Case2' is an incomplete type
                c_ = Case2(param);
                     ^
./case2buggy.h:17:7: note: forward declaration of 'learndalang_buggy::Case2'
class Case2;

 */
//#include "case2buggy.h"

int main(int argc, char ** argv) {
	std::cout << "Start of main" << std::endl;
	learndalang::Case1 c ("[FEN \"4k3/R7/1R6/8/8/8/8/4K3 w - - 0 1\"]");
	std::cout << "Trimmed fen is " << *c.GetTrimmed() << std::endl;
	{
		learndalang::Case2User c2User(12);
	}
	std::cout << "Another way of creating Case2User" << std::endl;
	{
		learndalang::Case2User c2User(12, 0);
	}

	// Following are the stl containers being demo'd
	learndalang::Case3 c3;
	learndalang::ChessPiece black_queen;
	black_queen.kind = learndalang::QUEEN;
	black_queen.color = learndalang::BLACK;
	black_queen.rank = learndalang::EIGHT;
	black_queen.file = learndalang::d;

	learndalang::ChessPiece white_black_bishop;
	white_black_bishop.kind = learndalang::BISHOP;
	white_black_bishop.color = learndalang::WHITE;
	white_black_bishop.rank = learndalang::ONE;
	white_black_bishop.file = learndalang::c;

	learndalang::ChessPiece white_white_bishop;
	white_white_bishop.kind = learndalang::BISHOP;
	white_white_bishop.color = learndalang::WHITE;
	white_white_bishop.rank = learndalang::ONE;
	white_white_bishop.file = learndalang::f;

	learndalang::ChessPiece white_queen;
	white_queen.kind = learndalang::QUEEN;
	white_queen.color = learndalang::WHITE;
	white_queen.rank = learndalang::ONE;
	white_queen.file = learndalang::d;

	c3.pieces_vector.push_back(c3.black_king);
	c3.pieces_vector.push_back(c3.white_king);
	c3.pieces_vector.push_back(white_queen);
	c3.pieces_vector.push_back(black_queen);
	// Black queen being inserted twice!
	c3.pieces_vector.push_back(black_queen);

	std::cout << "printing the vector (expect bKing, wKing, wQueen, bQueen, bQueen)\n";
	c3.PrintVector();

	c3.pieces_set.insert(white_queen);
	c3.pieces_set.insert(black_queen);
	// Black queen being inserted twice!
	c3.pieces_set.insert(black_queen);

	std::cout << "printing the set (expect bQueen, wQueen: despite adding white_queen earlier)\n";
	c3.PrintSet();

	c3.pieces_queue.push(white_queen);
	c3.pieces_queue.push(black_queen);
	std::cout << "printing the queue (expect wQueen, bQueen: FIFO semantics)\n";
	c3.PrintQueue();

	c3.pieces_stack.push(white_queen);
	c3.pieces_stack.push(black_queen);
	std::cout << "printing the stack (expect bQueen, wQueen: LIFO semantics)\n";
	c3.PrintStack();

	c3.pieces_list.emplace_back(white_queen);
	c3.pieces_list.emplace_back(white_black_bishop);
	c3.pieces_list.emplace_back(white_white_bishop);
	std::cout << "printing the list (expect wQueen, wbBishop, wwBishop: list semantics)\n";
	c3.PrintList();

	c3.pieces_color_map[white_queen] = learndalang::WHITE;
	c3.pieces_color_map[black_queen] = learndalang::BLACK;
	std::cout << "printing the map \n";

	c3.PrintMap();
}
