#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

// Maximum number of cows as per problem constraints (usually N <= 5000)
const int MAXN = 5005;

// Array to store the direction of cows: 0 for 'F' (Forward), 1 for 'B' (Backward)
int dir[MAXN]; 
// Array to track where flips occur; f[i] = 1 means a flip operation starts at index i
int f[MAXN];   
int N;

/**
 * Calculates the minimum operations needed for a fixed K.
 * @param K The size of the group to flip.
 * @return The number of operations, or -1 if impossible.
 */
int solve(int K) {
    // Reset the flip array
    memset(f, 0, sizeof(f));
    int operations = 0;
    int current_flips = 0; // Tracks the number of active flips covering the current position

    for (int i = 0; i < N; ++i) {
        // If we have moved past the range of a previous flip, remove its effect.
        // A flip starting at (i - K) ends at (i - 1), so it no longer affects i.
        if (i - K >= 0) {
            current_flips -= f[i - K];
        }

        // Determine the current state of cow i.
        // The cow is flipped if (original_state + current_flips) is odd.
        // We want the final state to be 0 ('F').
        // If current state is 1 ('B'), we MUST flip.
        if ((dir[i] + current_flips) % 2 != 0) {
            // We need to perform a flip starting at i.
            // Check if a flip of size K is possible within the remaining range.
            if (i + K > N) {
                return -1; // Impossible to flip this cow without going out of bounds
            }
            
            operations++;
            f[i] = 1;        // Mark that a flip started here
            current_flips++; // Increment active flips count
        }
    }
    return operations;
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read N
    if (!(cin >> N)) return 0;

    // Read cow directions
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        if (c == 'F') dir[i] = 0;
        else dir[i] = 1; // 'B' is 1, needs to become 0
    }

    int min_ops = N + 1; // Initialize with a value larger than max possible operations
    int best_K = 1;

    // Iterate through all possible values of K from 1 to N
    // N <= 5000, so O(N^2) complexity is acceptable (~2.5 * 10^7 operations)
    for (int K = 1; K <= N; ++K) {
        int ops = solve(K);
        if (ops != -1) {
            // We want the smallest K that achieves the minimum operations.
            // Since we iterate K from 1 upwards, we only update if we find a strictly smaller ops count.
            if (ops < min_ops) {
                min_ops = ops;
                best_K = K;
            }
        }
    }

    // Output the result: K and M
    cout << best_K << " " << min_ops << endl;

    return 0;
}
