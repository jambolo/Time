/** @file *//********************************************************************************************************

                                                       Timer.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Time/Timer.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! A class that measures time durations

class Timer
{
public:

	//! Constructor
	Timer();

	//! Destructor
	~Timer();

	//! Starts the timer
	__int64 Start();

	//! Stops the timer
	__int64 Stop();

	//! Resumes the timer
	__int64 Resume();

	//! Returns the elapsed time
	__int64 Elapsed();

private:

	__int64	m_StartTime;	//!< Time at which the timer started
	__int64	m_StopTime;		//!< Time at which the timer was stopped (if it is not running)
	bool	m_Running;		//!< @c true if the timer is running
};
