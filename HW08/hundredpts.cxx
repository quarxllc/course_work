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
using namespace std;

#define N 100


int main(int argc, char **argv){
    //ROOT stuff
    TRint theApp("App",&argc,argv);
   TCanvas *cl = new TCanvas("cl","Graph Draw Options", 200,10, 600, 400);

   double x[N], y[N];

   for(int i = 0; i < N; i++){

        x[i] = i * 0.1;
        y[i] = 10 * sin(x[i] + 0.2);

   }

    TGraph *gr = new TGraph(N,x,y);

    gr->Draw("*AP");

    TF1 *f = new TF1("fun","10*sin(x + 0.2)", 0 , 10);
    f-> Draw("same");

    theApp.Run();

}

