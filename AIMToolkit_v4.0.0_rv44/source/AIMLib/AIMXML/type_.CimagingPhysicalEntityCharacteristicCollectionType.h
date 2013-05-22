/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimagingPhysicalEntityCharacteristicCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimagingPhysicalEntityCharacteristicCollectionType



namespace AIMXML
{

class CimagingPhysicalEntityCharacteristicCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CimagingPhysicalEntityCharacteristicCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CimagingPhysicalEntityCharacteristicCollectionType(CimagingPhysicalEntityCharacteristicCollectionType const& init);
	void operator=(CimagingPhysicalEntityCharacteristicCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CimagingPhysicalEntityCharacteristicCollectionType); }
	MemberElement<CImagingPhysicalEntityCharacteristic, _altova_mi_altova_CimagingPhysicalEntityCharacteristicCollectionType_altova_ImagingPhysicalEntityCharacteristic> ImagingPhysicalEntityCharacteristic;
	struct ImagingPhysicalEntityCharacteristic { typedef Iterator<CImagingPhysicalEntityCharacteristic> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimagingPhysicalEntityCharacteristicCollectionType
