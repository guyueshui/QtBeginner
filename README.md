QtBeginner
==========

This is a really simple Qt application started up from a pure manual scratch
refered to

[C++ Tutorial: Create QT applications without QTCreator][1]

without a Qt IDE (i.e. Qt Creator). It's is used for reference to Qt beginners
(like me).

Also, the CMakeLists.txt is refered from [flameshot][2] project.

How to build
------------

Use cmake,

```bash
mkdir build
cd build
cmake ..
make
```

or use qmake

```bash
qmake QtBeginner.pro
make
```

Note that `QtBeginner.pro` is generated by executing `qmake -project` in the
project root, and it needs to be modified with just add one line into it.

```
QT += widgets
```

see [this line](QtBeginner.pro#L8).


[1]:https://www.linux.org/threads/c-tutorial-create-qt-applications-without-qtcreator.18409/
[2]:https://github.com/flameshot-org/flameshot