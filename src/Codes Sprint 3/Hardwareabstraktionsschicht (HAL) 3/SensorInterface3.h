#pragma once

class SensorInterface {
public:
    virtual ~SensorInterface() = default;
    virtual float readTemperature() = 0;
};
