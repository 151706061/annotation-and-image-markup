/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.presenter.lexicon.search;

import edu.stanford.isis.atb.ui.model.TermSearchItem;

/**
 * Implementors can accept single lexicon term selected in search dialog.
 * 
 * @author Vitaliy Semeshko
 */
public interface CanAcceptSingleTerm {

	public void accept(TermSearchItem searchItem);
	
}
