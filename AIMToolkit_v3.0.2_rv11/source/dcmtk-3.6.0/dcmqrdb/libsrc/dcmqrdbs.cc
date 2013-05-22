/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */
#include "dcmtk/dcmqrdb/dcmqrdbs.h"
#include "dcmtk/dcmdata/dcdatset.h"    /* for class DcmDataset */

#define INCLUDE_CSTDDEF
#include "dcmtk/ofstd/ofstdinc.h"


DcmQueryRetrieveDatabaseStatus::DcmQueryRetrieveDatabaseStatus(Uint16 s)
: status_(s)
, statusDetail_(NULL)
{
}

DcmQueryRetrieveDatabaseStatus::DcmQueryRetrieveDatabaseStatus(const DcmQueryRetrieveDatabaseStatus& org)
: status_(org.status_)
, statusDetail_(NULL)
{
  if (org.statusDetail_) statusDetail_ = OFstatic_cast(DcmDataset *, org.statusDetail_->clone());
}

DcmQueryRetrieveDatabaseStatus::~DcmQueryRetrieveDatabaseStatus()
{
  delete statusDetail_;
}

DcmQueryRetrieveDatabaseStatus& DcmQueryRetrieveDatabaseStatus::operator=(const DcmQueryRetrieveDatabaseStatus& org)
{
  if (this != &org)
  {
    status_ = org.status_;
    if (org.statusDetail_ != statusDetail_)
    {
      delete statusDetail_;
      if (org.statusDetail_) statusDetail_ = OFstatic_cast(DcmDataset *, org.statusDetail_->clone()); else statusDetail_ = NULL;
    }
  }
  return *this;
}

void DcmQueryRetrieveDatabaseStatus::deleteStatusDetail()
{
  delete statusDetail_;
  statusDetail_ = NULL;
}

DcmDataset *DcmQueryRetrieveDatabaseStatus::extractStatusDetail()
{
  DcmDataset *result = statusDetail_;
  statusDetail_ = NULL;
  return result;
}

/*
 * CVS Log
 * $Log: dcmqrdbs.cc,v $
 * Revision 1.5  2010-11-01 13:37:32  uli
 * Fixed some compiler warnings reported by gcc with additional flags.
 *
 * Revision 1.4  2010-10-14 13:14:36  joergr
 * Updated copyright header. Added reference to COPYRIGHT file.
 *
 * Revision 1.3  2009-08-21 09:54:11  joergr
 * Replaced tabs by spaces and updated copyright date.
 *
 * Revision 1.2  2005/12/08 15:47:10  meichel
 * Changed include path schema for all DCMTK header files
 *
 * Revision 1.1  2005/03/30 13:34:53  meichel
 * Initial release of module dcmqrdb that will replace module imagectn.
 *   It provides a clear interface between the Q/R DICOM front-end and the
 *   database back-end. The imagectn code has been re-factored into a minimal
 *   class structure.
 *
 *
 */
