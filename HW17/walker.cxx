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

const int N = 100;

int main(int argc, char **argv){
  
  TRint theApp("App",&argc,argv);
    
  TCanvas *c = new TCanvas(" "," ",1);
  
  
    float x[N], n[N], dt = 0.01, change;

    x[0] = 0;
  
    srandom(time(0));
    
  
  for (int i = 0; i < N-1; i++){
      
    n[i] = i * dt;
    
    change = random()/double(RAND_MAX);

    if (change < 0.5)
        
      x[i+1] = x[i] + 1;
      
    
    
    if (change > 0.5)
        
      x[i+1] = x[i] - 1;
      
    
  }
    
    TGraph *gr = new TGraph(N, n, x);
    
    gr->Draw("AP*");
    
    gr->GetXaxis()->SetTitle("Time (s)");
    gr->GetYaxis()->SetTitle("Walk (d)");
      
    c->Update();
    
    
    theApp.Run();
    
  
    return 0;
  
}
