/*********************************************************************
 * BinaryGap.cs returns longest substring of zeros surrounded by ones.
 * Runs O(N).
 *********************************************************************/
public int BinaryGap(int N) {
    // Convert N to a binary string of 0's and 1's.
    string bits = Convert.ToString(N, 2);

    int length = 0;     // Current 0 string length.
    int bestLength = 0; // Best 0 string length so far.
    int tempCount = 0;  // Intermediate 0 counter.
    

    for (int i = 0; i < bits.Length; i++) {
        if (bits[i] == '0') {
            if (tempCount > 0) { // it's the second or higher 0 encountered...
                tempCount++;     // increment temp count.
            }
            else {
                tempCount = 1;   // it's the first 0.
            }
        }
        else {
            tempCount = 0;       // it's a 1, so reset tempCount.
        }
        // Conditionally update current 0 length if tempCount better than current string length.
        if (tempCount > length) 
            length = tempCount;
        // If a closing 1 and new length better than best length so far, update bestLength.
        if (bits[i] == '1' && length > bestLength)
            bestLength = length;
    
    }

    return bestLength;
}
