#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
** Given a strictly increasing array A of positive integers forming a sequence,
** find the length of the longest fibonacci-like subsequence of A.
** If one does not exist, return 0.
*/

int lenLongestFibSubseq(vector<int>& A) {
    int N = (int) A.size();
    unordered_map<int, int> index;
    for (int i = 0; i < N; ++i)
        index[A[i]] = i;
    
    unordered_map<int, int> longest;
    int ans = 0;
    for (int k = 0; k < N; ++k)
        for (int j = 0; j < k; ++j) {
            if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                int i = index[A[k] - A[j]];
                longest[j * N + k] = longest[i * N + j] + 1;
                ans = max(ans, longest[j * N + k] + 2);
            }
        }
    
    return ans >= 3 ? ans : 0;
}

int main(int argc, const char * argv[]) {
    vector<int> v = {1,3,7,11,12,14,18,25};
    cout << lenLongestFibSubseq(v) << endl;
    
    return 0;
}
