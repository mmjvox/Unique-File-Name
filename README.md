# Unique-File-Name
Suggests a unique file name when saving new files for Qt.


## file name.txt
## file name (1).txt
## file name (2).txt


### usage:
copy `UniqueFileName.h` file in your include path or project main directory or add to .pro as a header.
use that any where you opennig new file:
```
UniqueFileName::newName("newfile")
```
for example:
```
QFile file(UniqueFileName::newName("./newfile.txt"));
file.open();

QPrinter printer(QPrinter::PrinterResolution);
printer.setOutputFileName( UniqueFileName::newName( "/home/user/Desktop/new print.pdf" ) );

QImage image;
image.save(UniqueFileName::newName("../images/image.png"), "PNG");

QXlsx::Document xlsx;
xlsx.saveAs(UniqueFileName::newName("~/Documents/Test.xlsx"));
```
