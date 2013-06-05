/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.presenter;

import edu.stanford.isis.atb.ui.view.View;

/**
 * Abstract Presenter.
 * @param <V> View
 * 
 * @author Vitaliy Semeshko
 */
public abstract class AbstractPresenter<V extends View> implements Presenter<V> {

	protected V view;
	
	public AbstractPresenter(V view) {
		this.view = view;
	}
	
	@Override
	public V getView() {
		return view;
	}
	
}
