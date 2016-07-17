#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "TAxis.h"
#include <cmath>
#include <iomanip>
#include <cstdio>
#include "TApplication.h"
#include "TF1.h"
#include "TROOT.h"
#include "TRint.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TRint.h"
#include "TSystem.h"
#include "TH2F.h"

using namespace std;

const int N = 100;


int main(int argc, char **argv){

	TRint theApp("App",&argc,argv);
  
 	TCanvas *c1=new TCanvas("c1","Time vs. Distance",1);

 	c1->Divide(2,2);

 	int nwalkers = 500;


	 float x[N] = {0}, n[N] = {0}, x_sq_average[N] = {0}, x_average[N] = {0};

	 float delta = 1, a = 0.5, randomnumber;


	 x[0]=0;

 	for(int walkers = 0; walkers < nwalkers; walkers++){
 
 		for (int time = 0; time < N-1; time++){
   
 			unsigned seed=n[0];
 
			srandom(seed);

		    n[time+1]= delta * time;
 
			randomnumber=((double)rand()/(RAND_MAX));

			if(randomnumber < a)

   				x[time+1]=x[time]+1;

 			if(randomnumber >= a)

   				x[time+1]= x[time]-1;
 

 			x_average[time+1]= x_average[time+1] + x[time+1] / (500.);

 			x_sq_average[time+1]= x_sq_average[time+1] +(x[time+1] * x[time+1])/(500.);
 
			 	}
 

 			}
 
   			TGraph *gr1= new TGraph(N-1,n,x_average);
  			c1->cd(1);
  			gr1->Draw("AP*");
  			gr1->GetXaxis()->SetTitle("Time (s)");
  			gr1->GetYaxis()->SetTitle("Distance (m)");

  			TGraph *gr2= new TGraph(N-1,n,x_sq_average);
  			c1->cd(2);
  			gr2->Draw("AP*");
  			gr2->GetXaxis()->SetTitle("Time (s)");
  			gr2->GetYaxis()->SetTitle("Distance (m)");
 

  			c1->Update();
 			theApp.Run();

 	return 0;

}







