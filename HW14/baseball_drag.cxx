#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>


#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TRint.h"
#include "TF1.h"
#include "TAxis.h"
using namespace std;

#define NPOINTS 1000
#define g 9.81




int main( int argc, char **argv){

  TRint theApp("App",&argc,argv);
  TCanvas *c=new TCanvas("c","c",1);

  int t = 0;

    float time[NPOINTS]={0},
        x[NPOINTS]={0},
        y[NPOINTS]={0},
        v_x[NPOINTS]={0},
        v_y[NPOINTS]={0},
    	v[NPOINTS] = {0};

   
    float v0 = 49, dt = 0.01, drag = 0, vd = 35, delta = 5;

    //initial conditions
    v_x[0] = v0 * cos(45 * M_PI/180);

    v_y[0] = v0 * sin(45 * M_PI/180);

    x[0] = 0;

    y[0] = 1;


    for ( t = 0; t < NPOINTS; t++){

	v[t] = sqrt( pow( v_y[t], 2) + pow( v_x[t], 2));

	drag = 0.0039 + (0.0058/ (1 + exp(((v[t] - vd)/ delta))));
	    
        x[t+1] = x[t] + v_x[t] * dt;

        y[t+1] = y[t] + v_y[t] * dt;

        v_x[t+1] = v_x[t] - drag * v[t] * v_x[t] * dt;

        v_y[t+1] = v_y[t] - g * dt - drag * v_y[t] * v[t] * dt;

        time[t] = t * dt;

	if ( y[t+1] < 0)
		break;

    }
    //Graph Stuff
    
    c -> Divide(2,3);
    
    c->cd(1);
    TGraph *graph = new TGraph(NPOINTS, time, x);

        graph->Draw("AP*");

        graph->GetXaxis()->SetTitle("Time (s)");
        graph->GetYaxis()->SetTitle("X position");
    
    c->cd(2);
    TGraph *graph_2 = new TGraph(NPOINTS, time, y);

        graph_2->Draw("AP*");

        graph_2->GetXaxis()->SetTitle("Time (s)");
        graph_2->GetYaxis()->SetTitle("Y position");
    
    c->cd(3);
    TGraph *graph_3 = new TGraph(NPOINTS, time, v_x);

        graph_3->Draw("AP*");

        graph_3->GetXaxis()->SetTitle("Time (s)");
        graph_3->GetYaxis()->SetTitle("X Velocity (m/s)");

    c->cd(4);
    TGraph *graph_4 = new TGraph(NPOINTS, time, v_y);

        graph_4->Draw("AP*");

        graph_4->GetXaxis()->SetTitle("Time (s)");
        graph_4->GetYaxis()->SetTitle("Y Velocity (m/s)");

    c->cd(5);
    TGraph *graph_5 = new TGraph(NPOINTS, y, x);

        graph_5->Draw("AP*");

        graph_5->GetXaxis()->SetTitle("Y");
        graph_5->GetYaxis()->SetTitle("X");

    	c->Update();
  	theApp.Run();

      	return 0;
}
