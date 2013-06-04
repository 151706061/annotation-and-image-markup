/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcharacteristicQuantificationCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcharacteristicQuantificationCollectionType



namespace AIMXML
{

class CcharacteristicQuantificationCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CcharacteristicQuantificationCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CcharacteristicQuantificationCollectionType(CcharacteristicQuantificationCollectionType const& init);
	void operator=(CcharacteristicQuantificationCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CcharacteristicQuantificationCollectionType); }
	MemberElement<CCharacteristicQuantification, _altova_mi_altova_CcharacteristicQuantificationCollectionType_altova_CharacteristicQuantification> CharacteristicQuantification;
	struct CharacteristicQuantification { typedef Iterator<CCharacteristicQuantification> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcharacteristicQuantificationCollectionType
