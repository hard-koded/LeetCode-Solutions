// Problem solved with no memory allocation using only pointers and pointers arithmetic.

/**
 * Return -2 if ch is the null terminator character '\0'.
 * Return -1 if s does not contain ch, otherwise return the index of the first character in s equal to ch.
 */
int getIndexOfRepeatingChar(char* s, int sWinSize, char ch) {
    if (ch == '\0') {
        return -2;
    }

    int i = 0;
    while (i < sWinSize - 1 && s[i] != ch) { ++i; }
    return s[i] == ch ? i : -1;
}

int lengthOfLongestSubstring(char* s) {
    if (*s == '\0') {
        return 0;
    }

    int sWinSize = 1;

    char* advancingWin = s;
    int advancingWinSize = 1;
    char* advancingWinStart = s;

    while (*advancingWin != '\0') {
        int indexRepeatingChar = getIndexOfRepeatingChar(advancingWinStart, advancingWinSize, *(advancingWin + 1));

        if (indexRepeatingChar == -2) {
            // Exit while loop (do not increment size)
            ++advancingWin;
        }
        else if (indexRepeatingChar == -1) {
            // The next character is not present, increment the window
            ++advancingWin;
            ++advancingWinSize;
        }
        else {
            // The next character is already present

            // If the new window (advancingWin) is longer than the window of s,
            // save the state of the new window to s
            if (sWinSize < advancingWinSize) {
                s = advancingWinStart;
                sWinSize = advancingWinSize;
            }

            // Update advancingWin
            advancingWinSize -= indexRepeatingChar;
            advancingWinStart = advancingWinStart + indexRepeatingChar + 1;
            ++advancingWin;
        }
    }

    return sWinSize >= advancingWinSize ? sWinSize : advancingWinSize;
}
