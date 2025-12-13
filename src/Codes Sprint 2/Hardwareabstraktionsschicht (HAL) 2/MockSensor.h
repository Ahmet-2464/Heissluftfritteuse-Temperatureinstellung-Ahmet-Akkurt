#ifndef MOCK_SENSOR_H
#define MOCK_SENSOR_H

#include "SensorInterface2.h"

class MockSensor : public SensorInterface {
private:
    int simulatedValue;

public:
    MockSensor() : simulatedValue(25) {}

    int readTemperature() override { return simulatedValue; }
    bool sensorOK() override { return true; }

    void setSimulatedValue(int value) { simulatedValue = value; }
};

#endif
