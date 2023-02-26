// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    
    // Write your code here
    bool isFalling = false;
    bool isRising = false;
    bool wasLastRising = false;
    uint8_t numberOfSlopes = 0;
    uint8_t i = 0;
    for(i = 0; i < v.size()-1; i++)
    {
        if(v[i] < v[i+1])
        {
            isFalling = false;
            if(!isRising)
            {
                numberOfSlopes++;
            }
            isRising = true;
        }
        else if(v[i] > v[i+1])
        {
            isRising = false;
            if(!isFalling)
            {
                numberOfSlopes++;
            }
            isFalling = true;
        }
        wasLastRising = (isRising || isFalling)? isRising : wasLastRising;
        if(v[i] == v[i+1])
        {
            isRising = false;
            isFalling = false;
        }
    }
    bool isValidThird = false;
    if (numberOfSlopes == 3)
    {
        isValidThird = ((!wasLastRising && v[i] >= v[0]) || (wasLastRising && v[i] <= v[0]));
    }
    return (numberOfSlopes < 3 || isValidThird);
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    std::vector<int> myvec1 = {1, 1, 1, 1, 1};  // Yes
    std::vector<int> myvec2 = {3, 4, 5, 2, 2};  // Yes
    std::vector<int> myvec3 = {3, 4, 5, 2, 4};  // No
    std::vector<int> myvec4 = {1, 2, 3, 4, 5};  // Yes
    std::vector<int> myvec5 = {1, 2, 3, 1, 2};  // No
    std::vector<int> myvec6 = {5, 4, 6, 2, 6};  // No
    std::vector<int> myvec7 = {5, 4, 3, 2, 1};  // Yes
    std::vector<int> myvec8 = {5, 4, 3, 2, 6};  // Yes
    std::vector<int> myvec9 = {5, 4, 6, 5, 4};  // No
    std::vector<int> myvec10 = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec1) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec2) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec3) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec4) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec5) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec6) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec7) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec8) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec9) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << (is_bitonic(myvec10) == true ? "Yes, it is bitonic.\n" : "No, it is not bitonic.\n");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
