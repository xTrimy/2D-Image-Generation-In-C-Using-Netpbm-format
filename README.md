# 2D-Image-Generation-In-C-Using-Netpbm-format
This is a test project where image generation is done in C++ using portable grey maps (PGM) File Formats as it's the easiest file format to be written using a low level language like C++

PGM FIle format consists of a header of *usually* 3 lines
First line is a *string* identifies the file format (**P3**)
second line is the size of the image
third line is the maximum value of the color range

**Example of a PGM image:**

P3<br> 
#This is example of letter P <br>
6 10<br>
1<br> 
0 1 1 1 0 0<br>
0 1 0 0 1 0<br>
0 1 0 0 1 0<br>
0 1 0 0 1 0<br>
0 1 0 0 1 0<br>
0 1 1 1 0 0<br>
0 1 0 0 0 0<br>
0 1 0 0 0 0<br>
0 1 0 0 0 0<br>
0 1 0 0 0 0

Read more about Netpbm formats here https://en.wikipedia.org/wiki/Netpbm_format

# About the project:

You can set the size of the image by setting the width and height int variables

You can create rectangles by defining the X,Y Positions and the Size of the rectangle (SizeX & SizeY) <br>
**example :** <br>
rect(0,0,50,50);<br>
This will create a square of side length 50 pixels from the top left corner of the image

