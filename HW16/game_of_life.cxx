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
#include "TSystem.h"
#include "TH2F.h"



#define N 100

using namespace std;


int main(int argc, char **argv){
  
  TRint theApp("App",&argc,argv);
  TCanvas *c=new TCanvas("c","c",1);
  gSystem -> ProcessEvents( );
  
  float P[N][N] , Pnew[N][N], tot;
  
  
  for (int i=0 ; i < N; i++){

    for (int j=0 ; j < N; j++){  

      P[i][j] = 0;
      Pnew[i][j] = 0;

    }
  }

  P[50][49] = 1;
  P[50][50] = 1;
  P[50][51] = 1;

  TH2F *h = new TH2F("h", "Conway's Game of Life", N, 0, N, N, 0, N);

  for (int gen = 0; gen < N/2; gen++){

  	for (int i=1 ; i < N-1; i++){
	  
    	for (int j=1 ; j < N-1; j++){
      
			tot = P[i-1][j] + P[i+1][j] + P[i][j-1] + P[i][j+1] + P[i-1][j-1] + P[i-1][j+1] + P[i+1][j-1] + P[i+1][j+1]; 
      
			if (tot==0 ||tot==1){
	
				Pnew[i][j] = 0;
      
			}
      
			if (tot==2){
	
				Pnew[i][j] = P[i][j];	
			}
      
			if (tot==3){
	
				Pnew[i][j] = 1;
			}
      
			if (tot>4){
				
				Pnew[i][j] = 0;
			}
			h -> SetBinContent(i, j, P[i][j]); 
		}
	}

	for (int i=0 ; i < N; i++){
    
		for (int j=0 ; j < N; j++){
      
			P[i][j] = Pnew[i][j];
		}
	}
      
	h->Draw("box");
	c->Update();
	h->Reset ();   
  
  }
  
  theApp.Run();
  return 0;
}









  
  
    

  

