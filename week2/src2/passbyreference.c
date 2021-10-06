#include<stdio.h>

// Initialize an array with values 1,2,3,...,length_of_array
//
// Notice: Any changes made to "array_variable" are reflected in
//         the calling code! Arrays are pass by reference!
//
// Notice: There is no return statement, but still the array is changed
//         and can be said to be "returned" to the calling function.
void build_array( int array_variable[], int length_of_array )
  {
      for (int i=0; i<length_of_array; i++)
      {
          array_variable[i] = i;
      }
  }

        //Test code for passing an array by reference

int main()
{
  int caca[50];

//prints the value of an exact position in the array before the function is activated
//before the array is initialized, its values are 0.
  printf("the value at location 8 starts as %d\n", caca[7]);


  //call function and interact with values: entire empty array named caca and
  //how many of that values the program will change
  build_array(caca, 50);

  //prints the value of an exact location at the array after the function has been activated
  printf("the value at location 8 is now %d\n", caca[7]);

  return 0;
}