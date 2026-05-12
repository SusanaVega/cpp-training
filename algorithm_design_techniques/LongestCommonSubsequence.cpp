#include <iostream>
#include <string>
#include <algorithm>


class LongestCommonSubsequence
{
private:
    /* data */
public:
    static int lcs(std::string_view A, std::string_view B){
        // Get the length of each input string.
        int m = A.length();
        int n = B.length();

        int dp[m + 1][n + 1];

        // Loop through each cell in the 2D array.
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
            // Base case: If either of the strings is empty, LCS length is 0.
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                //If the corresponding characters in A and B are equal,
                // then we can extend the LCS for A[0..i-2] and B[0..j-2] by 1.
                else if(A[i-1] == B[j-1] && (std::isdigit(A[i-1]) && std::isdigit(B[j-1])) ) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                // If the corresponding characters in A and B are different,
                // take the maximum LCS length between A[0..i-1] & B[0..j-2] or A[0..i-2] & B[0..j-1].
                else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // The value at dp[m][n] contains the length of LCS for A and B.
        return dp[m][n];
    }
};


int main(){
    std::string sequence1 = "AB13cD90azK";
    std::string sequence2 = "zAB173QdK80";

    int lenghtOfLCS = LongestCommonSubsequence::lcs(sequence1, sequence2);
    std::cout << "The length of the longest common subsequence is: " << lenghtOfLCS << std::endl;
    return 0;
}