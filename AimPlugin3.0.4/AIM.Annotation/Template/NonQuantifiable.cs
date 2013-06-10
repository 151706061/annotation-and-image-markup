#region License

//L
// 2007 - 2013 Copyright Northwestern University
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
//L

#endregion

using System.Xml.Serialization;

namespace AIM.Annotation.Template
{
	public class NonQuantifiable
	{
		[XmlAttribute("codeValue")]
		public string CodeValue { get; set; }

		[XmlAttribute("codeMeaning")]
		public string CodeMeaning { get; set; }

		[XmlAttribute("codingSchemeDesignator")]
		public string CodingSchemeDesignator { get; set; }

		[XmlAttribute("codingSchemeVersion")]
		public string CodingSchemeVersion { get; set; }
	}
}
