/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#pragma once
#ifndef _AIMLib_TwoDimensionMultiPoint_Class_
#define _AIMLib_TwoDimensionMultiPoint_Class_

namespace aim_lib
{
	class AIMLIB_API TwoDimensionMultiPoint : public TwoDimensionGeometricShapeEntity
	{
	public:
		TwoDimensionMultiPoint();
		TwoDimensionMultiPoint(const TwoDimensionMultiPoint& multiPoint);
		virtual ~TwoDimensionMultiPoint();
		virtual TwoDimensionMultiPoint* Clone() const;

		virtual const TwoDimensionShapeType GetShapeType() const;
	};
}
#endif // _AIMLib_TwoDimensionMultiPoint_Class_
