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
#include "TH2F.h"
#include "TSystem.h"


#define N 100
#define nmax 10000
#define maxstep 1000
using namespace std;



int main(int argc, char **argv){

	TRint theApp("App",&argc,argv);
	TCanvas *c=new TCanvas("c","c",1);
	gSystem->ProcessEvents();
	float walk[N][N];
	int n; 


	int x = random()%100;
	int y = random()%100;


	unsigned seed=time(0);
	srandom(seed);
	TH2F *h=new TH2F("h","walk",N,0,N,N,0,N);

	for (int step = 0; step < N-1; step++){

		n = random()%4;

		if (n == 0){
			x = x + 1;
			y = y + 1;
			walk[x][y] = 1;
		}

		else if (n == 1){
			x = x + 1;
			y = y - 1;
			walk[x][y] = 1;
		}
		else if (n == 2){
			x = x - 1;
			y = y + 1;
			walk[x][y] = 1;
		}

		else if (n == 3){
			x = x - 1;
			y = y - 1;
			walk[x][y] = 1;
		}
		h -> SetBinContent (x, y, 1);
		h->Draw("box");
		c->Update();
	}

	h->Draw("box");
	c->Update();


	theApp.Run();


	return 0;

}
