/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.presenter;

import edu.stanford.isis.atb.ui.view.View;

/**
 * Basic Presenter.
 * 
 * @author Vitaliy Semeshko
 */
public interface Presenter<V extends View> {

	public V getView();
	
	public void bindView();
	
}
