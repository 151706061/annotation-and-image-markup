/*
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.view.template.impl;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dialog.ModalityType;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Collection;

import javax.swing.Icon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import edu.stanford.isis.atb.domain.ats.TemplateSearchRequest;
import edu.stanford.isis.atb.domain.ats.TemplateSingleResult;
import edu.stanford.isis.atb.service.Command;
import edu.stanford.isis.atb.ui.Application;
import edu.stanford.isis.atb.ui.Const;
import edu.stanford.isis.atb.ui.util.UIUtil;
import edu.stanford.isis.atb.ui.view.AbstractView;
import edu.stanford.isis.atb.ui.view.resources.MiscImageBundle;
import edu.stanford.isis.atb.ui.view.template.TemplateSearchView;
import edu.stanford.isis.atb.ui.view.widget.EscapeDialog;
import edu.stanford.isis.atb.ui.view.widget.table.GenericTable;
import edu.stanford.isis.atb.ui.view.widget.table.column.CommandColumn;
import edu.stanford.isis.atb.ui.view.widget.table.column.CommandColumn.CommandColumnValue;
import edu.stanford.isis.atb.ui.view.widget.table.column.TextColumn.TextColumnValue;

/**
 * @author Vitaliy Semeshko
 */
public class TemplateSearchViewImpl extends AbstractView implements TemplateSearchView {

	private JPanel root = new JPanel(new BorderLayout());
	
	private EscapeDialog dialog = new EscapeDialog();
	
	private GenericTable<TemplateSingleResult> resultTable = new GenericTable<TemplateSingleResult>();

	private MiscImageBundle miscImages = MiscImageBundle.getInstance(); 
	
	private JButton searchButton = new JButton(Const.BTN_SEARCH, miscImages.getButtonSubmitIcon().loadIcon());

	private Command selectCommand;
	
	private JTextField nameText = new JTextField();
	private JTextField codeDescText = new JTextField();
	private JTextField descriptionText = new JTextField();
	private JTextField authorText = new JTextField();
	private JTextField diseaseText = new JTextField();
	private JTextField bodyPartText = new JTextField();
	private JComboBox modalityComboBox;
	
	public TemplateSearchViewImpl() {
		dialog.add(root);
		dialog.setSize(1000, 600);
		dialog.setMinimumSize(new Dimension(800, 400));
		dialog.setModalityType(ModalityType.APPLICATION_MODAL);
		initForm();
		initResultTable();
	}

