#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

class SensorInterface {
public:
    virtual int readTemperature() = 0;
    virtual bool sensorOK() = 0;

    virtual ~SensorInterface() {}
};

#endif
