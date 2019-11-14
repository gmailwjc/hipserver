# README

## ![FCG](https://avatars0.githubusercontent.com/u/26013747?s=50&v=4) FieldComm Group

## hipserver

**hipserver** is one component of the [HART-IP Developer Kit](https://github.com/FieldCommGroup/HART-IP-Developer-Kit). It manages HART-IP connections with client programs and also with the companion [**hipflowapp** ](https://github.com/FieldCommGroup/hipflowapp)component, which implements the flow device functionality.

This component is common to the HART-IP server applications developed by FieldComm Group. It is the identical software used in the HART Test System and Wireless HART Test System. Future HART-IP server applications produced by FieldComm Group will also use this component.

## Known Issues

It does not pass HART-IP Test System test cases, as there is not a released test specification for HART-IP devices.  However, that specification is in development and the HART Test System will be enhanced to include these tests.

It does not check for malformed Token-Passing PDU’s \(planned\).

It supports UDP/IP, but does not yet support TCP/IP \(planned\).

The Pi computer is configured for DHCP.  You will want to configure it for a static address for any production use.

It does not implement security.  Security is not included in the HART-IP specification, but is currently being considered.  For now, security is the responsibility of the system integrator.

## User Guide

Pull the repository from the bash terminal with this command line:

```text
  git clone https://github.com/FieldCommGroup/hipserver
```

To launch the **hipserver**, the command line is:

```text
hipserver -v -h -p <num> <app command line>
```

where:

-v print version number and quit

-h print help text and quit

-p &lt;num&gt; specifies the port number to the app program.  The well-known default is 5094.  To operate two servers side-by-side, you will want to specify a separate port number for one of them.

&lt;app command line&gt; is a bash command line, with options, used to launch the companion app program.  This argument is optional, as described below.

To terminate the server, type Ctrl-C on the command line.

**hipserver** always executes with a companion app program, **hipflowapp** in this case.  The everyday method to launch the server is:

```text
sudo ./hipserver ./hipflowapp
```

In this case, the **hipserver** will launch itself, then the **hipflowapp**.  Elevated privileges are required for **hipflowapp**, hence launching the server with sudo.

## Developer Guide

Read below to learn how to build and modify this component.

### Architecture

**hipserver** is the client-facing component program that manages IP connections with HART-IP client \(or host\) programs. It manages:

* HART-IP connections with up to three clients
* Published message subscriptions for the clients
* Publishing burst messages to subscribed clients
* Checking HART-IP and HART message framing
* Sending and receiving HART Token-passing messages with a companion server application component program, **hipflowapp**, described [here](https://github.com/FieldCommGroup/HART-IP-Developer-Kit/blob/master/doc/HART-IP%20FlowDevice%20Spec.md).

The following diagram shows how the **hipserver** is related to the other components.

![Flow Device Components](.gitbook/assets/flowcomponent.png)

![Flow Device Components](.gitbook/assets/flowcomponent%20%281%29.png)

Together, these two components form a HART-IP Flow Device. With this architecture, it is easy to change out one app component with another to get a completely different server application. Here are some examples:

* a pass-through to a wired HART device,
* a device simulator, or 
* access to an IO System or Gateway.

### Repository Contents

All code compiles with g++ version 7.4. 

It includes a _make_ based build system in files named Makefile\*. To build **hipserver**, move to this folder and type 'make'.  The executable output file lands in this folder and is named **hipserver**.

The reopsitory contains four folders:

* Server
* AppConnect
* Common
* Realtime

**Server** This folder contains the main program, functions for managing HART-IP connections and the App program connection.

| File | Contents |
| :--- | :--- |
| .cproject, .project | These are Eclipse Oxygen project files. |
| debug.h | Contains \#defines that enable expanded output in the log files. |
| hssubscribe.cpp,.h | Maintains subscriptions for published commands. |
| hsrequest.cpp,.h | The server holds copies of each request and matches each to responses received from **hipflowapp**. |
| hsudp.cpp,.h | HART-IP functionality and message handling reside in these functions. |
| Makefile |  Includes make rules for 'all' and 'clean'. |
| Makefile.inc | Included by Makefile, specifies which source files are built. |
| Makefile\_macros.inc | Included by Makefile, specifies compiler options. |

This folder contains the main program and functions for managing HART-IP connections and the App program connection.

Some interesting files in this folder are described in the following table.

| File | Contents |
| :--- | :--- |
| .cproject,.project | Eclipse CDT Oxygen project settings |
| debug.h | \#defines provide expanded logging output if desired |
| Makefile | Provides rules for 'all' and 'clean'  |
| Makefile.inc | Included in Makefile, specifies source files to be built |
| Makefile\_macros.inc | Included in Makefile, specifies compile and link flags |
| hsqueues.cpp,.h | Create and manage POSIX message queues for communicating with the App component |
| hsrequest.cpp,.h | Track request PDU's received from each client |
| hssems.cpp,.h | Manage semaphores used  |
| hssigs.cpp,.h | Manage signals used |
| hssubscribe.cpp,.h | Keeps a subscription table of which clients have subscribed to what messages |
| hsthreads.cpp,.h | Manage the threads used |
| hsudp.cpp,.h | Socket management, receive and reply to HART-IP messages, route messages |

**AppConnect** This library code is shared with HART-IP server App programs, such as **hipflowapp**.  The contained classes specify what data is communicated via POSIX message queues  between the **hipserver** and **hipflowapp**.

| File | Contents |
| :--- | :--- |
| app.cpp.,h | Contains the App class, which is the parent class for all Apps that communicate with **hipserver**.  The virtual methods in this class should be implemented by each App's sub-class. |
| appconnector.h | This is a template class that defines the message pump for all Apps. |
| appmsg.cpp,.h | This class defines the data that is passed between **hipserver** and its Apps. |
| apppdu.cpp,.h | This class provides convenient access to the message contents. |
| tppdu.cpp,.h | This lightweight class parses TokenPassing PDU's. |
| tpdll.h | Symbolic constants used to parse HART message frames. |

This folder is library code that is used by the **hipserver** and shared with the app components.

| Files | Contents |
| :--- | :--- |
| app.cpp,.h | Contains the App base class for all App components.  Each App must have a subclass that implements the virtual functions defined |
| appconnector.h | This template class contains the message pump and calls the App object to dispatch and receive messages |
| appmsg.h | Defines the message structure of messages passed between hipserver and the app |
| apppdu.cpp,.h | Provide convenient access to the data inside an AppMsg |
| tpdll.h | Symbolic constants required to parse a HART message PDU |
| tppdu.cpp,.h | Methods in this lightweight class are used to parse a HART message |

**Common** folder contains headers defining data types, error values and other enumeration types.

**Realtime** folder contains library code for managing signals, semaphores, threads and POSIX message queues.



