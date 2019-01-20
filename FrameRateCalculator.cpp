#include "FrameRateCalculator.h"

#include "Clock.h"

FrameRateCalculator::FrameRateCalculator()
    : m_nFrames(0)
    , m_FrameRate(0.0f)
    , m_AverageFrameRate(0.0f)
{
    m_OldTime = m_OldTime2 = Clock::Instance().GetTime();
}

//!
//! @param	t	Time of current frame in ticks

void FrameRateCalculator::Update(__int64 t)
{
    Clock & clock = Clock::Instance();          // Convenience

    __int64 dt  = t - m_OldTime;            // Time since previous update
    __int64 dt2 = t - m_OldTime2;           // Time since previous 1 second update

    // Update the frame rate value

    if (dt > 0)
        m_FrameRate = float(1.0 / clock.ToSeconds(dt));
    else
        m_FrameRate = 0;

    m_OldTime = t;  // Save the current time for next time

    // Update the average frame rate

    ++m_nFrames;

    // If 1 second has passed, compute the new average FPS value and reset the counters

    if (dt2 > clock.GetFrequency())
    {
        m_AverageFrameRate = (float)m_nFrames / (float)clock.ToSeconds(dt2);

        m_OldTime2 = t; // Save the current time for next time
        m_nFrames  = 0; // Reset the frame counter
    }
}
