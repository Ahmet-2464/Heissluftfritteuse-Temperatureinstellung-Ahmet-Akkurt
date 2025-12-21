#pragma once

class TimerService {
private:
    int remainingSeconds;
    bool active;

public:
    TimerService();

    void start(int seconds);
    void tick();               // wird zyklisch aufgerufen
    bool isExpired() const;
};
