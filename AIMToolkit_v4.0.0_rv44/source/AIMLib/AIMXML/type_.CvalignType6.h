/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CvalignType6
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CvalignType6



namespace AIMXML
{

class CvalignType6 : public TypeBase
{
public:
	AIMXML_EXPORT CvalignType6(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CvalignType6(CvalignType6 const& init);
	void operator=(CvalignType6 const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_altova_CvalignType6); }

	enum EnumValues {
		Invalid = -1,
		k_top = 0, // top
		k_middle = 1, // middle
		k_bottom = 2, // bottom
		k_baseline = 3, // baseline
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


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CvalignType6
