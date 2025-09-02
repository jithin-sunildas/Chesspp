#include <iostream>
#include <string>

enum class Color { BLACK, WHITE };

enum class Direction { N, S, E, W, NE, NW, SE, SW };

struct Piece {
    int x;
    int y;
    int index;
    Color clr;
};

class Movement {
  public:
    void plusMovement(Piece &piece, Direction dir, int cells_to_move) {
        switch (dir) {
        case Direction::N:
            piece.y += cells_to_move;
            break;
        case Direction::S:
            piece.y -= cells_to_move;
            break;
        case Direction::W:
            piece.x -= cells_to_move;
            break;
        case Direction::E:
            piece.x += cells_to_move;
            break;
        default:
            break;
        }
    }

    void crossMovement(Piece &piece, Direction dir, int cells_to_move) {
        switch (dir) {
        case Direction::NE:
            piece.x += cells_to_move;
            piece.y += cells_to_move;
            break;
        case Direction::NW:
            piece.x -= cells_to_move;
            piece.y += cells_to_move;
            break;
        case Direction::SE:
            piece.x += cells_to_move;
            piece.y -= cells_to_move;
            break;
        case Direction::SW:
            piece.x -= cells_to_move;
            piece.y -= cells_to_move;
            break;
        default:
            break;
        }
    }
};

class Pawn {
  public:
    Pawn(Color clr, int row, int col, int index) : side(clr) {
        pawn.x = row;
        pawn.y = col;
        pawn.index = index;
    }

  private:
    Piece pawn;
    const Color side;
};

class Knight {
  public:
    Knight(Color clr, int row, int col, int index) : side(clr) {
        knight.x = row;
        knight.y = col;
        knight.index = index;
    }

  private:
    Piece knight;
    const Color side;
};

class Rook {
  public:
    Rook(Color clr, int row, int col, int index) : side(clr) {
        rook.x = row;
        rook.y = col;
        rook.index = index;
    }

  private:
    Piece rook;
    const Color side;
};

class Bishop {
  public:
    Bishop(Color clr, int row, int col, int index) : side(clr) {
        bishop.x = row;
        bishop.y = col;
        bishop.index = index;
    }

  private:
    Piece bishop;
    const Color side;
};

class Queen {
  public:
    Queen(Color clr, int row, int col) : side(clr) {
        queen.x = row;
        queen.y = col;
        queen.index = 1;
    }

  private:
    Piece queen;
    const Color side;
};

class King {
  public:
    King(Color clr, int row, int col) : side(clr) {
        king.x = row;
        king.y = col;
        king.index = 1;
    }

  private:
    Piece king;
    const Color side;
};

int main() {
    std::string hi = "hello world!";
    std::cout << hi << "\n";
    return 0;
}
