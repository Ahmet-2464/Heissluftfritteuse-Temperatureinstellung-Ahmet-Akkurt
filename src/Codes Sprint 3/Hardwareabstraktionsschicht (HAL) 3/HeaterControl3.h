#pragma once

class HeaterControl {
public:
    virtual ~HeaterControl() = default;
    virtual void on() = 0;
    virtual void off() = 0;
};
