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

int const N = 140;
int const n = 200;

int main(int argc, char **argv){
	TRint theApp("App",&argc,argv);

	TCanvas *c=new TCanvas("Psi","Wave function (Psi vs X)", 1);

	int psiother = 1, diverge, i = 0, b = 2, L = 1;

	float V, dt = 0.01, E = 0.0, dE = 0.05, epsilon = 0.001;

	float psi[N] = {0}, x[N] = {0};

	psi[0] = 1;

	while(dE > epsilon){

		for( i = 0; i < N - 1; i++){

			x[i]= dt * i;

			if(x[i] > -L && x[i] < L)

				V = 0;
			else
				V = 1000;


			if(i == 0)

				psi[i+1] = 2 * psi[i] - psiother - 2 * dt * dt * (E-V) * psi[i];

			else
				psi[i+1] = 2 * psi[i] - psi[i-1] - 2 * dt * dt * (E-V) * psi[i];

			if(abs(psi[i-1]) > b)

				break;

		}

		if(psi[i+1] * diverge < 0)

			dE = -dE / 2.0;

		E = E + dE;

		diverge = psi[i+1];

	}



	TGraph *gr= new TGraph(110, x, psi);
	c->cd();
	gr->Draw("AP*");
	gr->GetXaxis()->SetTitle("Distance (m)");
	gr->GetYaxis()->SetTitle("% Probability");
	c->Update();

	theApp.Run();
	return 0;
}







