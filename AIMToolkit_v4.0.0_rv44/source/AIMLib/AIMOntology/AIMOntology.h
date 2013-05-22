/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _INCLUDED_AIMOntology_H_
#define _INCLUDED_AIMOntology_H_

#include "../Altova/xs-types.h"
#include "../AltovaXML/Node.h"
#include "AIMOntology-typeinfo.h"

#define AIMOntology_EXPORT	


namespace AIMOntology
{

	class TypeBase
	{
	protected:
		xercesc::DOMNode* m_node;
	public:
		TypeBase(xercesc::DOMNode* const& node) : m_node(node) {}
		xercesc::DOMNode* GetNode() const { return m_node; }

		AIMOntology_EXPORT xercesc::DOMNode* GetElementNth(const altova::MemberInfo* member, unsigned index);
		AIMOntology_EXPORT xercesc::DOMNode* GetElementLast(const altova::MemberInfo* member);
		AIMOntology_EXPORT unsigned CountElement(const altova::MemberInfo* member);
		AIMOntology_EXPORT void RemoveElement(const altova::MemberInfo* member);
	};

	template <typename MemberType, unsigned MemberIndex>
	class MemberAttribute
	{
		TypeBase& m_owner;
	public:
		typedef const MemberType& argument_type;
		typedef MemberType return_type;

		MemberAttribute(TypeBase& owner) : m_owner(owner) {}
		void operator=(argument_type value);
		operator return_type();
		bool exists();
		void remove();
		altova::meta::Attribute info() const { return altova::meta::Attribute(members + MemberIndex); }
	};

