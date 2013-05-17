/*
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.view.template.form;

import edu.stanford.isis.atb.ui.Const;
import edu.stanford.isis.atb.ui.view.base.EditFormView;
import edu.stanford.isis.atb.ui.view.base.EditFormView.LabeledFormField;
import edu.stanford.isis.atb.ui.view.template.form.ImagingObservationFormView.ImagingObservationFormField;

/**
 * @author Vitaliy Semeshko
 */
public interface ImagingObservationFormView extends EditFormView<ImagingObservationFormField> {

	public enum ImagingObservationFormField implements LabeledFormField {
		ANNOTATOR_CONFIDENCE(Const.FRM_LBL_ANNOTATOR_CONFIDENCE);
		
		private String label;
		
		private ImagingObservationFormField(String label) {
			this.label = label;
		}
		
		@Override
		public String getLabel() {
			return label;
		}
		
	}
	
}
