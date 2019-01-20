#pragma once

#if !defined(TIME_CLOCK_H)
#define TIME_CLOCK_H

#include <Misc/Singleton.h>

//! A Singleton class that keeps track of the time

class Clock : Singleton<Clock>
{
public:

    //! Returns a reference to the only instance of Clock
    static Clock & Instance();

    //! Returns the current time
    __int64 GetTime() const;

    //! Returns the time elapsed since the given time (can be < 0)
    __int64 ElapsedSince(__int64 start) const;

    //! Returns true if the current time is later than the specified time
    bool IsPast(__int64 end) const;

    //! Converts ticks to seconds
    double ToSeconds(__int64 ticks) const;

    //! Converts seconds to ticks
    __int64 ToTicks(double seconds) const;

    //! Returns the clock tick frequency (ticks per second)
    __int64 GetFrequency() const { return m_frequency; }

    //! Returns the interval between ticks (in seconds)
    double GetInterval() const { return m_interval; }

private:

    //! Constructor and destructor are private to prevent external construction and destruction
    Clock();
    ~Clock() = default;

    __int64 m_frequency;                // Clock tick frequency
    double m_interval;                  // Clock tick interval (1/frequency)
};

//! @param	start	Start time
//!
//! @return			Ticks since start time

inline __int64 Clock::ElapsedSince(__int64 start) const
{
    return GetTime() - start;
}

//! @param	end		End time
//!
//! @return			@c true, if the current time is past the end time

inline bool Clock::IsPast(__int64 end) const
{
    return ElapsedSince(end) > 0;
}

//! @param	ticks	Number of ticks
//!
//! @return		Value in seconds
//!
//! @warning	The precision of the returned value is limited to the precision of @c double, which is less than
//!				the precision of of the @c ticks value.

inline double Clock::ToSeconds(__int64 ticks) const
{
    return double(ticks) * m_interval;
}

//! @param	seconds	Number of seconds
//!
//! @return		Value in ticks
//!
//! @warning	The precision of the returned value is limited to the precision of @c double, which is less than
//!				the precision of of the return value.

inline __int64 Clock::ToTicks(double seconds) const
{
    return __int64(seconds / m_interval + 0.5);
}

#endif // !defined(TIME_CLOCK_H)
