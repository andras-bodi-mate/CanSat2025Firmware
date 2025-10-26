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
    operator float() {return value;}
};
const RadioFrequency RadioFrequency::A(434.0);
const RadioFrequency RadioFrequency::B(868.2);
const RadioFrequency RadioFrequency::C(868.5);