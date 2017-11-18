# SinglyLinkedList_Large_Integers

##Author: Tony Nguyen
<br />
<br />
This program is written in C using pointers and a singly-linked list to add/subtract
numbers past the bounds of int. I created the singly-linked list backwards (input: 12345, 
actual list: 54321). It makes it easier to calculate the answer, just like how calculations
are done by hand, starting from the ones place and moving to the tens, hundreds, and so on.
It allows for calculating carries and borrows easier.
<br />
<br />
Compile using: gcc -Wall integer.c -o integer
<br />
Run using: ./integer
<br />
	- Input a number, then press enter
  <br />
	- Input a second number, then press enter
  <br />
	- Input either a '+' or a '-'
  <br />
	- Answer will appear
  <br />
	- Program ends
  <br />
	- NOTE: When subtracting, first number cannot be less than second number
		No NEGATIVE numbers.

