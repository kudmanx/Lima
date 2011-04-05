#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <ostream>
#include <vector>

namespace lima
{

enum AlignDir {
	Floor, Ceil,
};

std::ostream& operator <<(std::ostream& os, AlignDir align_dir);
/**@brief ImageType is the depth of detectors images
 * - Bpp8 means 8 bits unsigned
 * - Bpp8S means 8 bits signed....
 */
enum ImageType {
	Bpp8, Bpp8S, Bpp10, Bpp10S, Bpp12, Bpp12S, Bpp14, Bpp14S, 
	Bpp16, Bpp16S, Bpp32, Bpp32S
};

std::ostream& operator <<(std::ostream& os, ImageType image_type);

enum AcqMode {
	Single, Concatenation, Accumulation,
};

std::ostream& operator <<(std::ostream& os, AcqMode acq_mode);

enum TrigMode {
	IntTrig,IntTrigMult,
	ExtTrigSingle, ExtTrigMult,
	ExtGate, ExtStartStop,
	Live,
};

std::ostream& operator <<(std::ostream& os, TrigMode trig_mode);

enum BufferMode {
	Linear, Circular,
};

std::ostream& operator <<(std::ostream& os, BufferMode buffer_mode);

enum ShutterMode {
  ShutterManual, ShutterAutoFrame, ShutterAutoSequence
};

typedef std::vector<ShutterMode> ShutterModeList;

std::ostream& operator <<(std::ostream& os, ShutterMode shutter_mode);

enum AcqStatus {
	AcqReady, AcqRunning, AcqFault,
};

std::ostream& operator <<(std::ostream& os, AcqStatus acq_status);

enum DetStatus {
	DetIdle			= 0x00,
	DetFault		= 0x01, 
	DetWaitForTrigger	= 0x02,
	DetShutterOpen		= 0x04,
	DetExposure		= 0x08,
	DetShutterClose		= 0x10,
	DetChargeShift		= 0x20,
	DetReadout		= 0x40,
	DetLatency		= 0x80,
};

DetStatus  operator | (DetStatus  s1, DetStatus  s2);
DetStatus& operator |=(DetStatus& s1, DetStatus  s2);

std::ostream& operator <<(std::ostream& os, DetStatus det_status);

enum VideoMode {Y8,Y16,Y32,Y64,
		RGB555,RGB565,
		RGB24,RGB32,
		BGR24,BGR32,
		BAYER_RG8,BAYER_RG16,
		I420,YUV411,YUV422,YUV444};

} // namespace lima

#endif // CONSTANTS_H
