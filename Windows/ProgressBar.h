#ifndef ProgressBar_H
#define ProgressBar_H

#include <stdio.h>
#include <inttypes.h>
#include <windows.h>

//!  Progress Bar Class
/*!
  This class is a simple progress bar.
*/
class ProgressBar{
  private:
    //! Bar Value
    /*!
      In this private 8-bit integer variable the bar value is stored.
    */
    uint32_t ui32_barValue;
    //! Max Bar Value
    /*!
      In this private 32-bit integer variable the max bar value is stored.
    */
    uint32_t ui32_maxBar;
    float f_percentageValue;
    //! Max Constant
    /*!
      In this private float variable the division value of ui32_maxBar with ui32_maxValue is stored.
    */
    float f_maxConstant;
    //! Character of Shadow Bar
    /*!
      In this private char variable the shadow char value is stored.
    */
    char c_shadowBar;
    //! Character of Progress Bar
    /*!
      In this private char variable the progress bar char value is stored.
    */
    char c_progressBar;
    //! Character of Frame
    /*!
      In this private char variable the frame char value is stored.
    */
    char c_frame;
    //! Show ProgressBar
    /*!
      This method will round the value.
      \param f_value an float argument.
    */
    uint32_t ui32_roundValue(float f_value);
    //! Show Console Cursor
    /*!
      This method will show the console cursor.
      \param f_value an float argument.
    */
    void showConsoleCursor(bool b_showFlag);
  public:
    //! Neuron Constructor
    /*!
      This constructor will build a progress bar type object.
      \param ui8_maxBar an 8-bit integer (a.k.a. byte) argument.
      \param b_printShadow a boolean variable.
    */
    ProgressBar(uint32_t ui32_maxBar, uint8_t ui32_maxValue);
    //! Neuron Destructor
    /*!
      This destructor will delete this object.
    */
    ~ProgressBar(void);
    //! Show ProgressBar
    /*!
      This method will show the progress bar.
      \param ui32_increase an 32-bit integer argument.
    */
    void showProgressBar(uint32_t ui32_increase);
};

#endif
