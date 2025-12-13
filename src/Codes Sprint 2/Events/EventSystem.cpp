#include "EventSystem.h"

void EventSystem::registerCallback(EventType type, std::function<void()> callback) {
    callbacks[type].push_back(callback);
}

void EventSystem::triggerEvent(EventType type) {
    for (auto& cb : callbacks[type]) {
        cb();
    }
}
