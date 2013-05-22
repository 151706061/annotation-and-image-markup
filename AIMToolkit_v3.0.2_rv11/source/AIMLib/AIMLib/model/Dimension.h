/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#if !defined(_AIMLib_DIMENSION_INCLUDED_)
#define _AIMLib_DIMENSION_INCLUDED_

#include <string>
#include <vector>

namespace aim_lib
{
	class AIMLIB_API Dimension
	{
	public:
		Dimension();
		Dimension(const Dimension& dimension);
		Dimension& operator=(const Dimension& dimension);
		virtual ~Dimension();

		int GetIndex() const;
		int GetSize() const;
		const std::string& GetLabel() const;

		void SetIndex(int newVal);
		void SetSize(int newVal);
		void SetLabel(const std::string& newVal);

	private:
		int _cagridId;
		int _index;
		int _size;
		std::string _label;
	};

	typedef std::vector<Dimension> DimensionVector;
}
#endif // !defined(_AIMLib_DIMENSION_INCLUDED_)
