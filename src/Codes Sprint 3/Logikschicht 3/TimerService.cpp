#include "TimerService.h"

TimerService::TimerService()
    : remainingSeconds(0), active(false) {}

void TimerService::start(int seconds) {
    remainingSeconds = seconds;
    active = true;
}

void TimerService::tick() {
    if (active && remainingSeconds > 0) {
        --remainingSeconds;
        if (remainingSeconds == 0) {
            active = false;
        }
    }
}

bool TimerService::isExpired() const {
    return !active && remainingSeconds == 0;
}
