/*
 * case3.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: pankajm
 */

#include "case3.h"

#include <iostream>

namespace learndalang {

char FileToChar(File file) {
	switch (file) {
	case a : return 'a';
	case b : return 'b';
	case c : return 'c';
	case d : return 'd';
	case e : return 'e';
	case f : return 'f';
	case g : return 'g';
	case h : return 'h';
	default : return '!';
	}
}

Case3::Case3() {
	white_king.kind = KING;
	white_king.color = WHITE;
	white_king.rank = ONE;
	white_king.file = e;

	black_king.kind = KING;
	black_king.color = BLACK;
	black_king.rank = EIGHT;
	black_king.file = e;
}

Case3::~Case3() {
}

void Case3::PrintSet() {
	for (auto& p : pieces_set) {
		PrintPiece(p);
	}
}

void Case3::PrintQueue() {
	while (!pieces_queue.empty()) {
		ChessPiece& p = pieces_queue.front();
		PrintPiece(p);
		pieces_queue.pop();
	}
}

void Case3::PrintStack() {
	while (!pieces_stack.empty()) {
		ChessPiece& p = pieces_stack.top();
		PrintPiece(p);
		pieces_stack.pop();
	}
}

void Case3::PrintList() {
	std::list<ChessPiece>::const_iterator itr = pieces_list.cbegin();
	while (itr!= pieces_list.end()) {
		PrintPiece(*itr++);
	}
}

void Case3::PrintMap() {
	std::map<ChessPiece, PieceColor>::const_iterator itr = pieces_color_map.cbegin();
	while (itr!= pieces_color_map.end()) {
			std::cout << "Found a piece of color " << itr->second << std::endl;
			PrintPiece(itr->first);
			itr++;
	}
}

void Case3::PrintVector() {
	for (auto& p : pieces_vector) {
		PrintPiece(p);
	}
}

void Case3::PrintPiece(ChessPiece p) {

			if (p.color == learndalang::WHITE) {
				std::cout << "White ";
			} else {
				std::cout << "Black ";
			}

			switch (p.kind) {
			case learndalang::KING:
				std::cout << "King "; break;
			case learndalang::PAWN:
				std::cout << "Pawn "; break;
			case learndalang::BISHOP:
				std::cout << "Bishop "; break;
			case learndalang::KNIGHT:
				std::cout << "Knight "; break;
			case learndalang::ROOK:
				std::cout << "Rook "; break;
			case learndalang::QUEEN:
				std::cout << "Queen "; break;
			case learndalang::UNKNOWN:
				std::cout << "PROGRAM ERROR!!!";
			}
			std::cout << "at "
					<< learndalang::FileToChar(p.file) << p.rank << std::endl;
}
} /* namespace learndalang */
