/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/


#ifndef _INCLUDED_AIMOntology_typeinfo_H_
#define _INCLUDED_AIMOntology_typeinfo_H_

#include "../Altova/StructInfo.h"

#undef AIMOntology_DECLSPECIFIER
#define AIMOntology_DECLSPECIFIER


namespace AIMOntology
{

enum _altova_namespace_indices
{
	_altova_ni_aim,		
	_altova_ni_xs,		

};

enum _altova_typeinfo_indices
{
	_altova_tif_aim,
	_altova_ti_aim_altova_CAnatomicEntityXML = _altova_tif_aim,
	_altova_ti_aim_altova_CAnnotationDescriptionXML,
	_altova_ti_aim_altova_CImagingObservationCharacteristicXML,
	_altova_ti_aim_altova_CImagingObservationXML,
	_altova_ti_aim_altova_CAIMOntology,
	_altova_ti_aim_altova_CrelatedAnatomicEntityXMLType,
	_altova_ti_aim_altova_CanatomicEntityCollectionXMLType,
	_altova_ti_aim_altova_CimagingObservationCollectionXMLType,
	_altova_ti_aim_altova_CrelatedImagingObservationCharacteristicXMLType,
	_altova_ti_aim_altova_CrelatedImagingObservationXMLType,
	_altova_ti_aim_altova_CimagingObservationCharacteristicCollectionXMLType,
	_altova_til_aim,

