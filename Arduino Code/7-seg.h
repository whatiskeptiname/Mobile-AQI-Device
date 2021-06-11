int disp_pin[8];  /* array for a-g pins of 7-Segment display */
bool dot = 1;

void define_segment_pins(int a, int b, int c, int d, int e, int f, int g, int dp) /* Assigns 7-segment display pins to board */
{
  disp_pin[0] = a;
  disp_pin[1] = b;
  disp_pin[2] = c;
  disp_pin[3] = d;
  disp_pin[4] = e;
  disp_pin[5] = f;
  disp_pin[6] = g;
  disp_pin[7] = dp;
}

void s_disp(int num, bool dot) /* Function for displaying number (0-9) */
{
  digitalWrite(disp_pin[7], dot);
  switch (num)
  {
    case 0:
      digitalWrite(disp_pin[0], LOW); /* Drive disp_pin[0] to LOW */
      digitalWrite(disp_pin[1], LOW); /* Driving LOW turns on LED segment for common anode display */
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], LOW);
      digitalWrite(disp_pin[5], LOW);
      digitalWrite(disp_pin[6], HIGH);
      break;
    case 1:
      digitalWrite(disp_pin[0], HIGH);  /* Drive disp_pin[7] to HIGH */
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], HIGH);  /* Driving HIGH turns off LED segment for common anode display */
      digitalWrite(disp_pin[4], HIGH);
      digitalWrite(disp_pin[5], HIGH);
      digitalWrite(disp_pin[6], HIGH);
      break;
    case 2:
      digitalWrite(disp_pin[0], LOW);
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], HIGH);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], LOW);
      digitalWrite(disp_pin[5], HIGH);
      digitalWrite(disp_pin[6], LOW);
      break;
    case 3:
      digitalWrite(disp_pin[0], LOW);
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], HIGH);
      digitalWrite(disp_pin[5], HIGH);
      digitalWrite(disp_pin[6], LOW);
      break;
    case 4:
      digitalWrite(disp_pin[0], HIGH);
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], HIGH);
      digitalWrite(disp_pin[4], HIGH);
      digitalWrite(disp_pin[5], LOW);
      digitalWrite(disp_pin[6], LOW);
      break;
    case 5:
      digitalWrite(disp_pin[0], LOW);
      digitalWrite(disp_pin[1], HIGH);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], HIGH);
      digitalWrite(disp_pin[5], LOW);
      digitalWrite(disp_pin[6], LOW);
      break;
    case 6:
      digitalWrite(disp_pin[0], LOW);
      digitalWrite(disp_pin[1], HIGH);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], LOW);
      digitalWrite(disp_pin[5], LOW);
      digitalWrite(disp_pin[6], LOW);
      break;
    case 7:
      digitalWrite(disp_pin[0], LOW);
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], HIGH);
      digitalWrite(disp_pin[4], HIGH);
      digitalWrite(disp_pin[5], HIGH);
      digitalWrite(disp_pin[6], HIGH);
      break;
    case 8:
      digitalWrite(disp_pin[0], LOW);
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], LOW);
      digitalWrite(disp_pin[5], LOW);
      digitalWrite(disp_pin[6], LOW);
      digitalWrite(disp_pin[7], dot);
      break;
    case 9:
      digitalWrite(disp_pin[0], LOW);
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], HIGH);
      digitalWrite(disp_pin[5], LOW);
      digitalWrite(disp_pin[6], LOW);
      break;
    default:
      digitalWrite(disp_pin[0], HIGH);
      digitalWrite(disp_pin[1], LOW);
      digitalWrite(disp_pin[2], LOW);
      digitalWrite(disp_pin[3], LOW);
      digitalWrite(disp_pin[4], LOW);
      digitalWrite(disp_pin[5], HIGH);
      digitalWrite(disp_pin[6], LOW);
      digitalWrite(disp_pin[7], HIGH);
      break;
  }
}
