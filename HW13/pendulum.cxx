#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TRint.h"
#include "TF1.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TFormula.h"
#include "TH2.h"
#include "TStyle.h"

#define g 9.81
#define NPOINTS 250

using namespace std;

int main ( int argc, char **argv ){

	TRint theApp ( "App", &argc, argv );

	  TCanvas *c=new TCanvas("c","c",1);

	    float time[NPOINTS]= {0}, o[NPOINTS]={10}, omega[NPOINTS]= {0};

	    float dt = .04;
	    float l= 1;

	     for (int t=0; t<NPOINTS-1; t++){

		        omega[t+1] = omega[t] - (g/l)*o[t]*dt;

			o[t+1] = o[t] + omega[t+1]*dt;

			time[t] = t * dt; 

	}   
	      
	      
	       c -> Divide (2,1);
	        
	       c-> cd(1);
	       TGraph *gr = new TGraph(NPOINTS, time, omega); 

		gr->Draw("AP*");

		gr->GetXaxis()->SetTitle("Time (s)"); 
		gr->GetYaxis()->SetTitle("X Position (m)");

		c -> cd(2);
		TGraph *gr2 = new TGraph(NPOINTS, time, o); 

		gr2->Draw("AP*");

		gr2->GetXaxis()->SetTitle("Time (s)"); 
		gr2->GetYaxis()->SetTitle("Y Position (m)");

		
		c->Update();
		theApp.Run();
		return 0;
}
		


