#include "ProgressBar.h"
/*
The first step is to declare an object of type ProgressBar:

Parameter 1: Size of the progress bar (number of squares).
Parameter 2: Value corresponding to 100% of the bar.

Attention: the percentage indicates the maximum value obtained by the bar!
*/
ProgressBar Test(20, 100);

int main()
{
  for (int i = 0; i <= 100; i++){
    Test.showProgressBar(i);
    Sleep(50);
  }
  return 0;
}
