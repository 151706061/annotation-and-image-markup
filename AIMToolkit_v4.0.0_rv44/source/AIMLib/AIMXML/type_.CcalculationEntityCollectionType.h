/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcalculationEntityCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcalculationEntityCollectionType



namespace AIMXML
{

class CcalculationEntityCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CcalculationEntityCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CcalculationEntityCollectionType(CcalculationEntityCollectionType const& init);
	void operator=(CcalculationEntityCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CcalculationEntityCollectionType); }
	MemberElement<CCalculationEntity, _altova_mi_altova_CcalculationEntityCollectionType_altova_CalculationEntity> CalculationEntity;
	struct CalculationEntity { typedef Iterator<CCalculationEntity> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcalculationEntityCollectionType
