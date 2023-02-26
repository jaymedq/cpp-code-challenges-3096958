// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    // Write your code here
    const int possibleMoves[8][2] = {{+1,+2}, {+2,+1}, {+2,-1}, {+1,-2}, {-1, -2}, {-2,-1}, {-2,+1}, {-1,+2}};
    int column = 0;
    int newColumn = 0;
    int row = 0;
    int newRow = 0;

    std::transform(knight.begin(), knight.end(), knight.begin(), tolower);
    column = static_cast<int>(knight[0]) - 'a';
    row = static_cast<int>(knight[1]) - '1';

    for(int i = 0; i < 8; i++)
    {
        newColumn = column + possibleMoves[i][0];
        newRow = row + possibleMoves[i][1];
        if((newColumn >= 1 && newColumn <=8)&&(newRow >= 1 && newRow <=8))
        {
            std::string new_loc = "  ";
            new_loc[0] = newColumn + 'a';
            new_loc[1] = newRow + '1';
            moves.push_back(new_loc);
        }
    }
    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}