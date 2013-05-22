//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using System.Xml.Serialization;

namespace AIM.Annotation.Template
{
	[XmlTypeAttribute(Namespace = TemplateContainer.Namespace)]
	public enum PrecedingAnnotationRequest
	{
		OfferToSelect,
		RequireToSelect,
		DoNotOffer
	}
}
