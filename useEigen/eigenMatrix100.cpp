/*
* 编程实现 A 为 100 × 100 随机矩阵时，⽤ QR 和 Cholesky 分解求 x 的程序。你可以参考本次课⽤到的 useEigen 例程。
*/

#include <iostream>
using namespace std;

#include <ctime>
// Eigen 核心部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>

using namespace Eigen;

#define MATRIX_SIZE 100 

 

int main ( int argc, char** argv ) 
{ 
     Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_NN; 
     Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> v_Nd; 
     matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE ,MATRIX_SIZE); 
     v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE , 1); 
     cout << "100*100的矩阵A为：\n" << matrix_NN <<"\n"<< endl; 
     cout << "b向量为： \n"<< v_Nd <<"\n"<< endl;

     //生成100*100的正定对称矩阵A_sym 
     Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_NN_sym; 
     matrix_NN_sym = matrix_NN; 
     // matrix_NN_sym.array() += 1;//加法 
     matrix_NN_sym = matrix_NN_sym.array().abs(); 
     for (int i=0; i<MATRIX_SIZE; i++) 
     { 
          for (int j=0; j<MATRIX_SIZE; j++) 
          { 
               if (i>j) 
               { 
                    matrix_NN_sym(i,j)=matrix_NN_sym(j,i); 
               } 
          } 
     } 
     cout << "100*100的正定对称矩阵A_sym为：\n" << matrix_NN_sym <<"\n"<< endl; 

     //直接求逆求解 
     clock_t time_stt = clock(); 
     Eigen::Matrix<double, MATRIX_SIZE, 1> x_inverse = matrix_NN_sym.inverse()*v_Nd; 
     cout << "x_inverse =\n" << x_inverse<<"\n"<< endl; 
     cout << "time use in normal inverse is \n" << 1000*(clock() - time_stt)/(double) 
     CLOCKS_PER_SEC << "ms" <<"\n"<<endl; 
 
     //求QR分解求解 
     time_stt = clock(); 
     Eigen::Matrix<double, MATRIX_SIZE, 1> x_QR = 
     matrix_NN_sym.colPivHouseholderQr().solve(v_Nd); 
     cout << "x_QR =\n" << x_QR <<"\n"<< endl; 
     cout << "time use in Qr composition is \n" << 1000* (clock() - time_stt)/(double) 
     CLOCKS_PER_SEC << "ms" <<"\n"<<endl; 
     
     //Cholesky 求解 
     time_stt = clock(); 
     Eigen::Matrix<double, MATRIX_SIZE, 1> x_Cholesky_ldlt = matrix_NN_sym.ldlt().solve(v_Nd); 
     cout << "x_Cholesky_ldlt =\n" << x_Cholesky_ldlt <<"\n"<< endl; 
     cout << "time use in Cholesky_ldlt composition is \n" << 1000* (clock() - time_stt)/(double) 
     CLOCKS_PER_SEC << "ms" <<"\n"<<endl; 
     
     return 0; 

}
