#ifndef SAFETY_MANAGER_H
#define SAFETY_MANAGER_H

class SafetyManager {
private:
    bool safeState;
    int maxTemperature = 230;   // Sicherheitsgrenze

public:
    SafetyManager();

    void checkTemperature(int currentTemperature);
    bool isSafe() const;

    void resetSafetyState();
};

#endif
