#pragma once

/// A series of short and long blinks, that represents and error
struct BlinkPattern {
    public:
    static constexpr int MAX_NUM_BLINKS = 16; /// The maximum number of blinks
    static const int shortBlinkDuration = 200000; /// The duration of the short blinks in microseconds (the long blinks are twice as long)
    static const int longBlinkDuration = 500000;
    static const int blinkGap = 200000; // The duration of the gap between blinks in microseconds

    int length; /// The number of short and long blinks in total
    bool pattern[MAX_NUM_BLINKS] = {0}; /// A pattern of long and short blinks

    /// Default constructor (creates a pattern with length 0)
    BlinkPattern();

    /// Constructs a blink pattern where the duration of the short blinks is BlinkPattern::shortBlinkDuration
    BlinkPattern(bool pattern[MAX_NUM_BLINKS], int numBlinks);
};