	template <typename MemberType>
	class CastAs 
	{
	public:
		static MemberType Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember);
	};

	template <>
	inline bool CastAs<bool>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToBool(node, pMember);
	}

	template <>
	inline double CastAs<double>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToDouble(node, pMember);
	}

	template <>
	inline int CastAs<int>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToInt(node, pMember);
	}

	template <>
	inline unsigned CastAs<unsigned>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToUInt(node, pMember);
	}

	template <>
	inline __int64 CastAs<__int64>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToInt64(node, pMember);
	}

	template <>
	inline unsigned __int64 CastAs<unsigned __int64>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToUInt64(node, pMember);
	}

	template <>
	inline string_type CastAs<string_type>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToString(node, pMember);
	}

	template <>
	inline std::vector<unsigned char> CastAs<std::vector<unsigned char> >::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToBinary(node, pMember);
	}

	template <>
	inline altova::DateTime CastAs<altova::DateTime>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToDateTime(node, pMember);
	}

	template <>
	inline altova::Duration CastAs<altova::Duration>::Do(xercesc::DOMNode* const& node, const altova::MemberInfo* pMember)
	{
		return XercesTreeOperations::CastToDuration(node, pMember);
	}

	template <typename DataType>
	class Iterator : public DataType
	{
		XercesTreeOperations::MemberIterator m_it;
	public:
		Iterator(const XercesTreeOperations::MemberIterator& it) : DataType(0), m_it(it) { if (m_it) this.m_node = *m_it; }
		bool operator++() { if (++m_it) { this.m_node = *m_it; return true; } return false; }
		operator bool() const { return m_it; }		

		DataType& operator*() { return *this; }
		DataType* operator->() { return this; }
	};

	template <typename MemberType, unsigned MemberIndex>
	class MemberElement
	{
		TypeBase& m_owner;
	public:
		MemberElement(TypeBase& owner) : m_owner(owner) {}
		MemberType operator[](unsigned index);
		MemberType first();
		MemberType last();
		MemberType append();
		bool exists();
		unsigned count();
		void remove();
		void remove(unsigned index);
		altova::meta::Element info() const { return altova::meta::Element(members + MemberIndex); }

		Iterator<MemberType> all() { return XercesTreeOperations::GetElements(m_owner.GetNode(), members + MemberIndex); }
	};

	template <typename MemberType, unsigned MemberIndex>
	void MemberAttribute<MemberType, MemberIndex>::operator=(argument_type value)
	{
		XercesTreeOperations::SetValue(m_owner.GetNode(), members + MemberIndex, value);
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberAttribute<MemberType, MemberIndex>::operator typename MemberAttribute<MemberType, MemberIndex>::return_type()
	{
		xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
		if (!XercesTreeOperations::IsValid(att))
			throw altova::InvalidOperationException(_T("Cannot read value of non-existent attribute."));
		return CastAs<MemberType>::Do(att, members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	bool MemberAttribute<MemberType, MemberIndex>::exists()
	{
		xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
		return XercesTreeOperations::IsValid(att);
	}

	template <typename MemberType, unsigned MemberIndex>
	void MemberAttribute<MemberType, MemberIndex>::remove()
	{
		XercesTreeOperations::RemoveAttribute(m_owner.GetNode(), members + MemberIndex);
	}



	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::operator[](unsigned index)
	{
		return m_owner.GetElementNth(members + MemberIndex, index);
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::first()
	{
		return m_owner.GetElementNth(members + MemberIndex, 0);
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::last()
	{
		return m_owner.GetElementLast(members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	MemberType MemberElement<MemberType, MemberIndex>::append()
	{
		return XercesTreeOperations::AddElement(m_owner.GetNode(), members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	bool MemberElement<MemberType, MemberIndex>::exists()
	{
		return m_owner.GetElementNth(members + MemberIndex, 0) != 0;
	}

	template <typename MemberType, unsigned MemberIndex>
	unsigned MemberElement<MemberType, MemberIndex>::count()
	{
		return m_owner.CountElement(members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	void MemberElement<MemberType, MemberIndex>::remove()
	{
		m_owner.RemoveElement(members + MemberIndex);
	}

	template <typename MemberType, unsigned MemberIndex>
	void MemberElement<MemberType, MemberIndex>::remove(unsigned index)
	{
		XercesTreeOperations::RemoveElement(m_owner.GetNode(), members + MemberIndex, index);
	}

}

namespace AIMOntology
{
// Namespace: http://www.radiology.northwestern.edu/aim/1/ontology/1 
// SchemaPrefix: aim

namespace aim
{	
class CAnatomicEntityXML;
class CAnnotationDescriptionXML;
class CImagingObservationCharacteristicXML;
class CImagingObservationXML;
class CAIMOntology;
class CrelatedAnatomicEntityXMLType;
class CanatomicEntityCollectionXMLType;
class CimagingObservationCollectionXMLType;
class CrelatedImagingObservationCharacteristicXMLType;
class CrelatedImagingObservationXMLType;
class CimagingObservationCharacteristicCollectionXMLType;

} // namespace aim

// Namespace: http://www.w3.org/2001/XMLSchema 
// SchemaPrefix: xs

namespace xs
{	
class CENTITIES;
class CENTITY;
class CID;
class CIDREF;
class CIDREFS;
class CNCName;
class CNMTOKEN;
class CNMTOKENS;
class CNOTATION;
class CName;
class CQName;
class CanySimpleType;
class CanyType;
class CanyURI;
class Cbase64Binary;
class Cboolean;
class Cbyte;
class Cdate;
class CdateTime;
class Cdecimal;
class Cdouble;
class Cduration;
class Cfloat;
class CgDay;
class CgMonth;
class CgMonthDay;
class CgYear;
class CgYearMonth;
class ChexBinary;
class Cint;
class Cinteger;
class Clanguage;
class Clong;
class CnegativeInteger;
class CnonNegativeInteger;
class CnonPositiveInteger;
class CnormalizedString;
class CpositiveInteger;
class Cshort;
class Cstring;
class Ctime;
class Ctoken;
class CunsignedByte;
class CunsignedInt;
class CunsignedLong;
class CunsignedShort;
class CstringType;

} // namespace xs


}

// include individual types

// namespace "http://www.radiology.northwestern.edu/aim/1/ontology/1"
#include "type_aim.CAnatomicEntityXML.h"
#include "type_aim.CAnnotationDescriptionXML.h"
#include "type_aim.CImagingObservationCharacteristicXML.h"
#include "type_aim.CImagingObservationXML.h"
#include "type_aim.CAIMOntology.h"
#include "type_aim.CrelatedAnatomicEntityXMLType.h"
#include "type_aim.CanatomicEntityCollectionXMLType.h"
#include "type_aim.CimagingObservationCollectionXMLType.h"
#include "type_aim.CrelatedImagingObservationCharacteristicXMLType.h"
#include "type_aim.CrelatedImagingObservationXMLType.h"
#include "type_aim.CimagingObservationCharacteristicCollectionXMLType.h"

// namespace "http://www.w3.org/2001/XMLSchema"
#include "type_xs.CENTITIES.h"
#include "type_xs.CENTITY.h"
#include "type_xs.CID.h"
#include "type_xs.CIDREF.h"
#include "type_xs.CIDREFS.h"
#include "type_xs.CNCName.h"
#include "type_xs.CNMTOKEN.h"
#include "type_xs.CNMTOKENS.h"
#include "type_xs.CNOTATION.h"
#include "type_xs.CName.h"
#include "type_xs.CQName.h"
#include "type_xs.CanySimpleType.h"
#include "type_xs.CanyType.h"
#include "type_xs.CanyURI.h"
#include "type_xs.Cbase64Binary.h"
#include "type_xs.Cboolean.h"
#include "type_xs.Cbyte.h"
#include "type_xs.Cdate.h"
#include "type_xs.CdateTime.h"
#include "type_xs.Cdecimal.h"
#include "type_xs.Cdouble.h"
#include "type_xs.Cduration.h"
#include "type_xs.Cfloat.h"
#include "type_xs.CgDay.h"
#include "type_xs.CgMonth.h"
#include "type_xs.CgMonthDay.h"
#include "type_xs.CgYear.h"
#include "type_xs.CgYearMonth.h"
#include "type_xs.ChexBinary.h"
#include "type_xs.Cint.h"
#include "type_xs.Cinteger.h"
#include "type_xs.Clanguage.h"
#include "type_xs.Clong.h"
#include "type_xs.CnegativeInteger.h"
#include "type_xs.CnonNegativeInteger.h"
#include "type_xs.CnonPositiveInteger.h"
#include "type_xs.CnormalizedString.h"
#include "type_xs.CpositiveInteger.h"
#include "type_xs.Cshort.h"
#include "type_xs.Cstring.h"
#include "type_xs.Ctime.h"
#include "type_xs.Ctoken.h"
#include "type_xs.CunsignedByte.h"
#include "type_xs.CunsignedInt.h"
#include "type_xs.CunsignedLong.h"
#include "type_xs.CunsignedShort.h"
#include "type_xs.CstringType.h"

// finished

#endif //_INCLUDED_AIMOntology_H_
