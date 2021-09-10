/*********************************************************************
 * BinaryGap.cs returns longest substring of zeros surrounded by ones.
 *********************************************************************/
public int binaryGap(int N) {
    string bits = Convert.ToString(N, 2);
    int length = 0;
    int bestLength = 0;
    int tempCount = 0;
    for (int i = 0; i < bits.Length; i++) {
        if (bits[i] == '0') {
            if (tempCount > 0) {
                tempCount++;
            }
            else {
                tempCount = 1;
            }
        }
        else {
            tempCount = 0;
        }
        if (tempCount > length) length = tempCount;
        if (bits[i] == '1' && length > bestLength) bestLength = length;
    }
    return bestLength;
}
