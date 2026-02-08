#pragma once

class Speed {
    public:
    Speed(bool isValid = false, float speed = 0.0);
    bool isValid;
    float value; /// Speed in meters per second
};