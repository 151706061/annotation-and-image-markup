//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AIMTCGAService
{
    public class AnnotationOfAnnotation
    {
        static public CQLQueryResults getAnnotationOfAnnotationInfo()
        {
            object[] obj;

            AIMTCGADataServicePortTypeClient proxy = new AIMTCGADataServicePortTypeClient();

            string[] items = new string[] { "codeValue", "codeMeaning", "codingSchemeDesignator", "codingSchemeVersion", "annotatorConfidence" };
            ItemsChoiceType[] itemsChoiceType1 = new ItemsChoiceType[] {
                ItemsChoiceType.AttributeNames, ItemsChoiceType.AttributeNames, ItemsChoiceType.AttributeNames, 
                ItemsChoiceType.AttributeNames, ItemsChoiceType.AttributeNames };


            // Anatomic Entity
            obj = null;
            Attribute attrCodeValue = null;
            Attribute attrCodeMeaning = null;
            Attribute attrCodingSchemeDesignator = null;
            Attribute attrCodingSchemeVersion = null;
            Attribute attrAnnotatorConfidence = null;


            return null;
        }
    }
}
