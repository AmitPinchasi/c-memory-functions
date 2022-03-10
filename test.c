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

