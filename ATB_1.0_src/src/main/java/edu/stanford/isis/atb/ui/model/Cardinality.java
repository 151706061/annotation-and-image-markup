/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.model;

/**
 * @author Vitaliy Semeshko
 */
public class Cardinality {

	private long min;
	
	private long max;

	public Cardinality(long min, long max) {
		this.min = min;
		this.max = max;
	}
	
	public long getMin() {
		return min;
	}

	public long getMax() {
		return max;
	}
	
}
