//#include <avr/io.h>

#define XT1 20
#define XT2 21

inline void digiWrite(int pin, int state){
  if(state){
    switch(pin){
      case 0: PORTD |= _BV(0); break;
      case 1: PORTD |= _BV(1); break;
      case 2: PORTD |= _BV(2); break;
      case 3: PORTD |= _BV(3); break;
      case 4: PORTD |= _BV(4); break;
      case 5: PORTD |= _BV(5); break;
      case 6: PORTD |= _BV(6); break;
      case 7: PORTD |= _BV(7); break;
      case 8: PORTB |= _BV(0); break;
      case 9: PORTB |= _BV(1); break;
      case 10: PORTB |= _BV(2); break;
      case 11: PORTB |= _BV(3); break;
      case 12: PORTB |= _BV(4); break;
      case 13: PORTB |= _BV(5); break;
      case 14: PORTC |= _BV(0); break;
      case 15: PORTC |= _BV(1); break;
      case 16: PORTC |= _BV(2); break;
      case 17: PORTC |= _BV(3); break;
      case 18: PORTC |= _BV(4); break;
      case 19: PORTC |= _BV(5); break;
      case 20: PORTB |= _BV(6); break;
      case 21: PORTB |= _BV(7); break;
    }
  }
  else {
    switch(pin){
      case 0: PORTD &= ~_BV(0); break;
      case 1: PORTD &= ~_BV(1); break;
      case 2: PORTD &= ~_BV(2); break;
      case 3: PORTD &= ~_BV(3); break;
      case 4: PORTD &= ~_BV(4); break;
      case 5: PORTD &= ~_BV(5); break;
      case 6: PORTD &= ~_BV(6); break;
      case 7: PORTD &= ~_BV(7); break;
      case 8: PORTB &= ~_BV(0); break;
      case 9: PORTB &= ~_BV(1); break;
      case 10: PORTB &= ~_BV(2); break;
      case 11: PORTB &= ~_BV(3); break;
      case 12: PORTB &= ~_BV(4); break;
      case 13: PORTB &= ~_BV(5); break;
      case 14: PORTC &= ~_BV(0); break;
      case 15: PORTC &= ~_BV(1); break;
      case 16: PORTC &= ~_BV(2); break;
      case 17: PORTC &= ~_BV(3); break;
      case 18: PORTC &= ~_BV(4); break;
      case 19: PORTC &= ~_BV(5); break;
      case 20: PORTB &= ~_BV(6); break;
      case 21: PORTB &= ~_BV(7); break;
    }
  }
}

inline int digiRead(int pin){
  switch(pin){
    case 0: return((PIND & _BV(0))); break;
    case 1: return((PIND & _BV(1)) >> 1); break;
    case 2: return((PIND & _BV(2)) >> 2); break;
    case 3: return((PIND & _BV(3)) >> 3); break;
    case 4: return((PIND & _BV(4)) >> 4); break;
    case 5: return((PIND & _BV(5)) >> 5); break;
    case 6: return((PIND & _BV(6)) >> 6); break;
    case 7: return((PIND & _BV(7)) >> 7); break;
    case 8: return((PINB & _BV(0))); break;
    case 9: return((PINB & _BV(1)) >> 1); break;
    case 10: return((PINB & _BV(2) >> 2)); break;
    case 11: return((PINB & _BV(3)) >> 3); break;
    case 12: return((PINB & _BV(4)) >> 4); break;
    case 13: return((PINB & _BV(5)) >> 5); break;
    case 14: return((PINC & _BV(0))); break;
    case 15: return((PINC & _BV(1)) >> 1); break;
    case 16: return((PINC & _BV(2)) >> 2); break;
    case 17: return((PINC & _BV(3)) >> 3); break;
    case 18: return((PINC & _BV(4)) >> 4); break;
    case 19: return((PINC & _BV(5)) >> 5); break;
    case 20: return((PINB & _BV(6)) >> 6); break;
    case 21: return((PINB & _BV(7)) >> 7); break;
  }
}
