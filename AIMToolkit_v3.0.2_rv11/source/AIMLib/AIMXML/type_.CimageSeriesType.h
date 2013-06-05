/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageSeriesType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageSeriesType



namespace AIMXML
{

class CimageSeriesType : public TypeBase
{
public:
	AIMXML_EXPORT CimageSeriesType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CimageSeriesType(CimageSeriesType const& init);
	void operator=(CimageSeriesType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CimageSeriesType); }
	MemberElement<CImageSeries, _altova_mi_altova_CimageSeriesType_altova_ImageSeries> ImageSeries;
	struct ImageSeries { typedef Iterator<CImageSeries> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageSeriesType
