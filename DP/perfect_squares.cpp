#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// dynamic programming solution
class Solution_1 {
public:
    int numSquares(int n) {
        if (n <= 0)
            return 0;

        // cnt_perfect_squares[i] : the least number of perfect square number which sum to i, note that cnt_perfect_square[0] = 0
        vector<int> cnt_perfect_squares(n+1, INT_MAX);
        cnt_perfect_squares[0] = 0;
        for (int i = 1 ; i < n+1 ; ++i) {
            // for each i, it must be the sum of (i - j*j) and a perfect square number (j*j)
            for (int j = 1 ; j*j <= i ; ++j)
                cnt_perfect_squares[i] = cnt_perfect_squares[i - j*j] + 1 < cnt_perfect_squares[i] ? cnt_perfect_squares[i - j*j] + 1 : cnt_perfect_squares[i];
        }

        return cnt_perfect_squares[n];
    }
};

// mathematical solution
class Solution_2 {
public:
    // based on lagrange's four square theorem, there are only 4 possible results: 1, 2, 3, 4
    int numSquares(int n) {
        // if n is a perfect square, return 1
        if (is_square(n))
            return 1;

        // the result is 4 if and only if n = 4^k * (8*m + 7)
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;

        // check whether 2 is the result
        int sqrt_n = static_cast<int>(sqrt(n));
        for (int i = 1 ; i <= sqrt_n ; ++i)
            if (is_square(n - i * i))
                return 2;

        // otherwise, return 3
        return 3;
    }
private:
    bool is_square(int n) {
        int sqrt_n = static_cast<int>(sqrt(n));
        return sqrt_n * sqrt_n == n;
    }
};


int main() {
    int n = 13;
    Solution_1 sol1;   // dynamic programming solution
    Solution_2 sol2;   // mathematical solution
    cout << sol1.numSquares(n) << endl;
    cout << sol2.numSquares(n) << endl;
    return 0;
}
