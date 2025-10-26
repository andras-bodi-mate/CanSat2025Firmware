#include "blinkPattern.hpp"

BlinkPattern::BlinkPattern(): length(0), pattern({false}) {}

BlinkPattern::BlinkPattern(bool pattern[MAX_NUM_BLINKS], int numBlinks) : length(numBlinks) {
    for (int i = 0; i < MAX_NUM_BLINKS; i++) {
        this->pattern[i] = pattern[i];
    }
}