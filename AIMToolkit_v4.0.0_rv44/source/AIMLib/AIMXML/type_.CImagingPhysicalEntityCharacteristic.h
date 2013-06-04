/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImagingPhysicalEntityCharacteristic
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImagingPhysicalEntityCharacteristic



namespace AIMXML
{

class CImagingPhysicalEntityCharacteristic : public TypeBase
{
public:
	AIMXML_EXPORT CImagingPhysicalEntityCharacteristic(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CImagingPhysicalEntityCharacteristic(CImagingPhysicalEntityCharacteristic const& init);
	void operator=(CImagingPhysicalEntityCharacteristic const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CImagingPhysicalEntityCharacteristic); }
	MemberElement<iso::CCD, _altova_mi_altova_CImagingPhysicalEntityCharacteristic_altova_typeCode> typeCode;
	struct typeCode { typedef Iterator<iso::CCD> iterator; };
	MemberElement<iso::CCD, _altova_mi_altova_CImagingPhysicalEntityCharacteristic_altova_questionTypeCode> questionTypeCode;
	struct questionTypeCode { typedef Iterator<iso::CCD> iterator; };
	MemberElement<iso::CREAL, _altova_mi_altova_CImagingPhysicalEntityCharacteristic_altova_annotatorConfidence> annotatorConfidence;
	struct annotatorConfidence { typedef Iterator<iso::CREAL> iterator; };
	MemberElement<iso::CST, _altova_mi_altova_CImagingPhysicalEntityCharacteristic_altova_label> label;
	struct label { typedef Iterator<iso::CST> iterator; };
	MemberElement<iso::CINT, _altova_mi_altova_CImagingPhysicalEntityCharacteristic_altova_questionIndex> questionIndex;
	struct questionIndex { typedef Iterator<iso::CINT> iterator; };
	MemberElement<iso::CST, _altova_mi_altova_CImagingPhysicalEntityCharacteristic_altova_comment> comment;
	struct comment { typedef Iterator<iso::CST> iterator; };
	MemberElement<CcharacteristicQuantificationCollectionType2, _altova_mi_altova_CImagingPhysicalEntityCharacteristic_altova_characteristicQuantificationCollection> characteristicQuantificationCollection;
	struct characteristicQuantificationCollection { typedef Iterator<CcharacteristicQuantificationCollectionType2> iterator; };
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImagingPhysicalEntityCharacteristic
