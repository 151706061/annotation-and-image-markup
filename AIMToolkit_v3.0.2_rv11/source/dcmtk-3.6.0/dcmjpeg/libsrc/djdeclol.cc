/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djdeclol.h"
#include "dcmtk/dcmjpeg/djcparam.h"
#include "dcmtk/dcmjpeg/djrplol.h"
#include "dcmtk/dcmjpeg/djdijg8.h"
#include "dcmtk/dcmjpeg/djdijg12.h"
#include "dcmtk/dcmjpeg/djdijg16.h"

DJDecoderLossless::DJDecoderLossless()
: DJCodecDecoder()
{
}


DJDecoderLossless::~DJDecoderLossless()
{
}


E_TransferSyntax DJDecoderLossless::supportedTransferSyntax() const
{
  return EXS_JPEGProcess14TransferSyntax;
}


DJDecoder *DJDecoderLossless::createDecoderInstance(
    const DcmRepresentationParameter * /* toRepParam */,
    const DJCodecParameter *cp,
    Uint8 bitsPerSample,
    OFBool isYBR) const
{
  if (bitsPerSample > 12) return new DJDecompressIJG16Bit(*cp, isYBR);
  else if (bitsPerSample > 8) return new DJDecompressIJG12Bit(*cp, isYBR);
  else return new DJDecompressIJG8Bit(*cp, isYBR);
}


/*
 * CVS/RCS Log
 * $Log: djdeclol.cc,v $
 * Revision 1.3  2010-10-14 13:14:21  joergr
 * Updated copyright header. Added reference to COPYRIGHT file.
 *
 * Revision 1.2  2005-12-08 15:43:31  meichel
 * Changed include path schema for all DCMTK header files
 *
 * Revision 1.1  2001/11/13 15:58:26  meichel
 * Initial release of module dcmjpeg
 *
 *
 */
