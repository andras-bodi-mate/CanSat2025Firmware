#pragma once

/// Represents a radio frequency
struct RadioFrequency {
    private:

    private:
    float value;
    /// Creates a radio frequency
    /// @param value The radio frequency in kHz
    RadioFrequency(float value): value(value) {}
    public:

    /// 434.0 kHz
    static const RadioFrequency A;

    /// 868.2 kHz
    static const RadioFrequency B;

    /// 868.5 kHz
    static const RadioFrequency C;

    bool operator ==(const RadioFrequency& other) {
        return value == other.value;
    }
    operator float() {return value;}
};