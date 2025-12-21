#pragma once
#include "SensorInterface3.h"

class MockSensor : public SensorInterface {
private:
    float temperature;

public:
    MockSensor(float temp = 20.0f) : temperature(temp) {}

    void setTemperature(float temp) {
        temperature = temp;
    }

    float readTemperature() override {
        return temperature;
    }
};
