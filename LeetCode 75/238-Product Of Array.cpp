/**
 * Product of Array Except Self
 *
 * @ref https://leetcode.com/problems/reverse-vowels-of-a-string
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

/**
 * I have not come up with this solution on my own.
 * -    My first solution was the division method which fails when there is a 0 in vector.
 * -    My second solution was the 2 loop method where I skip the current iteration &
 *      multiply rest of the elements but this is not allowed.
 * -    I looked into this solution:
 *      @ref https://leetcode.com/problems/product-of-array-except-self/solutions/3186745/best-c-3-solution-dp-space-optimization-brute-force-optimize-one-stop-solution
 *      @ref https://www.youtube.com/watch?v=G9zKmhybKBM
 */
vector<int> productExceptSelf(vector<int> &nums) {
    int size = nums.size();
    vector<int> answers(size);
    vector<int> leftProducts(size);
    vector<int> rightProducts(size);

    leftProducts[0] = 1;
    rightProducts[size - 1] = 1;

    for (int idx = 1; idx < size; idx++) {
        leftProducts.at(idx) = nums.at(idx - 1) * leftProducts.at(idx - 1);
    }

    for (int idx = size - 2; idx >= 0; idx--) {
        rightProducts.at(idx) =
            rightProducts.at(idx + 1) * nums.at(idx + 1);
    }

    for (int idx = 0; idx < size; idx++) {
        answers.at(idx) = leftProducts.at(idx) * rightProducts.at(idx);
    }

    return answers;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    cout << "Original Vector: " << vectorIntToString(nums) << endl;
    cout << "Result Vector: " << vectorIntToString(productExceptSelf(nums)) << endl;
}