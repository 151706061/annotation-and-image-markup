/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/


#ifndef DDPIIMPL_H
#define DDPIIMPL_H

#include "dcmtk/config/osconfig.h"

#include "dcmtk/dcmdata/dcddirif.h"

#include "dcmtk/dcmjpeg/djdefine.h"


/*---------------------*
 *  class declaration  *
 *---------------------*/

/** Implementation of the plugable image support for the DICOMDIR class
 */
class DCMTK_DCMJPEG_EXPORT DicomDirImageImplementation
  : public DicomDirImagePlugin
{
  public:

    /** constructor
     */
    DicomDirImageImplementation();

    /** destructor
     */
    virtual ~DicomDirImageImplementation();

    /** scale given pixel data (monochrome only).
     *  The destination pixel data array needs to be allocated by the caller.
     *  @param srcData source pixel data (byte array)
     *  @param srcWidth width of the source pixel data (in pixels)
     *  @param srcHeight height of the source pixel data (in pixels)
     *  @param dstData destination pixel data (resulting byte array, not NULL)
     *  @param dstWidth width of the scaled pixel data (in pixels)
     *  @param dstHeight height of the scaled pixel data (in pixels)
     *  @return OFTrue if successful, OFFalse otherwise
     */
    virtual OFBool scaleData(const Uint8 *srcData,
                             const unsigned int srcWidth,
                             const unsigned int srcHeight,
                             Uint8 *dstData,
                             const unsigned int dstWidth,
                             const unsigned int dstHeight) const;

    /** get scaled pixel data from DICOM image.
     *  The resulting scaled image (pixel array) is always monochrome.
     *  The resulting pixel data array needs to be allocated by the caller.
     *  @param dataset DICOM dataset in which the DICOM image is stored
     *  @param pixel resulting pixel data array (not NULL)
     *  @param count number of pixels allocated for the resulting array
     *  @param frame index of the frame to be scaled (1..n)
     *  @param width width of the scaled image (in pixels)
     *  @param height height of the scaled image (in pixels)
     *  @param decompressAll always decompress complete pixel data if true
     *  @return OFTrue if successful, OFFalse otherwise
     */
    virtual OFBool scaleImage(DcmItem *dataset,
                              Uint8 *pixel,
                              const unsigned long count,
                              const unsigned long frame,
                              const unsigned int width,
                              const unsigned int height,
                              const OFBool decompressAll = OFFalse) const;
};


#endif
