//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using System;
using System.Collections.Generic;
using ClearCanvas.Common.Utilities;

namespace SearchComponent
{
	[Cloneable]
	public class RetrieveProgressResult
	{
		public RetrieveProgressResult() {}

		public readonly Guid Identifier;
		public RetrieveStatus Status = RetrieveStatus.Unknown;
		public string ProgressMessage;
		public readonly List<RetrieveQueryItem> QueryItems = new List<RetrieveQueryItem>();
	}

	public class RetrieveQueryItem
	{
		public RetrieveQueryItem() {}

		public Patient Patient = new Patient();
		public Study Study = new Study();
		public List<Series> Series = new List<Series>();
	}
}
