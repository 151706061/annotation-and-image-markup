/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CPostalAddressUse
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CPostalAddressUse



namespace AIMXML
{

namespace iso
{	

class CPostalAddressUse : public TypeBase
{
public:
	AIMXML_EXPORT CPostalAddressUse(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CPostalAddressUse(CPostalAddressUse const& init);
	void operator=(CPostalAddressUse const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_iso_altova_CPostalAddressUse); }

	enum EnumValues {
		Invalid = -1,
		k_H = 0, // H
		k_HP = 1, // HP
		k_HV = 2, // HV
		k_WP = 3, // WP
		k_DIR = 4, // DIR
		k_PUB = 5, // PUB
		k_BAD = 6, // BAD
		k_TMP = 7, // TMP
		k_ABC = 8, // ABC
		k_IDE = 9, // IDE
		k_SYL = 10, // SYL
		k_PHYS = 11, // PHYS
		k_PST = 12, // PST
		k_SNDX = 13, // SNDX
		k_PHON = 14, // PHON
		EnumValueCount
	};
	void operator= (const string_type& value) 
	{
		altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::AnySimpleTypeFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator string_type()
	{
		return CastAs<string_type >::Do(GetNode(), 0);
	}
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CPostalAddressUse
