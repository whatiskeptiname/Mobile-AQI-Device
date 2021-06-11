int n_num, n_dustDensity;

void next_data(float dustDensity) //function to regression analysis
{
  int n = 16;
  int x[16] = {155, 157, 165, 168, 159, 142, 152, 152, 141, 148, 153, 151, 141, 154, 154, 166}; //sample data for regression analysis 
  int y[16] = {157, 165, 168, 159, 142, 152, 152, 141, 148, 153, 151, 141, 154, 154, 166, 177}; //dependency of next hour data on present data
  float x2[16];
  float xy[16];
  float sumX = 0;
  float sumY = 0;
  float sumX2 = 0;
  float sumXY = 0;

  for (int i = 0; i < n ; i++) //regression calculation
  {
    sumX += x[i];   
    sumY += y[i];
    x2[i] = x[i] * x[i];
    xy[i] = x[i] * y[i];
    sumXY += xy[i];
    sumX2 += x2[i];
  }
  float b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX); // slope of regression line
  float a = sumY / n - b * sumX / n; // y intercept on regression line
  
  n_dustDensity = (a + b * dustDensity); //predicted pollution level
  n_num = map(n_dustDensity, 0, 600, 0, 10); //mapping the data between 0-10
}
