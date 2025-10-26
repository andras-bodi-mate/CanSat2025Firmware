#pragma once

/// Represents a pattern to blink in
struct BlinkPattern {
    public:
    static constexpr int MAX_NUM_BLINKS = 16; /// The maximum number of blinks
    static const int shortDuration = 100; /// The duration of the short blinks in milliseconds (the long blinks are twice as long)
    static const int longBlinkDuration = 200;
    static const int shortBlinkDuration = 100;

    int length; /// The number of short and long blinks in total
    bool pattern[MAX_NUM_BLINKS] = {0}; /// A pattern of long and short blinks

    /// Default constructor (creates a pattern with length 0)
    BlinkPattern();

    /// Constructs a blink pattern where the duration of the short blinks is 100 milliseconds
    BlinkPattern(bool pattern[MAX_NUM_BLINKS], int numBlinks);
};