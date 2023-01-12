#include <LiquidCrystal_I2C.h>

//Key Values:
//Yes = 42
//No = 64
//Normal = 1023

LiquidCrystal_I2C lcd (0x27 , 16, 2);

int buttonst = 0;
int btn = A0;
int buttonvalue;

int item = 0;

void setup() {
  // put your setup code here, to run once:
    lcd.backlight();
    lcd.clear();
    lcd.init();
}

void loop() {
  // put your main code here, to run repeatedly:
   buttonvalue = analogRead(A0);

   selected(buttonst);
     
   if(buttonvalue == 64){
      if(buttonst < 3){
      buttonst++;
      delay(400);
      
     }
      else{
      buttonst = -1;
      selected(buttonst);
     }
   }

   else if (buttonvalue == 42){
      yes_selected();
   }
}

void selected(int buttonst){
    
    lcd.setCursor(1,0);
    lcd.print("item1");
    
    lcd.setCursor(9,0);
    lcd.print("item2");
  
    lcd.setCursor(1,1);
    lcd.print("item3");
  
    lcd.setCursor(9,1);
    lcd.print("item4");

    
    
    if (buttonst == 0){
      lcd.setCursor(8,1);
      lcd.print(" ");
      lcd.setCursor(0,0);
      lcd.print(">");
    }
  
    if (buttonst == 1){
      lcd.setCursor(0,0);
      lcd.print(" ");
      lcd.setCursor(8,0);
      lcd.print(">");
    }
  
    if (buttonst == 2){
      lcd.setCursor(8,0);
      lcd.print(" ");
      lcd.setCursor(0,1);
      lcd.print(">");
    }
  
    if (buttonst == 3){
      lcd.setCursor(0,1);
      lcd.print(" ");
      lcd.setCursor(8,1);
      lcd.print(">");
    }
}



void yes_selected(){
  
    if (buttonst == 0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("item1 selected");
      delay(1000);

      lcd.setCursor(0,0);
      lcd.print(" ");
      
      lcd.setCursor(6,0);
      lcd.print("   ");
    
      lcd.setCursor(6,1);
      lcd.print("   ");
      
      selected(buttonst);
      
    }
  
    if (buttonst == 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("item2 selected");
      delay(1000);

      lcd.setCursor(0,0);
      lcd.print(" ");
      
      lcd.setCursor(6,0);
      lcd.print("   ");
    
      lcd.setCursor(6,1);
      lcd.print("   ");
      
      selected(buttonst);
      
    }
  
    if (buttonst == 2){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("item3 selected");
      delay(1000);

      lcd.setCursor(0,0);
      lcd.print(" ");
      
      lcd.setCursor(6,0);
      lcd.print("   ");
    
      lcd.setCursor(6,1);
      lcd.print("   ");
      
      selected(buttonst);
      
    }
  
    if (buttonst == 3){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("item4 selected");
      delay(1000);

      lcd.setCursor(0,0);
      lcd.print(" ");
      
      lcd.setCursor(6,0);
      lcd.print("   ");
    
      lcd.setCursor(6,1);
      lcd.print("   ");
      
      selected(buttonst);
      
    }
}
