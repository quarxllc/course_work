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

#define NPOINTS 250
#define g 9.81



int main(int argc, char **argv){

  TRint theApp("App",&argc,argv);
  TCanvas *c=new TCanvas("c","c",1);

  float time[NPOINTS]={0},
    under[NPOINTS]={0},
    critical[NPOINTS]={0},
    over[NPOINTS]={0},
    omega_under[NPOINTS]={0},
    omega_critical[NPOINTS]={0},
    omega_over[NPOINTS]={0},
    q[2] = {0.5, 1},
    f[3] = {0, 0.5, 5.2};
   
float dt = .04, l = 1, o = 2.61;

    under[0] = 10 * M_PI/180;
 
    over[0] = 30 * M_PI/180;
 
    critical[0] = 117 * M_PI/180;

	

 for (int t=0; t<NPOINTS-1; t++){
  
     time[t] = t * dt;

     omega_under[t+1] = omega_under[t] - (g/l) * sin(under[t]) * dt-q[0]*omega_under[t] * dt\
     + f[0] * sin( o * time[t]) * dt;

     under[t+1] = under[t] + omega_under[t+1] * dt;


     omega_critical[t+1] = omega_critical[t] - (g/l) * sin(critical[t]) * dt - q[0] * omega_critical[t] * dt\
     + f[1] * sin( o * time[t]) * dt;

     critical[t+1] = critical[t] + omega_critical[t+1] * dt;



     omega_over[t+1] = omega_over[t] - (g/l)*sin(over[t]) * dt - q[1] * omega_over[t] * dt\
     + f[2] * sin( o * time[t]) * dt;

     over[t+1] = over[t] + omega_over[t+1] * dt;

  
 }
 
        c -> Divide (3,3);
 
            c-> cd(1);
                TGraph *gr = new TGraph(NPOINTS, time, omega_under);

                gr->Draw("AP*");

                gr->GetXaxis()->SetTitle("Time (s)");
                gr->GetYaxis()->SetTitle("Velocity (m/s)");

            c -> cd(2);
                TGraph *gr2 = new TGraph(NPOINTS, time, under);

                gr2->Draw("AP*");

                gr2->GetXaxis()->SetTitle("Time (s)");
                gr2->GetYaxis()->SetTitle("Position (m)");

            c -> cd(3);
                TGraph *gr3 = new TGraph(NPOINTS, omega_under, under);
  
                gr3->Draw("AP*");

                gr3->GetXaxis()->SetTitle("Velocity (m/s)");
                gr3->GetYaxis()->SetTitle("Position (m)");


            c -> cd(4);
                TGraph *gr4 = new TGraph(NPOINTS, time, omega_critical);
  
                gr4->Draw("AP*");

                gr4->GetXaxis()->SetTitle("Time (s)");
                gr4->GetYaxis()->SetTitle("Velocity (m/s)");

            c -> cd(5);
                TGraph *gr5 = new TGraph(NPOINTS, time, critical);
  
                gr5->Draw("AP*");

                gr5->GetXaxis()->SetTitle("Time (s)");
                gr5->GetYaxis()->SetTitle("Position (m)");

  
            c -> cd(6);
                TGraph *gr6 = new TGraph(NPOINTS, omega_critical, critical);
  
                gr6->Draw("AP*");

                gr6->GetXaxis()->SetTitle("Velocity (m/s)");
                gr6->GetYaxis()->SetTitle("Position (m)");
    
            c -> cd(7);
                TGraph *gr7 = new TGraph(NPOINTS, time, omega_over);
  
                gr7->Draw("Al");

                gr7->GetXaxis()->SetTitle("Time (s)");
                gr7->GetYaxis()->SetTitle("Velocity (m/s)");
    
            c -> cd(8);
                TGraph *gr8 = new TGraph(NPOINTS, time, over);
  
                gr8->Draw("AP*");

                gr8->GetXaxis()->SetTitle("Time (s)");
                gr8->GetYaxis()->SetTitle("Position (m)");
  
            c -> cd(9);
                TGraph *gr9 = new TGraph(NPOINTS, omega_over, over);
  
                gr9->Draw("APl");

                gr9->GetXaxis()->SetTitle("Velocity (m/s)");
                gr9->GetYaxis()->SetTitle("Position (m)");

    c->Update();


  theApp.Run();
  return 0;
}
