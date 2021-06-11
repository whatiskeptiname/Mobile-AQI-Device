int n_num, n_dustDensity;

void next_data(float dustDensity)
{
  int n = 16;
  int x[n] = {155, 157, 165, 168, 159, 142, 152, 152, 141, 148, 153, 151, 141, 154, 154, 166};
  int y[n] = {157, 165, 168, 159, 142, 152, 152, 141, 148, 153, 151, 141, 154, 154, 166, 177};
  float x2[n];
  float xy[n];
  float sumX = 0;
  float sumY = 0;
  float sumX2 = 0;
  float sumXY = 0;

  for (int i = 0; i < n ; i++)
  {
    sumX += x[i];   
    sumY += y[i];
    x2[i] = x[i] * x[i];
    xy[i] = x[i] * y[i];
    sumXY += xy[i];
    sumX2 += x2[i];
  }
  float b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  float a = sumY / n - b * sumX / n;
  
  n_dustDensity = (a + b * dustDensity);
  n_num = map(n_dustDensity, 0, 600, 0, 10);
//  Serial.println(b);
//  Serial.println(n_dustDensity);

}
