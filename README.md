annotation-and-image-markup
===========================
AIM is the first project to propose and create a standard means of adding information and knowledge to an image in a clinical environment, so that image content can be easily and automatically searched. AIM provides a solution to the following imaging challenges:

    No agreed upon syntax for annotation and markup
    No agreed upon semantics to describe annotations
    No standard format (for example, DICOM, XML, HL7) for annotations and markup

The AIM project includes the following.

    The AIM Model captures the descriptive information for an image with user-generated graphical symbols placed on the image into a single common information source.
    The AIM Template Service is a web service application that makes it possible for you to upload (publish) and download AIM templates created using an AIM tool such as AIM Template Builder.
    The AIM Template Builder is a Java application that allows you to build templates that are compatible with the AIM Model. Templates are a set of well-defined questions and answer choices that facilitate collecting information for a study. The AIM Template Builder has replaced the AIM Template Manager.
    AIM on ClearCanvas Workstation is a reference implementation of the AIM Model. AIM on ClearCanvas Workstation demonstrates how the AIM model and the AIM library can be applied in a real imaging diagnostic workstation. You can use AIM on ClearCanvas Workstation to create AIM XML documents and AIM DICOM SR objects that adhere to the AIM data model. You can also import a new AIM template XML document that represents a set of controlled questions and answers for each question. Typical users want to make simple and constrained annotations that are reproducible and consistent for the same kind of imaging study.
