
# pointers, memory and more ;) 
by Amit Pinchasi

## pointers
**what are pointers?**
a pointer in short is a variable which stores the address of other variable.
int pointer is a pointer which stores the address of int variable,
char pointer is a pointer which stores the address of char variable,
etc, etc..

what else can we do with pointers? we can dereference the pointer into the variable which
the pointer points to! and here comes the fun part.
if we create an int variable "b" which equal to 5.
and create an int pointer variable called "a" which equal to the address of b.
what will be the value of " *a "? ("a" dereference,) 

int b = 5;
int * a = &b;
*(a)?

that going to give us 5!
**what the difference between types of pointers?**
when we dereference char pointer the computer know to dereference only 1 byte after the address, 
and when we dereference int pointer the computer know to dereference 4 byte after the address,
because the size of char variable is 1 byte and the size of int variable is 4 byte.
so when we handling type of pointers, the whole point is how the pointer will dereference, or in other words - the type of pointer is needed so the computer will know how to dereference the variable which the pointer is points to.

**what is the size of pointers in memory?**
the size of pointer is going to be same as all type of pointers. and that depends on
the platform which we compile the program for, and its going to be the size of the 
address bus. in 16 bit computer the size of a pointer is 2 byte, in 32 computer the size
of a pointer is 4 byte and etc.. 

**what is void pointer?**
a void pointer is a generic pointer which can change his type to a another type in runtime.
so if we dereference a void pointer we get an error, because the compiler doesn't no how to
dereference a void pointer, and this is why the pointer calls generic.
int a = 5;
void * ptr = &a ;


**what is a null pointer?**
a null pointer is a pointer which points to a location not on the memory of the program
but in the same time not a pointer who would give you segfault. and the value of it is null,
void* ptr = NULL;

**okay, what can i use pointer for?**
you can have pointer to variables, structs, arrays, files, a pointer to a pointer and even functions.

**what about operations?**
when your doing archmatic operations to pointers for example incrementing the address will 
jump as the size of the type that being points by the pointer. for example if we add 1 to
an int pointer which points to the address of 100 we will get 104 because the size of int
is 4 bytes. 
int* ptr = 1000;
(ptr+1) = 1004
fun fact: The C standard doesn’t allow pointer arithmetic with void pointers

**are pointers and arrays the same?**
very similar. too of them are pointing to and address in memory but there is actually a difference,
by definition array is group of variables which relates to each other, pointers are as we say earlier 
a variables which stores address. we can use pointers to store an adress of group of variables 
and it will be exacly like an array however we can use pointers for much more. in addition in the metadata of the program the compilers gives a different meaning for the two. in the metadata the size of an array will return the size of all the elements in memory and the size of a pointer will give you the size of the pointer in memory so when we dealing with pointers, if we use pointers to acts like an array we need to know that in the metadata there is no a save which save how much elements are should be together an a group so if we want to know we need to make a temporary to save the numebrs of elements.
fun fact: -> string in c is char array.
char arr[1]  = "";
char * arr = "";
so:
the difference between pointer and array that in the metadata in the compiler the compiler
store the size of the array, and in pointers he store only the size of the pointer.
 
 **const pointers and pointers to const values.**
const pointer- pointer which have a final value.
int* const ptr;
a pointer to const var - pointer which points to a const value.
const int* ptr;
## c memory functions

the sizeof() function takes void pointer (generic function) and returns the size on memory of
the type. 

the memcpy() functions takes, void pointer to destination, to source and size_t for the size
and copy from dest to src for size_t.

the memmov() function does the same as the memcpy function but in different algorithm.

the memset() function takes a void pointer, size_t, and a character and setting in the address
for the given size in memory the character given.

## the heap,

the heap is a very large space in memory which we use to store large buffers of memory
in addition the heap is not fast as the stack and data segment, but much larger than them
to get a void pointer to the heap we need to use the malloc() function - memory allocation
which returns a void pointer in the heap, we need manually delete and free the memory
from the heap, with the free() function which get a pointer and remove it from the heap
the heap is actually a memory which the os is invented! the only way to get to the heap
in asm is to use syscalls, the heap manged by the os. what would we do without os??

