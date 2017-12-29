---
id: AddingQEasyDownloader
title: Adding QEasyDownloader to your Qt Project
sidebar_label: Adding to your Qt Project
---

|	    |				       		     |		
|-----------|------------------------------------------------|
|  Header:  | #include "QEasyDownloader/QEasyDownloader.hpp" |
|   qmake:  | QT += network core   		       	     |
|	    | HEADERS += QEasyDownloader/QEasyDownloader.hpp |
|Inherits:  | [QObject](http://doc.qt.io/qt-5/qobject.html)  |	

**QEasyDownloader** is just a header and all you have to do after installation is to add   
it in your **.pro** file ( **Qt Project file** ).

### Qt Project file (**.pro**)

Append these **lines** to your **Qt Project file**.

```
QT += network core
HEADERS += QEasyDownloader/QEasyDownloader.hpp
```

### Including in your Source

Whenever you want to use **QEasyDownloader** , you just need to include it!

```
#include "QEasyDownloader/QEasyDownloader.hpp"
```

