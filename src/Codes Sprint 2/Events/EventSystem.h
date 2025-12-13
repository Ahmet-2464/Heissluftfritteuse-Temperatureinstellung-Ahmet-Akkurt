#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H

#include <functional>
#include <map>
#include <vector>

enum class EventType {
    TEMP_CHANGED,
    OVERHEAT,
    BUTTON_PRESS,
    SYSTEM_ERROR
};

class EventSystem {
private:
    std::map<EventType, std::vector<std::function<void()>>> callbacks;

public:
    void registerCallback(EventType type, std::function<void()> callback);
    void triggerEvent(EventType type);
};

#endif
