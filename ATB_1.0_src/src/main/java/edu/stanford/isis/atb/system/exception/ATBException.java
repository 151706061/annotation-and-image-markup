/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.system.exception;

import edu.stanford.isis.atb.ui.Const;

/**
 * General exception.
 * 
 * @author Vitaliy Semeshko
 */
public class ATBException extends RuntimeException {

	public ATBException(String message) {
		super(message);
	}

	public ATBException(String message, Throwable cause) {
		super(message, cause);
	}

	public ATBException(Throwable cause) {
		super(Const.EMPTY, cause);
	}

	public boolean isCritical() {
		return true;
	}
	
}
