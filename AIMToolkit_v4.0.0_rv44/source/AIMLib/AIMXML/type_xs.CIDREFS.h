/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_xs_ALTOVA_CIDREFS
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_xs_ALTOVA_CIDREFS



namespace AIMXML
{

namespace xs
{	

class CIDREFS : public TypeBase
{
public:
	AIMXML_EXPORT CIDREFS(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CIDREFS(CIDREFS const& init);
	void operator=(CIDREFS const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_xs_altova_CIDREFS); }
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



} // namespace xs

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_xs_ALTOVA_CIDREFS
