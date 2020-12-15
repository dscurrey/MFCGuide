# MFC

- [MFC](#mfc)
  - [Overview](#overview)
  - [Creating a Dialog-Based Application](#creating-a-dialog-based-application)
  - [Basic Controls](#basic-controls)

## Overview

MFC encapsulates the Win32 API (Application Programming Interface), a C interface to Windows OS services. It provides C++ classes which speed up Win32 application development.

It does this by encapsulating some key features of Win32 development to make them simpler and easier to use, as well as by hiding some of the more low-level aspects of programming for Windows.

## Creating a Dialog-Based Application
The most simple method is to use the MFC wizard to generate the boilerplate code for the project.

First, create a new MFC project using the new project dialog in VS.

![](resources/img/CreateMFC1.png)

This opens the MFC Application Wizard, which will allow you to customise the MFC application it will help generate.

![](resources/img/CreateMFC2.png)

This page allows you to select the application type. In this case we are creating a dialog based application, so that option is selected. It is best to keep MFC as a shared DLL to help reduce file sizes.

![](resources/img/CreateMFC3.png)

Next, you can customise the UI's Main window. Options are limited here as the application is dialog based, and in this case the defaults are okay for our purposes.

![](resources/img/CreateMFC4.png)

This page allows you to change the advanced features added to the project. ActiveX controls are potentially noteworthy as they are now legacy technology and should be avoided for future development.

![](resources/img/CreateMFC5.png)

This final page will show you the generated classes and allow you to change the name before finishing. Clicking finish will close the wizard and generate the application, which will be created with a blank Dialog resource, containing a TODO message in a static text control.

![](resources/img/CreateMFC6.png)

From here, the dialog can be edited and your application can be written and created.

## Basic Controls
The above instructions creates a project with a blank dialog resource, seen here:

![](resources/img/BlankDlg.png)

This is the dialog editor view, and allows you to add, remove and change properties of controls and the dialog itself. This is done mainly using the toolbox and properties panes (see below).

![](resources/img/Toolbox.png)
![](resources/img/BlankDlgProperties.png)


