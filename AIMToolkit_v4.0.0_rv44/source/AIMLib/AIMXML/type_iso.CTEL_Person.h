/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CTEL_Person
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CTEL_Person



namespace AIMXML
{

namespace iso
{	

class CTEL_Person : public TypeBase
{
public:
	AIMXML_EXPORT CTEL_Person(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CTEL_Person(CTEL_Person const& init);
	void operator=(CTEL_Person const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CTEL_Person); }

	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_validTimeLow, 0, 0> validTimeLow;	// validTimeLow Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_validTimeHigh, 0, 0> validTimeHigh;	// validTimeHigh Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_controlActRoot, 0, 0> controlActRoot;	// controlActRoot CUid

	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_controlActExtension, 0, 0> controlActExtension;	// controlActExtension Cstring
	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_nullFlavor, 0, 15> nullFlavor;	// nullFlavor CNullFlavor

	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_flavorId, 0, 0> flavorId;	// flavorId Cstring
	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_updateMode, 0, 8> updateMode;	// updateMode CUpdateMode

	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_value2, 0, 0> value2;	// value CanyURI
	MemberAttribute<string_type,_altova_mi_iso_altova_CTEL_Person_altova_use, 1, 12> use;	// use Cset_TelecommunicationAddressUse
	MemberElement<iso::CQSET_TS, _altova_mi_iso_altova_CTEL_Person_altova_useablePeriod> useablePeriod;
	struct useablePeriod { typedef Iterator<iso::CQSET_TS> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CTEL_Person
