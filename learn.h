char*createBuffer(char*argv);
double **createArray(char*buffer, int numCols, int numRows);
double **divideRow(double **array, int a, double c, int x, int y);
double **subtractRow(double **array, int a, int b, double f, int x, int y);
double **transpose(double **array, int cols, int rows);
double **multiply(double **array1, double**array2, int rows1, int cols1, int rows2, int cols2);
