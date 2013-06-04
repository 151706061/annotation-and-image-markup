/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CreferencedCalculationCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CreferencedCalculationCollectionType



namespace AIMXML
{

class CreferencedCalculationCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CreferencedCalculationCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CreferencedCalculationCollectionType(CreferencedCalculationCollectionType const& init);
	void operator=(CreferencedCalculationCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CreferencedCalculationCollectionType); }
	MemberElement<CReferencedCalculation, _altova_mi_altova_CreferencedCalculationCollectionType_altova_ReferencedCalculation> ReferencedCalculation;
	struct ReferencedCalculation { typedef Iterator<CReferencedCalculation> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CreferencedCalculationCollectionType
