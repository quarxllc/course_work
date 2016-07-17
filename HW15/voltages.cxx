#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>


#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TApplication.h"
#include "TRint.h"
#include "TF1.h"
#include "TAxis.h"

using namespace std;

#define N 7
#define N2 13

void make_array( float array[N][N], float old_array[N][N]);

void make_array_2( float array[N2][N2], float old_array[N2][N2]);

void make_array_3( float array[N2][N2], float old_array[N2][N2], float q[N2][N2]);
  
void print_array(float array[N][N]);

void voltage_calculations(float array[N][N], float old_array[N][N], float precision);

void voltage_calculations_2(float array[N2][N2], float old_array[N2][N2], float precision);

void voltage_calculations_3(float array[N2][N2], float old_array[N2][N2],float q[N2][N2], float precision);

void conversion(float array[N][N], float x[N * N], float y[N * N], float z[N * N]);

void conversion_2(float array[N2][N2], float x[N2 * N2], float y[N2 * N2], float z[N2 * N2]);


int main(int argc, char **argv){
    
    TRint theApp("App",&argc,argv);
    TCanvas *c = new TCanvas("c","c",1);
    
    
    float v[N][N], old_v[N][N], v2[N2][N2], v2_old[N2][N2], q[N2][N2];
    float x[N2 * N2], y[N2 * N2], z[N2 * N2];
    float precision = 10.0;
    
    make_array(v, old_v);
    //make_array_2(v2, v2_old);
    //make_array_3(v2, v2_old, q);
    
    print_array(v);
    //print_array(v2);
    voltage_calculations(v, old_v, precision);
    
    //voltage_calculations_2(v2, v2_old, precision);
    //voltage_calculations_3(v2, v2_old, q, precision);
    conversion(v, x, y, z);
    //conversion_2(v2, x, y, z);
    
    //print out graph with data on it
    
    TGraph2D *g = new TGraph2D( N * N, x, y, z);
    g->Draw("surf1");
    
    
    c->Update();
    
    theApp.Run();
    return 0;
}

void make_array( float array[N][N], float old_array[N][N]){
    
    for (int i = 0; i < N; i++){
        
        for (int j = 0; j < N; j++){
            
            
            if (i == 0){
                
                array[i][j] = -1 + 2.*j/(N-1);
                old_array[i][j] = array[i][j];
                
            }
            else if (i == N-1){
                
                array[i][j] = -1 + 2.*j/(N-1);
                old_array[i][j] = array[i][j];
                
            }
            else if (j == 0){
                
                array[i][j] = -1;
                old_array[i][j] = array[i][j];
                
            }
            
            else if (j == N - 1){
                
                array[i][j] = 1;
                old_array[i][j] = array[i][j];
                
            }
            
            else {
                
                array[i][j] = 0;
                old_array[i][j] = array[i][j];
                
            }
            
        }
    }
    
    
}

void print_array(float array[N][N]){
    
    for (int i = 0; i < N; i++){
        
        for (int j = 0; j < N; j++){
            
            cout << array[i][j] << " ";
            
            if (j == N - 1)
                
                cout << endl;
            
        }
    }
}


void voltage_calculations(float array[N][N], float old_array[N][N], float precision){
    
    while (precision > 1e-5){
        
        precision = 0;
        
        for (int i = 1; i < N-1; i++){
            
            for (int j = 1; j < N-1; j++){
                
                array[i][j] = (0.25) * ( old_array[i+1][j]
                                        + old_array[i-1][j]
                                        + old_array[i][j+1]
                                        + old_array[i][j-1]);
                
                precision = precision + abs(array[i][j] - old_array[i][j]);
                
                old_array[i][j] = array[i][j];
            }
        }
    }
}

void voltage_calculations_2(float array[N2][N2], float old_array[N2][N2], float q[N2][N2], float precision){
    
    while (precision > 1e-5){
        
        precision = 0;
        
        for (int i = 1; i < N2-1; i++){
            
            for (int j = 1; j < N2-1; j++){
                
                array[i][j] = (0.25) * ( old_array[i+1][j]
                                        + old_array[i-1][j]
                                        + old_array[i][j+1]
                                        + old_array[i][j-1]
                                        + q[i][j]);
                
                precision = precision + abs(array[i][j] - old_array[i][j]);
                
                old_array[i][j] = array[i][j];
            }
        }
    }
}

void voltage_calculations_2(float array[N2][N2], float old_array[N2][N2], float precision){
    
    while (precision > 1e-5){
        
        precision = 0;
        
        for (int i = 1; i < N2-1; i++){
            
            for (int j = 1; j < N2-1; j++){
                
                
                if ( (j == 4 || j == 8) && ( i >=4 && i <= 8) )
                
                    continue;
                
                else{
                array[i][j] = (0.25) * ( old_array[i+1][j]
                                        + old_array[i-1][j]
                                        + old_array[i][j+1]
                                        + old_array[i][j-1]);
                
                precision = precision + abs(array[i][j] - old_array[i][j]);
                
                old_array[i][j] = array[i][j];
                }
                
            }
        }
    }
}

void make_array_2( float array[N2][N2], float old_array[N2][N2]){
    
    for (int i = 0; i < N2; i++){
        
        for (int j = 0; j < N2; j++){
            
            if ((i >= 4 && i <= 8) && j == 4){
                
                array[i][j] = -1;
                old_array[i][j] = array[i][j];
            }
            
            else if ((i >= 4 && i <= 8) && j == 8){
                
                array[i][j] = 1;
                old_array[i][j] = array[i][j];
            }
            
            else {
                array[i][j] = 0;
                old_array[i][j] = array[i][j];
            }
            
        }
    }
}



void make_array_3( float array[N2][N2], float old_array[N2][N2],float q[N2][N2]){
    
    for (int i = 0; i < N2; i++){
        
        for (int j = 0; j < N2; j++){
            
            if ((i >= 4 && i <= 8) && j == 4){
                
                array[i][j] = -1;
                old_array[i][j] = array[i][j];
            }
            
            else if ((i >= 4 && i <= 8) && j == 8){
                
                array[i][j] = 1;
                old_array[i][j] = array[i][j];
            }
            
            else if (i == 4 && (j > 4 && j < 8)){
                
                array[i][j] = -1 + 2.*j/(N-1);
                old_array[i][j] = array[i][j];
            }
            
            else if (i==8 && (j>4 && j<8)){
                array[i][j] = -1 + 2.*j/(N-1);
                old_array[i][j] = array[i][j];
            }
            
            else if(i == 6 && j == 6){
                q[i][j] = 1;
            }
            
            else {
                
                array[i][j] = 0;
                old_array[i][j] = array[i][j];
                q[i][j] = 0;
            }
            
        }
    }
}

void conversion_2(float array[N2][N2], float x[N2 * N2], float y[N2 * N2], float z[N2 * N2]){
    
    for(int i = 0; i < N2; i++){
        
        for(int j = 0; j < N2; j++){
            
            x[j + N2 * i]= j;
            y[j + N2 * i]= i;
            z[j + N2 * i]= array[i][j];
        }
    }
}

void conversion(float array[N][N], float x[N * N], float y[N * N], float z[N * N]){
    
    for(int i = 0; i < N2; i++){
        
        for(int j = 0; j < N2; j++){
            
            x[j + N * i]= j;
            y[j + N * i]= i;
            z[j + N * i]= array[i][j];
        }
    }
}



