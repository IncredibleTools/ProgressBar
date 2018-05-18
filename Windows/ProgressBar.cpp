#include "ProgressBar.h"

ProgressBar::ProgressBar(uint32_t ui32_maxBar, uint8_t ui32_maxValue){
  this->c_shadowBar = 177;
  this->c_progressBar = 219;
  this->c_frame = 179;
  this->ui32_maxBar = ui32_maxBar;
  this->f_maxConstant = (float)ui32_maxBar/(float)ui32_maxValue;
	this->f_percentageValue = 0;
  this->ui32_barValue = 0;
}

ProgressBar::~ProgressBar(){
}

void ProgressBar::showProgressBar(uint32_t ui32_increase){
  showConsoleCursor(false);
  uint32_t ui32_newIncrease = ui32_roundValue((float)ui32_increase*(float)this->f_maxConstant);
  bool b_flagPrintPercentageProgress = false;
  this->f_percentageValue = (float)ui32_increase*(float)this->f_maxConstant/(float)this->ui32_maxBar*(float)100;
  if ((float)ui32_increase*(float)this->f_maxConstant > ui32_barValue){
    this->ui32_barValue = ui32_newIncrease;
  }
	printf ("\r");
	printf("%c", this->c_frame);
	for(uint32_t ui32_counter = 0; ui32_counter < ui32_newIncrease; ui32_counter++){
		printf("%c", this->c_progressBar);
	}
	while(ui32_newIncrease < this->ui32_maxBar){
		printf("%c", this->c_shadowBar);
		ui32_newIncrease++;
	}
	if (f_percentageValue == 100){
		showConsoleCursor(true);
	}
	printf("%c", this->c_frame);
	printf(" - %.2f%c", (float)this->f_percentageValue, 37);
}

uint32_t ProgressBar::ui32_roundValue(float f_value){
  uint32_t ui32_compareValue = (uint32_t)f_value;
  float f_decimalValue = (float)f_value - (float)ui32_compareValue;
  if (f_decimalValue >= 0.8){
    return ui32_compareValue + 1;
  }
  else{
    return ui32_compareValue;
  }
}

void ProgressBar::showConsoleCursor(bool b_showFlag){
  HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO CursorInfo;
  GetConsoleCursorInfo(out, &CursorInfo);
  CursorInfo.bVisible = b_showFlag;
  SetConsoleCursorInfo(out, &CursorInfo);
}
