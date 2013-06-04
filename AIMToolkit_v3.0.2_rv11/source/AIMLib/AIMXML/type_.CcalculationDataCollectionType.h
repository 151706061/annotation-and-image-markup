/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcalculationDataCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcalculationDataCollectionType



namespace AIMXML
{

class CcalculationDataCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CcalculationDataCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CcalculationDataCollectionType(CcalculationDataCollectionType const& init);
	void operator=(CcalculationDataCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CcalculationDataCollectionType); }
	MemberElement<CCalculationData, _altova_mi_altova_CcalculationDataCollectionType_altova_CalculationData> CalculationData;
	struct CalculationData { typedef Iterator<CCalculationData> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcalculationDataCollectionType
