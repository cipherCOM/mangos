/*
 *  EventRaidMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTRAIDMGR_H__
#define __EVENTRAIDMGR_H__

#include "EventSystemMgr.h"

class Group;

struct EventInfoRaid : public EventInfo
{
    const Group &group;
    // TODO: implement needed params

    EventInfoRaid(const Group &group_)
    : EventInfo(), group(group_) {}
};

class EventListenerRaid : public EventListener
{
public:
    virtual void EventRaidCreated(const EventInfoRaid &) {}
    virtual void EventRaidDisbanded(const EventInfoRaid &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugRaid : public EventListenerRaid
{
public:
    EventDebugRaid()
    {
        sEventSystemMgr(EventListenerRaid).RegisterListener(this);
    }
    void EventRaidCreated(const EventInfoRaid &info);
    void EventRaidDisbanded(const EventInfoRaid &info);
};
extern EventDebugRaid eventDebugRaid;
#endif

#endif // __EVENTRAIDMGR_H__
