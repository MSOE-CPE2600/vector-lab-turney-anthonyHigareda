# VECTOR CALCULATOR
### Version 1.0: Released 21 October 2025

#### Developed by Anthony Higareda for MSOE CPE2600-111, Systems Programming, Lab 7<br><br><br>

Create 3-dimensional vectors and perform mathematical functions on them.
This program uses dynamic memory to store a near-infinite amount of vectors.

*Build the program with:*
> `gcc -o vector main.c mathcontroller.c storagecontroller.c userinterface.c - Wall`

*Run the program with:*
> `./vector`

**Mathematical Functions Available:**
- Addition
  > `c = a + b`
- Subtraction
  > `c = a - b`
- Scalar Multiplication
  > `c = a * 9`
- Dot Product
  > Returns a floating-point value; cannot be saved as a vector!<br>
  > `a . b`
- Cross Product
  > `c = a X b`

**A note about the required syntax:**
All terms and symbols must be separated by one and ONLY one space `" "` or comma `","`
> `c = a + b` OR `c,=,a,+,b` OR `c =,a +,b`

**System Functions Available:**
- Load
  > Read vectors into memory from a .csv file<br>
  > `load example.csv`
- Save
  > Save all vectors in memory to a .csv file<br>
  > `save example.csv`
- Clear
  > Remove all vectors from memory
- List
  > Display all vectors in memory
- Quit
  > Exit the program

**Dynamic Memory Functionality**

This program uses dynamic memory to increase the size of the backing array which stores all vectors.
Each vector is a struct that holds a name of up to 10 characters, as well as a double-precision 
floating-point number for each of the 3 directional values.
Upon running the program, the array of vectors has space for only 5 vectors. Each slot in this array is initialized
with a vector named "NULL" and x, y, and z coordinates all set to 0.0. When a new vector is created and saved to the array,
the first instance of a NULL vector is overwritten with the new vector. When attempting to add a vector to the array
when the array has been filled, a new array is allocated to memory with space for 5 more vectors than the current array. 
Each vector in the old array is copied into the new array, and the 5 new slots are initialized to the NULL vector. The old
vector is freed from memory and then pointed to the new array. When the `clear` command is given, the array is freed from memory,
then reallocated as an array with space for 5 vectors that are set to the NULL vector.