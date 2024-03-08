 #include<bits/stdc++.h>
using namespace std;

void printMatrix(double **mat, int rows, int cols)
{
      for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++){
                cout<<mat[i][j]<<" ";
                cout<<endl;
        }
    }

}
int main()
{
    string fileName_L="L_3.txt";
    string fileName_R="R_3.txt";

    ifstream fin;
    fin.open(fileName_L);
    
    int rows, cols;
    fin >> rows >> cols;

    cout <<"\n rows::"<< rows<<"\t cols::"<<cols<<endl;
    //dynamic memory allocation
    double mat[rows][cols];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<(cols-1);j++){
                fin>>mat[i][j];
        }
    }


     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<(cols-1);j++){
                cout<<mat[i][j]<<" ";
                
        }
    
    cout <<endl;
    }    
        fin.close();
        fin.open(fileName_R);
         for(int i=0;i<rows;i++){
                fin>>mat[i][cols-1];
        }
        cout<<"\n Augumented matrix is :: \n";
        for(int i=0; i<rows; i++)
        {
            for(int j=0;j<cols;j++){
                cout<<mat[i][j]<<" ";
            
            }
            cout<<endl;
        }
           fin.close();
    
        return 0;
        
}