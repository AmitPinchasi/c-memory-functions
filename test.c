#include<stdio.h>
#include<string.h>



///////////////////////////////////////////////////////////////////////////////////
//                                                                               //
//                                                                               //
//                   c memory functions implemented by Amit Pinchasi             //
//                                                                               //
//                                                                               //
///////////////////////////////////////////////////////////////////////////////////
        



//for comfort
typedef unsigned char BYTE;
//
//#define unsigned char BYTE
//
//the typedef is interpreted by the compiler and the define by the preproccesor.


// - SIZEOF -
//we sub the typecasting of the type to bytes and get the delta of 1  to see the delta byte between the types.
//for example for int -> (return (char*)(int*+1)-(char*)(int*)) = (char*)(4*2)-(char*)(4) = 4 with char* casting which returns size_t type. 
#define SizeOf(type) (char *)(&type+1)-(char*)(&type)




// - MEMCPY - 
void MemCpy(void *dest, void *src, size_t n)
{
   //casting src and dest addresses (void *) to (char *)
   //for handling 1 byte
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
  
   for (int i=0; i<n; i++)
       cdest[i] = csrc[i];
}


// - MEMMOVE - 
void MemMove(void *dest, void *src, size_t n)
{
   //casting src and dest addresses (void *) to (char *)
   //for handling 1 byte
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
  
   //creating the temp array to store the src 
   char *temp = (char*) malloc(1*n);
  
   //src to temp
   for (int i=0; i<n; i++)
       temp[i] = csrc[i];
  
   //temp to dest
   for (int i=0; i<n; i++)
       cdest[i] = temp[i];
  
   free(temp);
}


// - MEMSET -
void* MemSet(void *address, int c, int len)
{
  //we do unsigned char pointer to store the ascii value of the c parmeter (int)
  BYTE *p = address;

  //loop
  int i = 0;
  while(len > 0)
    {
      //setting the value
      *p = c;
      //going to the next pointer in the "adress array"
      p++;
      len--;
    }
  return(address);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// the heap,
/////////////////////////////////////////////////////////////////////////////////////////////
//the heap is a very large space in memory which we use to store large buffers of memory
//in addition the heap is not fast as the satck and data segement, but much larger than them
//to get a void pointer to the heap we need to use the malloc() function - memory alloction
//which returns a void pointer in the heap, we need manually delete and free the memory
//from the heap, with the free() function which get a pointer and remove it from the heap
//the heap is acually a memory which the os is ivented! the only way to get to the heap
//in asm is to use syscalls, the heap manged by the os. what would we do without os??
/////////////////////////////////////////////////////////////////////////////////////////////


