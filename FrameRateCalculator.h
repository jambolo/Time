/** @file *//********************************************************************************************************

                                                FrameRateCalculator.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Time/FrameRateCalculator.h#5 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! A class that keeps track of the frame rate.

class FrameRateCalculator
{
public:

	//! Constructor
	FrameRateCalculator();

	//! Updates the state and computes the new frame rate values
	void Update( __int64 t );

	//! Returns the frame rate for the previous frame
	float GetFrameRate() const									{ return m_FrameRate; }

	//! Returns the average frame rate over the previous second
	//
	//! 
	//! @note	This value is updated every second (at most).
	float GetAverageFrameRate() const							{ return m_AverageFrameRate; }

private:

	__int64		m_OldTime;				//!< Time of the previous update
	__int64		m_OldTime2;				//!< Time of the previous 1 second update
	int			m_nFrames;				//!< Number of frames since the previous 1 second update
	float		m_FrameRate;			//!< Frame rate of the previous frame
	float		m_AverageFrameRate;		//!< Frame rate of the previous 1 second interval
};
