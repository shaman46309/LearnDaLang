/*
 * case3.h
 *
 * Demo of stl containers.
 *
 *  Created on: Mar 4, 2015
 *      Author: pankajm
 */

#ifndef CASE3_H_
#define CASE3_H_

#include <vector>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <stack>
//#include <tuple>
#include <unordered_map>
#include <unordered_set>

namespace learndalang {
enum PieceKind {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, UNKNOWN};
enum PieceColor {BLACK, WHITE};
enum Rank {ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT};
enum File {a, b, c, d, e, f, g, h};
class ChessPiece {
public:
	PieceKind kind;
	PieceColor color;
	Rank rank;
	File file;

	// Color = binary. Lets assign multiplier = +1 or -1 for white or black
	// kind = 0 to 6
	// rank = 1 to 8
	// file = 0 to 7
	// lets compute hash = (kind * 100 + rank * 10 + file ) * multiplier
	inline int hash() const {
		int multiplier = (color == WHITE ? 1 : -1);
		return multiplier * (100 * kind + rank * 10 + file);
	}

	// The operator should take into account color, kind and position.
	bool operator< (const ChessPiece& c) const {
	    return (this->hash() < c.hash());
	}

};


char FileToChar(File file);

class Case3 {
public:
	Case3();
	virtual ~Case3();

	void PrintVector();
	void PrintSet();
	void PrintQueue();
	void PrintStack();
	void PrintList();
	void PrintMap();

	// These should be private in the real world.
	// Here we open up access just to demo these containers.
	std::vector<ChessPiece> pieces_vector;
	std::set<ChessPiece> pieces_set;
	/*
	 * What does this error mean?
	 * /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/c++/v1/memory:1908:55: error: no member named 'value' in 'std::__1::is_empty<std::__1::hash<learndalang::ChessPiece> >'
                                bool = is_empty<_T2>::value
                                       ~~~~~~~~~~~~~~~^
	 *
	 */
//	std::unordered_set<ChessPiece> pieces_unordered_set;
	std::list<ChessPiece> pieces_list;
	std::map<ChessPiece, PieceColor> pieces_color_map;
	/*
	 * What does this error mean?
	 * no member named 'value' in
	 * 'std::__1::is_empty<std::__1::hash<learndalang::ChessPiece> >'
	 *
	 */
//	std::unordered_map<ChessPiece, PieceColor> pieces_color_unordered_map;
	std::queue<ChessPiece> pieces_queue;
	std::stack<ChessPiece> pieces_stack;
	// Tuple is a new feature : C++ 11?
//	std::tuple<Rank, File> piece_location;

	// Convenience objects
	// These should be static and statically initialized
	// TODO(pankajm): Figure out how to do this in C++
	/*
	 * class XYZ {
	 * static {
	 *   black_king = InitBlackKing();
	 *   white_king = InitWhiteKing();
	 * }
	 * }
	 */
	ChessPiece black_king;
	ChessPiece white_king;

private:
	void PrintPiece(ChessPiece);
};

} /* namespace learndalang */

#endif /* CASE3_H_ */
