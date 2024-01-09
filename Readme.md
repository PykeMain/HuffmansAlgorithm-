# "Huffman's Algorithm"

Author: Momchil Mladenov
Github: [https://github.com/PykeMain/HuffmansAlgorithm-.git](https://github.com/PykeMain/HuffmansAlgorithm-.git)
Structure Data Programing project @ FMI

The program can encode and decode following [David A. Huffman](https://en.wikipedia.org/wiki/David_A._Huffman) [algorithm](https://en.wikipedia.org/wiki/Huffman_coding). The data is imported from files in the **Text** folder, as well as recorded there.


There is also a debug feature that prints the value of every byte in an encoded sequence.

There is a Doxyfile that needs to be ran to generate the documantation.

Project is created with CMake so create a build folder on the level of src,test and text and then run:
```
cmake .. 
make
```

