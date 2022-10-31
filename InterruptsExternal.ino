unsigned long int timerLED1;
unsigned long int timePreview = 0;
bool LEDOn = 0;
 
ISR (TIMER0_COMPA_vect) //функция, вызываемая таймером-счетчиком T0
{
    timerLED1++;
    if(timerLED1 - timePreview >= 1000)  //сверяем текущее время с последним сохраненным
    {                                    //если прошло больше 1000 мс
      timePreview = timerLED1;           //сохраняем новое время для последующей сверки
      digitalWrite(13, (LEDOn = !LEDOn));  
    }  
}
void setup() 
{
  pinMode(13, OUTPUT);
  TCCR0A |= (1 << WGM01);              //сброс при совпадении
  OCR0A = 0xF9;                        //начало отсчета до переполнения (249)
  TIMSK0 |= (1 << OCIE0A);             //разрешить прерывание при совпадении с регистром А
  TCCR0B |= (1 << CS01) | (1 << CS00); //установить делитель частоты на 64 
  sei();                               //разрешить прерывания
}
void loop() 
{
  
}