	private void initForm() {
		JPanel search = new JPanel(new BorderLayout());
		JPanel form = new JPanel();
		JPanel buttons = new JPanel();
		
		form.add(initLeftForm(), BorderLayout.WEST);
		form.add(initRightForm(), BorderLayout.EAST);
		
		search.add(form, BorderLayout.CENTER);
		search.add(buttons, BorderLayout.SOUTH);
		
		JButton resetButton = new JButton(Const.BTN_RESET, miscImages.getButtonResetIcon().loadIcon());
		
		resetButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				clear();
			}
		});
		
		JButton cancelButton = new JButton(Const.BTN_CANCEL, miscImages.getButtonCancelIcon().loadIcon());
		
		cancelButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dialog.setVisible(false);
			}
		});
		
		buttons.add(searchButton);
		buttons.add(resetButton);
		buttons.add(cancelButton);
		
		root.add(search, BorderLayout.NORTH);
	}
	
	private JPanel initLeftForm() {
		JPanel form = new JPanel(UIUtil.createFormLayout(4));
		
		GridBagConstraints gbcLabelTemplateName = new GridBagConstraints();
		gbcLabelTemplateName.insets = new Insets(10, 10, 5, 8);
		gbcLabelTemplateName.anchor = GridBagConstraints.EAST;
		gbcLabelTemplateName.gridx = 0;
		gbcLabelTemplateName.gridy = 0;
		form.add(label(Const.FRM_LBL_TEMPLATE_NAME), gbcLabelTemplateName);
		
		GridBagConstraints gbcTextTemplateName = new GridBagConstraints();
		gbcTextTemplateName.insets = new Insets(10, 0, 5, 10);
		gbcTextTemplateName.fill = GridBagConstraints.HORIZONTAL;
		gbcTextTemplateName.gridx = 1;
		gbcTextTemplateName.gridy = 0;
		form.add(nameText, gbcTextTemplateName);
		nameText.setColumns(20);
		
		GridBagConstraints gbcLabelCodeDesc = new GridBagConstraints();
		gbcLabelCodeDesc.anchor = GridBagConstraints.EAST;
		gbcLabelCodeDesc.insets = new Insets(0, 10, 5, 8);
		gbcLabelCodeDesc.gridx = 0;
		gbcLabelCodeDesc.gridy = 1;
		form.add(label(Const.FRM_LBL_TEMPLATE_CODE_DESC), gbcLabelCodeDesc);
		
		GridBagConstraints gbcTextCodeDesc = new GridBagConstraints();
		gbcTextCodeDesc.insets = new Insets(0, 0, 5, 10);
		gbcTextCodeDesc.fill = GridBagConstraints.HORIZONTAL;
		gbcTextCodeDesc.gridx = 1;
		gbcTextCodeDesc.gridy = 1;
		form.add(codeDescText, gbcTextCodeDesc);
		codeDescText.setColumns(20);
		
		GridBagConstraints gbcLabelDescription = new GridBagConstraints();
		gbcLabelDescription.insets = new Insets(0, 10, 5, 8);
		gbcLabelDescription.anchor = GridBagConstraints.EAST;
		gbcLabelDescription.gridx = 0;
		gbcLabelDescription.gridy = 2;
		form.add(label(Const.FRM_LBL_TEMPLATE_DESCRIPTION), gbcLabelDescription);
		
		GridBagConstraints gbcTextDescription = new GridBagConstraints();
		gbcTextDescription.insets = new Insets(0, 0, 5, 10);
		gbcTextDescription.fill = GridBagConstraints.HORIZONTAL;
		gbcTextDescription.gridx = 1;
		gbcTextDescription.gridy = 2;
		form.add(descriptionText, gbcTextDescription);
		descriptionText.setColumns(20);
		
		GridBagConstraints gbcLabelAuthor = new GridBagConstraints();
		gbcLabelAuthor.anchor = GridBagConstraints.EAST;
		gbcLabelAuthor.insets = new Insets(0, 10, 0, 8);
		gbcLabelAuthor.gridx = 0;
		gbcLabelAuthor.gridy = 3;
		form.add(label(Const.FRM_LBL_TEMPLATE_AUTHOR), gbcLabelAuthor);
		
		GridBagConstraints gbcTextAuthor = new GridBagConstraints();
		gbcTextAuthor.insets = new Insets(0, 0, 5, 10);
		gbcTextAuthor.fill = GridBagConstraints.HORIZONTAL;
		gbcTextAuthor.gridx = 1;
		gbcTextAuthor.gridy = 3;
		form.add(authorText, gbcTextAuthor);
		authorText.setColumns(20);
		
		form.setBorder(new EmptyBorder(new Insets(0, 0, 0, 10)));
		return form;
	}
	
	private JPanel initRightForm() {
		JPanel form = new JPanel(UIUtil.createFormLayout(4));
		
		GridBagConstraints gbcLabelDisease = new GridBagConstraints();
		gbcLabelDisease.insets = new Insets(10, 10, 5, 8);
		gbcLabelDisease.anchor = GridBagConstraints.EAST;
		gbcLabelDisease.gridx = 0;
		gbcLabelDisease.gridy = 0;
		form.add(label(Const.FRM_LBL_DISEASE), gbcLabelDisease);
		
		GridBagConstraints gbcTextDisease = new GridBagConstraints();
		gbcTextDisease.insets = new Insets(10, 0, 5, 10);
		gbcTextDisease.fill = GridBagConstraints.HORIZONTAL;
		gbcTextDisease.gridx = 1;
		gbcTextDisease.gridy = 0;
		form.add(diseaseText, gbcTextDisease);
		diseaseText.setColumns(20);
		
		GridBagConstraints gbcLabelBodyPart = new GridBagConstraints();
		gbcLabelBodyPart.anchor = GridBagConstraints.EAST;
		gbcLabelBodyPart.insets = new Insets(0, 10, 5, 8);
		gbcLabelBodyPart.gridx = 0;
		gbcLabelBodyPart.gridy = 1;
		form.add(label(Const.FRM_LBL_BODY_PART), gbcLabelBodyPart);
		
		GridBagConstraints gbcTextBodyPart = new GridBagConstraints();
		gbcTextBodyPart.insets = new Insets(0, 0, 5, 10);
		gbcTextBodyPart.fill = GridBagConstraints.HORIZONTAL;
		gbcTextBodyPart.gridx = 1;
		gbcTextBodyPart.gridy = 1;
		form.add(bodyPartText, gbcTextBodyPart);
		bodyPartText.setColumns(20);
		
		GridBagConstraints gbcLabelModality = new GridBagConstraints();
		gbcLabelModality.insets = new Insets(0, 10, 5, 8);
		gbcLabelModality.anchor = GridBagConstraints.EAST;
		gbcLabelModality.gridx = 0;
		gbcLabelModality.gridy = 2;
		form.add(label(Const.FRM_LBL_MODALITY), gbcLabelModality);
		
		GridBagConstraints gbcTextModality = new GridBagConstraints();
		gbcTextModality.insets = new Insets(0, 0, 5, 10);
		gbcTextModality.fill = GridBagConstraints.HORIZONTAL;
		gbcTextModality.gridx = 1;
		gbcTextModality.gridy = 2;
		form.add(modalityComboBox = new JComboBox(getModalities()), gbcTextModality);
		//modalityText.setColumns(20);
		
		GridBagConstraints gbcPlaceholder = new GridBagConstraints();
		gbcPlaceholder.insets = new Insets(0, 10, 5, 8);
		gbcPlaceholder.anchor = GridBagConstraints.EAST;
		gbcPlaceholder.gridx = 0;
		gbcPlaceholder.gridy = 3;
		form.add(new JPanel(), gbcPlaceholder);
		
		form.setBorder(new EmptyBorder(new Insets(0, 10, 0, 0)));
		return form;
	}
	
	private Object[] getModalities() {
		Object[] values = edu.stanford.isis.atb.domain.template.ModalityType.values();
		Object[] valuesWithEmptyOption = new Object[values.length + 1];
		valuesWithEmptyOption[0] = Const.EMPTY;
		for (int i = 1; i < valuesWithEmptyOption.length; i++) {
			valuesWithEmptyOption[i] = values[i-1];
		}
		return valuesWithEmptyOption;
	}
	
	private JLabel label(String text) {
		return new JLabel(String.format(Const.TPL_FORM_LABEL, text));
	}
	
	private void initResultTable() {
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBorder(null);
		root.add(scrollPane, BorderLayout.CENTER);
		scrollPane.setViewportView(resultTable);
		scrollPane.getViewport().setBackground(Color.white);
		
		CommandColumn<TemplateSingleResult> dc = 
				new CommandColumn<TemplateSingleResult>(new CommandColumnValue<TemplateSingleResult>() {
			@Override
			public String getValue(TemplateSingleResult source) {
				return source.getName();
			}

			@Override
			public Command getCommand() {
				return selectCommand;
			}

			@Override
			public Icon getIcon() {
				return miscImages.getDownloadIcon().loadIcon();
			}
			
		}, Const.COLUMN_NAME, 120);
		
		resultTable.addGenericColumn(dc, true);
		
		resultTable.addTextColumn(new TextColumnValue<TemplateSingleResult>() {
			@Override
			public String getValue(TemplateSingleResult source) {
				return source.getAuthor();
			}
		}, Const.COLUMN_AUTHORS, 100, false);
		
		resultTable.addTextColumn(new TextColumnValue<TemplateSingleResult>() {
			@Override
			public String getValue(TemplateSingleResult source) {
				return source.getDesc();
			}
		}, Const.COLUMN_DESCRIPTION, 200, false);
		
		resultTable.addTextColumn(new TextColumnValue<TemplateSingleResult>() {
			@Override
			public String getValue(TemplateSingleResult source) {
				return source.getDisease();
			}
		}, Const.COLUMN_DISEASE, 180, false);
		
		resultTable.addTextColumn(new TextColumnValue<TemplateSingleResult>() {
			@Override
			public String getValue(TemplateSingleResult source) {
				return source.getBodyPart();
			}
		}, Const.COLUMN_BODY_PART, 80, false);
		
		resultTable.addTextColumn(new TextColumnValue<TemplateSingleResult>() {
			@Override
			public String getValue(TemplateSingleResult source) {
				return source.getModality();
			}
		}, Const.COLUMN_MODALITY, 60, false);
		
		resultTable.addTextColumn(new TextColumnValue<TemplateSingleResult>() {
			@Override
			public String getValue(TemplateSingleResult source) {
				return source.getUid();
			}
		}, Const.COLUMN_UID, 120, false);
	}

	@Override
	public void setTemplates(Collection<TemplateSingleResult> templates) {
		resultTable.setValues(templates);
	}

	@Override
	public TemplateSingleResult getSelectedTemplate() {
		return resultTable.getSelectedValue();
	}

	@Override
	public TemplateSearchRequest getTemplateSearchRequest() {
		TemplateSearchRequest request = new TemplateSearchRequest();
		request.setAuthor(authorText.getText());
		request.setBodyPart(bodyPartText.getText());
		request.setCodeDesc(codeDescText.getText());
		request.setDescription(descriptionText.getText());
		request.setDisease(diseaseText.getText());
		
		Object modality = modalityComboBox.getSelectedItem();
		if (modality != null && modality instanceof edu.stanford.isis.atb.domain.template.ModalityType) {
			request.setModality(((edu.stanford.isis.atb.domain.template.ModalityType) modality).toString());
		}
		
		if (modality != null) {
			
		}
		request.setName(nameText.getText());
		return request;
	}

	@Override
	public void clear() {
		resultTable.clear();
		nameText.setText(Const.EMPTY);
		codeDescText.setText(Const.EMPTY);
		descriptionText.setText(Const.EMPTY);
		authorText.setText(Const.EMPTY);
		diseaseText.setText(Const.EMPTY);
		bodyPartText.setText(Const.EMPTY);
		modalityComboBox.setSelectedIndex(0);
	}

	@Override
	public void setSearchCommand(final Command command) {
		searchButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				command.execute();
			}
		});
	}

	@Override
	public void setSelectCommand(Command command) {
		selectCommand = command;
	}

	@Override
	public void showAsDialog() {
		Rectangle outerBounds = Application.accessApplication().asComponent().getBounds();
		int x = outerBounds.x + (outerBounds.width - dialog.getSize().width) / 2;
		int y = outerBounds.y + (outerBounds.height - dialog.getSize().height) / 2;
		dialog.setLocation(x, y);
		dialog.setVisible(true);
	}

	@Override
	public Component asComponent() {
		return root;
	}
	
}
