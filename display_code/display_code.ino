
float T1 = 0;
  float T2 = 0;
  int pass;
  int jj = 0;
  float initial_time;
  void setup() {
  // put your setup code here, to run once:
  pinMode(9, INPUT); // the button corresponding to yellow LED
  pinMode(10, INPUT); // the button corresponding to red LED
  pinMode(11, OUTPUT); // the yellow LED
  pinMode(12, OUTPUT); // the red LED

}

void screencontroller(int input_number){
  DDRD = B1111111;
  DDRC = B001111; 
  int numbit[10];
  int numdigit[5];
  numdigit[0] = 0b111110;
  numdigit[1] = 0b111101;
  numdigit[2] = 0b111011;
  numdigit[3] = 0b110111;
  numdigit[4] = 0b111111;
  numbit[0] = 0b00111111; 
  numbit[1] = 0b00000110;
  numbit[2] = 0b01011011;
  numbit[3] = 0b01001111;
  numbit[4] = 0b01100110;
  numbit[5] = 0b01101101;
  numbit[6] = 0b01111101;
  numbit[7] = 0b00000111;
  numbit[8] = 0b01111111;
  numbit[9] = 0b01101111;
  
  int ones = (input_number%10); // digit 4
  int tens = ((input_number/10)%10); // digit 3
  int hundreds = ((input_number/100)%10); // digit 2
  int thousands = (input_number/1000); // digit 1
  int first_time = millis();

  while(millis()-first_time <= 200){
      PORTD = numbit[ones];
      PORTC = numdigit[3];
      delayMicroseconds(1200);
      PORTC = numdigit[4];

      if(tens > 0 | (hundreds > 0 | thousands > 0)){
        PORTD = numbit[tens];
        PORTC = numdigit[2];
        delayMicroseconds(1200);
        PORTC = numdigit[4];
        }
      if(hundreds > 0 | thousands > 0){
        PORTD = numbit[hundreds];
        PORTC = numdigit[1];
        delayMicroseconds(1200);
        PORTC = numdigit[4];
        }
      if(thousands > 0){
        PORTD = numbit[thousands];
        PORTC = numdigit[0];
        delayMicroseconds(1200);
        PORTC = numdigit[4];
        }
    }
  return;
  }

void loop() {
  // put your main code here, to run repeatedly:
   
  }
 
