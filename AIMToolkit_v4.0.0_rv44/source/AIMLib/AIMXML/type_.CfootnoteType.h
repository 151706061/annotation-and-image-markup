/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CfootnoteType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CfootnoteType



namespace AIMXML
{

class CfootnoteType : public TypeBase
{
public:
	AIMXML_EXPORT CfootnoteType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CfootnoteType(CfootnoteType const& init);
	void operator=(CfootnoteType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CfootnoteType); }
	AIMXML_EXPORT void operator=(const string_type& value);
	AIMXML_EXPORT operator string_type();

	MemberAttribute<string_type,_altova_mi_altova_CfootnoteType_altova_ID, 0, 0> ID;	// ID CID

	MemberAttribute<string_type,_altova_mi_altova_CfootnoteType_altova_language, 0, 0> language;	// language CNMTOKEN

	MemberAttribute<string_type,_altova_mi_altova_CfootnoteType_altova_styleCode, 0, 0> styleCode;	// styleCode CNMTOKENS
	MemberElement<CcontentType, _altova_mi_altova_CfootnoteType_altova_content> content;
	struct content { typedef Iterator<CcontentType> iterator; };
	MemberElement<ClinkHtmlType, _altova_mi_altova_CfootnoteType_altova_linkHtml> linkHtml;
	struct linkHtml { typedef Iterator<ClinkHtmlType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_CfootnoteType_altova_sub> sub;
	struct sub { typedef Iterator<xs::CstringType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_CfootnoteType_altova_sup> sup;
	struct sup { typedef Iterator<xs::CstringType> iterator; };
	MemberElement<CbrType, _altova_mi_altova_CfootnoteType_altova_br> br;
	struct br { typedef Iterator<CbrType> iterator; };
	MemberElement<CrenderMultiMediaType, _altova_mi_altova_CfootnoteType_altova_renderMultiMedia> renderMultiMedia;
	struct renderMultiMedia { typedef Iterator<CrenderMultiMediaType> iterator; };
	MemberElement<CparagraphType, _altova_mi_altova_CfootnoteType_altova_paragraph> paragraph;
	struct paragraph { typedef Iterator<CparagraphType> iterator; };
	MemberElement<ClistType, _altova_mi_altova_CfootnoteType_altova_list> list;
	struct list { typedef Iterator<ClistType> iterator; };
	MemberElement<CtableType, _altova_mi_altova_CfootnoteType_altova_table> table;
	struct table { typedef Iterator<CtableType> iterator; };
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CfootnoteType
