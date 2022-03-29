//SunRiver
namespace sr
{
    public class Matrix
    {
        public double[,] data;

        public Matrix(double[,] data)
        {
            this.data = data;
        }

        public Matrix(int row = 2, int col = 2)
        {
            data = new double[row, col];
        }

        public Matrix(Matrix matrix)
        {
            data = (double[,])matrix.data.Clone();
        }
        
        //可以像数组一样访问数据
        public double this[int row,int col]
        {
            get { return data[row, col]; }
            set { data[row, col] = value; }
        }

        //矩阵转置
        public Matrix T => new Matrix(Transpose(data)); 

        //逆矩阵
        public Matrix inv  => new Matrix(Inv(data)); 

        //行列式的值
        public double det => Det(data);

        //多少行
        public int row => data.GetLength(0);

        //多少列
        public int col => data.GetLength(1);

        //扩展矩阵
        public Matrix Extension(Matrix other)
        {
            return new Matrix(Extension(data, other.data));
        }

        //扩展矩阵,垂直的
        public Matrix ExtensionV(Matrix other)
        {
            return new Matrix(ExtensionV(data, other.data));
        }

        //截取矩阵中的一部分
        public Matrix Sub(int row_start, int col_start, int row_end, int col_end)
        {
            return new Matrix(Sub(data, row_start, col_start, row_end, col_end));
        }
        public Matrix Sub(int row_start, int col_start)
        {
            return new Matrix(Sub(data, row_start, col_start, row-1, col-1));
        }

        public override string ToString()
        {
            return ToString("{0:F2}");
        }

        public string ToString(uint precision)
        {
            return ToString("{0:F" + precision + "}");
        }

        public string ToString(string format)
        {
            string str = "";
            for (int r = 0; r < row; ++r)
            {
                for (int c = 0; c < col; ++c)
                {
                    str += string.Format(format,data[r,c]) + '\t';
                }
                str += '\n';
            }
            return str;
        }
        
        public static Matrix operator +(Matrix a, Matrix b)
        {
            return new Matrix(Add(a.data, b.data));
        }

        public static Matrix operator -(Matrix a, Matrix b)
        {
            return new Matrix(Subtract(a.data, b.data));
        }

        public static Matrix operator *(Matrix a, Matrix b)
        {
            return new Matrix(Multiply(a.data, b.data));
        }

        //--------------------快速建立特殊的矩阵---------------        
        //对角矩阵
        public static Matrix Diagonal(double[] data)
        {
            Matrix matrix = new Matrix(data.Length, data.Length);
            for (int i = 0; i < data.Length; ++i)
            {
                matrix[i, i] = data[i];
            }
            return matrix;
        }

        //单位矩阵
        public static Matrix Identity(int count)
        {
            Matrix matrix = new Matrix(count, count);
            for (int i = 0; i < count; ++i)
            {
                matrix[i, i] = 1.0;
            }
            return matrix;
        }

        //一行
        public static Matrix Row(double[] data)
        {
            Matrix matrix = new Matrix(1, data.Length);
            for (int i = 0; i < data.Length; ++i)
            {
                matrix[0, i] = data[i];
            }
            return matrix;
        }

        //一列
        public static Matrix Col(double[] data)
        {
            Matrix matrix = new Matrix( data.Length,1);
            for (int i = 0; i < data.Length; ++i)
            {
                matrix[i,0] = data[i];
            }
            return matrix;
        }

        //---------------------------------------------------------
        //下面是针对于原始数据进行的运算

        //矩阵的转置 
        public static double[,] Transpose(double[,] iMatrix)
        {
            int row = iMatrix.GetLength(0);
            int column = iMatrix.GetLength(1);

            double[,] iMatrixT = new double[column, row];

            for (int i = 0; i < column; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    iMatrixT[i, j] = iMatrix[j, i];
                }
            }
            return iMatrixT;
        }

        //矩阵的逆矩阵，根据扩展矩阵化单位矩阵求的 
        public static double[,] Inv(double[,] iMatrix)
        {
            if (iMatrix.GetLength(0) != iMatrix.GetLength(1)) { throw new System.Exception("Inv need the count of row equals col "); }

            int i = 0;
            int row = iMatrix.GetLength(0);
            double[,] MatrixZwei = new double[row, row * 2];
            double[,] iMatrixInv = new double[row, row];

            //构造扩展矩阵,[ A  E ]
            for (i = 0; i < row; ++i)
            {
                for (int j = 0; j < row; ++j)
                {
                    MatrixZwei[i, j] = iMatrix[i, j];
                }
            }
            for (i = 0; i < row; ++i)
            {
                for (int j = row; j < row * 2; ++j)
                {
                    MatrixZwei[i, j] = (i + row == j) ? 1 : 0;
                }
            }

            for (i = 0; i < row; ++i)
            {
                if (MatrixZwei[i, i] == 0)
                {
                    bool ok = false;
                    for (int j = i + 1; j < row; ++j)
                    {
                        if (MatrixZwei[j, i] != 0)
                        {
                            double temp;
                            for (int k = 0; k < row * 2; ++k)
                            {
                                temp = MatrixZwei[i, k];
                                MatrixZwei[i, k] = MatrixZwei[j, k];
                                MatrixZwei[j, k] = temp;
                            }

                            ok = true;
                            break;
                        }
                    }
                    if (!ok) { throw new System.Exception("Can't get inv for this matrix!"); }
                }

                double intTemp = MatrixZwei[i, i];
                for (int j = 0; j < row * 2; j++)
                {
                    MatrixZwei[i, j] = MatrixZwei[i, j] / intTemp;
                }

                for (int j = 0; j < row; ++j)
                {
                    if (j == i) { continue; }

                    intTemp = MatrixZwei[j, i];
                    for (int k = 0; k < row * 2; ++k)
                    {
                        MatrixZwei[j, k] -= MatrixZwei[i, k] * intTemp;
                    }
                }
            }

            for (i = 0; i < row; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    iMatrixInv[i, j] = MatrixZwei[i, j + row];
                }
            }
            return iMatrixInv;
        }

        //矩阵加法 
        public static double[,] Add(double[,] MatrixEin, double[,] MatrixZwei)
        {
            int row = MatrixEin.GetLength(0);
            int col = MatrixEin.GetLength(1);
            if (row != MatrixZwei.GetLength(0) || col != MatrixZwei.GetLength(1)) { throw new System.Exception("size unequal"); }

            double[,] MatrixResult = new double[row,col];
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    MatrixResult[i, j] = MatrixEin[i, j] + MatrixZwei[i, j];
            return MatrixResult;
        }

        //矩阵减法 
        public static double[,] Subtract(double[,] MatrixEin, double[,] MatrixZwei)
        {
            int row = MatrixEin.GetLength(0);
            int col = MatrixEin.GetLength(1);
            if (row != MatrixZwei.GetLength(0) || col != MatrixZwei.GetLength(1)) { throw new System.Exception("size unequal"); }

            double[,] MatrixResult = new double[row,col];
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    MatrixResult[i, j] = MatrixEin[i, j] - MatrixZwei[i, j];
            return MatrixResult;
        }

        //矩阵乘法 
        public static double[,] Multiply(double[,] MatrixEin, double[,] MatrixZwei)
        {
            if (MatrixEin.GetLength(1) != MatrixZwei.GetLength(0)) { throw new System.Exception("* col != row"); }

            double[,] MatrixResult = new double[MatrixEin.GetLength(0), MatrixZwei.GetLength(1)];
            for (int i = 0; i < MatrixEin.GetLength(0); ++i)
            {
                for (int j = 0; j < MatrixZwei.GetLength(1); ++j)
                {
                    for (int k = 0; k < MatrixEin.GetLength(1); ++k)
                    {
                        MatrixResult[i, j] += MatrixEin[i, k] * MatrixZwei[k, j];
                    }
                }
            }
            return MatrixResult;
        }

        //行列式的值 
        public static double Det(double[,] MatrixEin)
        {
            if (MatrixEin.GetLength(0) != MatrixEin.GetLength(1)) { throw new System.Exception("Det need the count of row equals col ");  }

            int rows = MatrixEin.GetLength(0);
            if(rows==1)
            {
                return MatrixEin[0, 0];
            }
            else if(rows==2)
            {
                return MatrixEin[0, 0] * MatrixEin[1, 1] - MatrixEin[0, 1] * MatrixEin[1, 0];
            }
            else if(rows == 3)
            {
                return MatrixEin[0, 0] * MatrixEin[1, 1] * MatrixEin[2, 2] + MatrixEin[0, 1] * MatrixEin[1, 2] * MatrixEin[2, 0] + MatrixEin[0, 2] * MatrixEin[1, 0] * MatrixEin[2, 1]
           - MatrixEin[0, 2] * MatrixEin[1, 1] * MatrixEin[2, 0] - MatrixEin[0, 1] * MatrixEin[1, 0] * MatrixEin[2, 2] - MatrixEin[0, 0] * MatrixEin[1, 2] * MatrixEin[2, 1];
            }
            else
            {
                const double precision = 1E-8;
                double[,] matrix = (double[,])MatrixEin.Clone();
                double sum = 1.0;
                for (int i = 0; i < rows; ++i)
                {                   
                    if(System.Math.Abs( matrix[i,i]) < precision)
                    {
                        int j = i + 1;
                        for(;j<rows;++j)
                        {
                            if(System.Math.Abs( matrix[j,i]) > precision)
                            {
                                double temp;
                                for (int k = 0; k < rows; ++k)
                                {
                                    temp = matrix[i, k];
                                    matrix[i, k] = matrix[j, k];
                                    matrix[j, k] = temp;
                                }
                                sum = -sum;
                                break;
                            }
                        }
                        if(j==rows) { return 0.0; }
                    }
                    sum *= matrix[i, i];

                    for (int j = i+1; j < rows; ++j)
                    {
                        double B = -matrix[j, i] / matrix[i, i];
                        for (int k = 0; k < rows; ++k)
                        {
                            matrix[j, k] += B * matrix[i, k];
                        }
                    }

                }
                return sum;
            }
           
        }

        //扩展矩阵，垂直的 
        public static double[,] ExtensionV(double[,] up, double[,] down)
        {
            if (up.GetLength(1) != down.GetLength(1)) { throw new System.Exception("Extension: col number is unequal."); }
            int uprow = up.GetLength(0);
            int col = up.GetLength(1);
            double[,] ex = new double[up.GetLength(0) + down.GetLength(0), col];
            
            for (int i = 0; i < uprow; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    ex[i, j] = up[i, j];
                }
            }
            for (int i = 0; i < down.GetLength(0); ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    ex[i + uprow, j] = down[i, j];
                }
            }
            return ex;
        }

        //扩展矩阵
        public static double[,] Extension(double[,] left, double[,] right)
        {
            if (left.GetLength(0) != right.GetLength(0)) { throw new System.Exception("Extension: row number is unequal."); }
            int leftcol = left.GetLength(1);
            int row = left.GetLength(0);
            double[,] ex = new double[row, left.GetLength(1) + right.GetLength(1)];
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < leftcol; ++j)
                {
                    ex[i, j] = left[i, j];
                }
            }

            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < right.GetLength(1); ++j)
                {
                    ex[i, leftcol + j] = right[i, j];
                }
            }

            return ex;
        }

        //截取矩阵中的一部分
        public static double[,] Sub(double[,] source,int row_start,int col_start,int row_end,int col_end)
        {
            double[,] result = new double[1 + row_end - row_start, 1 + col_end - col_start];
            for(int r = row_start;r<=row_end;++r)
            {
                for(int c = col_start; c<=col_end; ++c)
                {
                    result[r-row_start, c-col_start] = source[r, c];
                }
            }
            return result;
        }
    }
}