	_altova_tif_xs = _altova_til_aim,
	_altova_ti_xs_altova_CENTITIES = _altova_tif_xs,
	_altova_ti_xs_altova_CENTITY,
	_altova_ti_xs_altova_CID,
	_altova_ti_xs_altova_CIDREF,
	_altova_ti_xs_altova_CIDREFS,
	_altova_ti_xs_altova_CNCName,
	_altova_ti_xs_altova_CNMTOKEN,
	_altova_ti_xs_altova_CNMTOKENS,
	_altova_ti_xs_altova_CNOTATION,
	_altova_ti_xs_altova_CName,
	_altova_ti_xs_altova_CQName,
	_altova_ti_xs_altova_CanySimpleType,
	_altova_ti_xs_altova_CanyType,
	_altova_ti_xs_altova_CanyURI,
	_altova_ti_xs_altova_Cbase64Binary,
	_altova_ti_xs_altova_Cboolean,
	_altova_ti_xs_altova_Cbyte,
	_altova_ti_xs_altova_Cdate,
	_altova_ti_xs_altova_CdateTime,
	_altova_ti_xs_altova_Cdecimal,
	_altova_ti_xs_altova_Cdouble,
	_altova_ti_xs_altova_Cduration,
	_altova_ti_xs_altova_Cfloat,
	_altova_ti_xs_altova_CgDay,
	_altova_ti_xs_altova_CgMonth,
	_altova_ti_xs_altova_CgMonthDay,
	_altova_ti_xs_altova_CgYear,
	_altova_ti_xs_altova_CgYearMonth,
	_altova_ti_xs_altova_ChexBinary,
	_altova_ti_xs_altova_Cint,
	_altova_ti_xs_altova_Cinteger,
	_altova_ti_xs_altova_Clanguage,
	_altova_ti_xs_altova_Clong,
	_altova_ti_xs_altova_CnegativeInteger,
	_altova_ti_xs_altova_CnonNegativeInteger,
	_altova_ti_xs_altova_CnonPositiveInteger,
	_altova_ti_xs_altova_CnormalizedString,
	_altova_ti_xs_altova_CpositiveInteger,
	_altova_ti_xs_altova_Cshort,
	_altova_ti_xs_altova_Cstring,
	_altova_ti_xs_altova_Ctime,
	_altova_ti_xs_altova_Ctoken,
	_altova_ti_xs_altova_CunsignedByte,
	_altova_ti_xs_altova_CunsignedInt,
	_altova_ti_xs_altova_CunsignedLong,
	_altova_ti_xs_altova_CunsignedShort,
	_altova_ti_xs_altova_CstringType,
	_altova_til_xs,


};

enum
{
	_altova_mif_aim_altova_CAnatomicEntityXML,
	_altova_mi_aim_altova_CAnatomicEntityXML_altova_codeMeaning = _altova_mif_aim_altova_CAnatomicEntityXML,
	_altova_mi_aim_altova_CAnatomicEntityXML_altova_codingSchemeDesignator,
	_altova_mi_aim_altova_CAnatomicEntityXML_altova_codeValue,
	_altova_mi_aim_altova_CAnatomicEntityXML_altova_relationship,
	_altova_mi_aim_altova_CAnatomicEntityXML_altova_relatedAnatomicEntityXML,
	_altova_mil_aim_altova_CAnatomicEntityXML,
};
enum
{
	_altova_mif_aim_altova_CAnnotationDescriptionXML = _altova_mil_aim_altova_CAnatomicEntityXML,
	_altova_mi_aim_altova_CAnnotationDescriptionXML_altova_anatomicEntityCollectionXML = _altova_mif_aim_altova_CAnnotationDescriptionXML,
	_altova_mi_aim_altova_CAnnotationDescriptionXML_altova_imagingObservationCollectionXML,
	_altova_mil_aim_altova_CAnnotationDescriptionXML,
};
enum
{
	_altova_mif_aim_altova_CImagingObservationCharacteristicXML = _altova_mil_aim_altova_CAnnotationDescriptionXML,
	_altova_mi_aim_altova_CImagingObservationCharacteristicXML_altova_codeMeaning = _altova_mif_aim_altova_CImagingObservationCharacteristicXML,
	_altova_mi_aim_altova_CImagingObservationCharacteristicXML_altova_codingSchemeDesignator,
	_altova_mi_aim_altova_CImagingObservationCharacteristicXML_altova_codeValue,
	_altova_mi_aim_altova_CImagingObservationCharacteristicXML_altova_comment,
	_altova_mi_aim_altova_CImagingObservationCharacteristicXML_altova_relationship,
	_altova_mi_aim_altova_CImagingObservationCharacteristicXML_altova_relatedImagingObservationCharacteristicXML,
	_altova_mil_aim_altova_CImagingObservationCharacteristicXML,
};
enum
{
	_altova_mif_aim_altova_CImagingObservationXML = _altova_mil_aim_altova_CImagingObservationCharacteristicXML,
	_altova_mi_aim_altova_CImagingObservationXML_altova_codeMeaning = _altova_mif_aim_altova_CImagingObservationXML,
	_altova_mi_aim_altova_CImagingObservationXML_altova_codingSchemeDesignator,
	_altova_mi_aim_altova_CImagingObservationXML_altova_codeValue,
	_altova_mi_aim_altova_CImagingObservationXML_altova_comment,
	_altova_mi_aim_altova_CImagingObservationXML_altova_relationship,
	_altova_mi_aim_altova_CImagingObservationXML_altova_relatedImagingObservationXML,
	_altova_mi_aim_altova_CImagingObservationXML_altova_imagingObservationCharacteristicCollectionXML,
	_altova_mil_aim_altova_CImagingObservationXML,
};
enum
{
	_altova_mif_aim_altova_CAIMOntology = _altova_mil_aim_altova_CImagingObservationXML,
	_altova_mi_aim_altova_CAIMOntology_altova_AnnotationDescriptionXML = _altova_mif_aim_altova_CAIMOntology,
	_altova_mil_aim_altova_CAIMOntology,
};
enum
{
	_altova_mif_aim_altova_CrelatedAnatomicEntityXMLType = _altova_mil_aim_altova_CAIMOntology,
	_altova_mi_aim_altova_CrelatedAnatomicEntityXMLType_altova_AnatomicEntityXML = _altova_mif_aim_altova_CrelatedAnatomicEntityXMLType,
	_altova_mil_aim_altova_CrelatedAnatomicEntityXMLType,
};
enum
{
	_altova_mif_aim_altova_CanatomicEntityCollectionXMLType = _altova_mil_aim_altova_CrelatedAnatomicEntityXMLType,
	_altova_mi_aim_altova_CanatomicEntityCollectionXMLType_altova_AnatomicEntityXML = _altova_mif_aim_altova_CanatomicEntityCollectionXMLType,
	_altova_mil_aim_altova_CanatomicEntityCollectionXMLType,
};
enum
{
	_altova_mif_aim_altova_CimagingObservationCollectionXMLType = _altova_mil_aim_altova_CanatomicEntityCollectionXMLType,
	_altova_mi_aim_altova_CimagingObservationCollectionXMLType_altova_ImagingObservationXML = _altova_mif_aim_altova_CimagingObservationCollectionXMLType,
	_altova_mil_aim_altova_CimagingObservationCollectionXMLType,
};
enum
{
	_altova_mif_aim_altova_CrelatedImagingObservationCharacteristicXMLType = _altova_mil_aim_altova_CimagingObservationCollectionXMLType,
	_altova_mi_aim_altova_CrelatedImagingObservationCharacteristicXMLType_altova_ImagingObservationCharacteristicXML = _altova_mif_aim_altova_CrelatedImagingObservationCharacteristicXMLType,
	_altova_mil_aim_altova_CrelatedImagingObservationCharacteristicXMLType,
};
enum
{
	_altova_mif_aim_altova_CrelatedImagingObservationXMLType = _altova_mil_aim_altova_CrelatedImagingObservationCharacteristicXMLType,
	_altova_mi_aim_altova_CrelatedImagingObservationXMLType_altova_ImagingObservationXML = _altova_mif_aim_altova_CrelatedImagingObservationXMLType,
	_altova_mil_aim_altova_CrelatedImagingObservationXMLType,
};
enum
{
	_altova_mif_aim_altova_CimagingObservationCharacteristicCollectionXMLType = _altova_mil_aim_altova_CrelatedImagingObservationXMLType,
	_altova_mi_aim_altova_CimagingObservationCharacteristicCollectionXMLType_altova_ImagingObservationCharacteristicXML = _altova_mif_aim_altova_CimagingObservationCharacteristicCollectionXMLType,
	_altova_mil_aim_altova_CimagingObservationCharacteristicCollectionXMLType,
};
enum
{
	_altova_mif_xs_altova_CENTITIES = _altova_mil_aim_altova_CimagingObservationCharacteristicCollectionXMLType,
	_altova_mil_xs_altova_CENTITIES = _altova_mif_xs_altova_CENTITIES,
};
enum
{
	_altova_mif_xs_altova_CENTITY = _altova_mil_xs_altova_CENTITIES,
	_altova_mil_xs_altova_CENTITY = _altova_mif_xs_altova_CENTITY,
};
enum
{
	_altova_mif_xs_altova_CID = _altova_mil_xs_altova_CENTITY,
	_altova_mil_xs_altova_CID = _altova_mif_xs_altova_CID,
};
enum
{
	_altova_mif_xs_altova_CIDREF = _altova_mil_xs_altova_CID,
	_altova_mil_xs_altova_CIDREF = _altova_mif_xs_altova_CIDREF,
};
enum
{
	_altova_mif_xs_altova_CIDREFS = _altova_mil_xs_altova_CIDREF,
	_altova_mil_xs_altova_CIDREFS = _altova_mif_xs_altova_CIDREFS,
};
enum
{
	_altova_mif_xs_altova_CNCName = _altova_mil_xs_altova_CIDREFS,
	_altova_mil_xs_altova_CNCName = _altova_mif_xs_altova_CNCName,
};
enum
{
	_altova_mif_xs_altova_CNMTOKEN = _altova_mil_xs_altova_CNCName,
	_altova_mil_xs_altova_CNMTOKEN = _altova_mif_xs_altova_CNMTOKEN,
};
enum
{
	_altova_mif_xs_altova_CNMTOKENS = _altova_mil_xs_altova_CNMTOKEN,
	_altova_mil_xs_altova_CNMTOKENS = _altova_mif_xs_altova_CNMTOKENS,
};
enum
{
	_altova_mif_xs_altova_CNOTATION = _altova_mil_xs_altova_CNMTOKENS,
	_altova_mil_xs_altova_CNOTATION = _altova_mif_xs_altova_CNOTATION,
};
enum
{
	_altova_mif_xs_altova_CName = _altova_mil_xs_altova_CNOTATION,
	_altova_mil_xs_altova_CName = _altova_mif_xs_altova_CName,
};
enum
{
	_altova_mif_xs_altova_CQName = _altova_mil_xs_altova_CName,
	_altova_mil_xs_altova_CQName = _altova_mif_xs_altova_CQName,
};
enum
{
	_altova_mif_xs_altova_CanySimpleType = _altova_mil_xs_altova_CQName,
	_altova_mil_xs_altova_CanySimpleType = _altova_mif_xs_altova_CanySimpleType,
};
enum
{
	_altova_mif_xs_altova_CanyType = _altova_mil_xs_altova_CanySimpleType,
	_altova_mi_xs_altova_CanyType_altova_unnamed = _altova_mif_xs_altova_CanyType,
	_altova_mil_xs_altova_CanyType,
};
enum
{
	_altova_mif_xs_altova_CanyURI = _altova_mil_xs_altova_CanyType,
	_altova_mil_xs_altova_CanyURI = _altova_mif_xs_altova_CanyURI,
};
enum
{
	_altova_mif_xs_altova_Cbase64Binary = _altova_mil_xs_altova_CanyURI,
	_altova_mil_xs_altova_Cbase64Binary = _altova_mif_xs_altova_Cbase64Binary,
};
enum
{
	_altova_mif_xs_altova_Cboolean = _altova_mil_xs_altova_Cbase64Binary,
	_altova_mil_xs_altova_Cboolean = _altova_mif_xs_altova_Cboolean,
};
enum
{
	_altova_mif_xs_altova_Cbyte = _altova_mil_xs_altova_Cboolean,
	_altova_mil_xs_altova_Cbyte = _altova_mif_xs_altova_Cbyte,
};
enum
{
	_altova_mif_xs_altova_Cdate = _altova_mil_xs_altova_Cbyte,
	_altova_mil_xs_altova_Cdate = _altova_mif_xs_altova_Cdate,
};
enum
{
	_altova_mif_xs_altova_CdateTime = _altova_mil_xs_altova_Cdate,
	_altova_mil_xs_altova_CdateTime = _altova_mif_xs_altova_CdateTime,
};
enum
{
	_altova_mif_xs_altova_Cdecimal = _altova_mil_xs_altova_CdateTime,
	_altova_mil_xs_altova_Cdecimal = _altova_mif_xs_altova_Cdecimal,
};
enum
{
	_altova_mif_xs_altova_Cdouble = _altova_mil_xs_altova_Cdecimal,
	_altova_mil_xs_altova_Cdouble = _altova_mif_xs_altova_Cdouble,
};
enum
{
	_altova_mif_xs_altova_Cduration = _altova_mil_xs_altova_Cdouble,
	_altova_mil_xs_altova_Cduration = _altova_mif_xs_altova_Cduration,
};
enum
{
	_altova_mif_xs_altova_Cfloat = _altova_mil_xs_altova_Cduration,
	_altova_mil_xs_altova_Cfloat = _altova_mif_xs_altova_Cfloat,
};
enum
{
	_altova_mif_xs_altova_CgDay = _altova_mil_xs_altova_Cfloat,
	_altova_mil_xs_altova_CgDay = _altova_mif_xs_altova_CgDay,
};
enum
{
	_altova_mif_xs_altova_CgMonth = _altova_mil_xs_altova_CgDay,
	_altova_mil_xs_altova_CgMonth = _altova_mif_xs_altova_CgMonth,
};
enum
{
	_altova_mif_xs_altova_CgMonthDay = _altova_mil_xs_altova_CgMonth,
	_altova_mil_xs_altova_CgMonthDay = _altova_mif_xs_altova_CgMonthDay,
};
enum
{
	_altova_mif_xs_altova_CgYear = _altova_mil_xs_altova_CgMonthDay,
	_altova_mil_xs_altova_CgYear = _altova_mif_xs_altova_CgYear,
};
enum
{
	_altova_mif_xs_altova_CgYearMonth = _altova_mil_xs_altova_CgYear,
	_altova_mil_xs_altova_CgYearMonth = _altova_mif_xs_altova_CgYearMonth,
};
enum
{
	_altova_mif_xs_altova_ChexBinary = _altova_mil_xs_altova_CgYearMonth,
	_altova_mil_xs_altova_ChexBinary = _altova_mif_xs_altova_ChexBinary,
};
enum
{
	_altova_mif_xs_altova_Cint = _altova_mil_xs_altova_ChexBinary,
	_altova_mil_xs_altova_Cint = _altova_mif_xs_altova_Cint,
};
enum
{
	_altova_mif_xs_altova_Cinteger = _altova_mil_xs_altova_Cint,
	_altova_mil_xs_altova_Cinteger = _altova_mif_xs_altova_Cinteger,
};
enum
{
	_altova_mif_xs_altova_Clanguage = _altova_mil_xs_altova_Cinteger,
	_altova_mil_xs_altova_Clanguage = _altova_mif_xs_altova_Clanguage,
};
enum
{
	_altova_mif_xs_altova_Clong = _altova_mil_xs_altova_Clanguage,
	_altova_mil_xs_altova_Clong = _altova_mif_xs_altova_Clong,
};
enum
{
	_altova_mif_xs_altova_CnegativeInteger = _altova_mil_xs_altova_Clong,
	_altova_mil_xs_altova_CnegativeInteger = _altova_mif_xs_altova_CnegativeInteger,
};
enum
{
	_altova_mif_xs_altova_CnonNegativeInteger = _altova_mil_xs_altova_CnegativeInteger,
	_altova_mil_xs_altova_CnonNegativeInteger = _altova_mif_xs_altova_CnonNegativeInteger,
};
enum
{
	_altova_mif_xs_altova_CnonPositiveInteger = _altova_mil_xs_altova_CnonNegativeInteger,
	_altova_mil_xs_altova_CnonPositiveInteger = _altova_mif_xs_altova_CnonPositiveInteger,
};
enum
{
	_altova_mif_xs_altova_CnormalizedString = _altova_mil_xs_altova_CnonPositiveInteger,
	_altova_mil_xs_altova_CnormalizedString = _altova_mif_xs_altova_CnormalizedString,
};
enum
{
	_altova_mif_xs_altova_CpositiveInteger = _altova_mil_xs_altova_CnormalizedString,
	_altova_mil_xs_altova_CpositiveInteger = _altova_mif_xs_altova_CpositiveInteger,
};
enum
{
	_altova_mif_xs_altova_Cshort = _altova_mil_xs_altova_CpositiveInteger,
	_altova_mil_xs_altova_Cshort = _altova_mif_xs_altova_Cshort,
};
enum
{
	_altova_mif_xs_altova_Cstring = _altova_mil_xs_altova_Cshort,
	_altova_mil_xs_altova_Cstring = _altova_mif_xs_altova_Cstring,
};
enum
{
	_altova_mif_xs_altova_Ctime = _altova_mil_xs_altova_Cstring,
	_altova_mil_xs_altova_Ctime = _altova_mif_xs_altova_Ctime,
};
enum
{
	_altova_mif_xs_altova_Ctoken = _altova_mil_xs_altova_Ctime,
	_altova_mil_xs_altova_Ctoken = _altova_mif_xs_altova_Ctoken,
};
enum
{
	_altova_mif_xs_altova_CunsignedByte = _altova_mil_xs_altova_Ctoken,
	_altova_mil_xs_altova_CunsignedByte = _altova_mif_xs_altova_CunsignedByte,
};
enum
{
	_altova_mif_xs_altova_CunsignedInt = _altova_mil_xs_altova_CunsignedByte,
	_altova_mil_xs_altova_CunsignedInt = _altova_mif_xs_altova_CunsignedInt,
};
enum
{
	_altova_mif_xs_altova_CunsignedLong = _altova_mil_xs_altova_CunsignedInt,
	_altova_mil_xs_altova_CunsignedLong = _altova_mif_xs_altova_CunsignedLong,
};
enum
{
	_altova_mif_xs_altova_CunsignedShort = _altova_mil_xs_altova_CunsignedLong,
	_altova_mil_xs_altova_CunsignedShort = _altova_mif_xs_altova_CunsignedShort,
};
enum
{
	_altova_mif_xs_altova_CstringType = _altova_mil_xs_altova_CunsignedShort,
	_altova_mi_xs_altova_CstringType_altova_unnamed = _altova_mif_xs_altova_CstringType,
	_altova_mil_xs_altova_CstringType,
};



extern AIMOntology_DECLSPECIFIER const altova::FacetInfo facets[];
extern AIMOntology_DECLSPECIFIER const altova::NamespaceInfo namespaces[];
extern AIMOntology_DECLSPECIFIER const altova::MemberInfo members[];
extern AIMOntology_DECLSPECIFIER const altova::TypeInfo types[];

}  // namespace AIMOntology

#endif // _INCLUDED_AIMOntology_typeinfo_H_
