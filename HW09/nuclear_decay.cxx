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
#include "TAxis.h"//calls the taxis class which manages axis labels
using namespace std;

#define NPOINTS 100 // constant used throughout the program


// This is the function that governs nuclear decay points without knowing what
// the actual function is. Each Variable represents the numbers you will be
// entering at the bottom later. 
// dt - delta time
// tau - nuclear decay constant
// n - mass of the given substance 
float nuclear_decay(float dt, float tau, float n){

 
        return n - (n/tau) * dt; //return provides a way for us to read back the given function when we use it

}

int main(int argc, char **argv){
    //ROOT stuff
    TRint theApp("App",&argc,argv);
    //TCanvas *c = new TCanvas("c", "Graph Draw Options", 400, 400, 600, 400);

    float x[100], y[100]; // declaration of two arrays, x and y with 100 bits allocated to use
    int tau = 1; // nuclear decay constant, I kept this the same through out the program though you could name it anything
    float dt = .1; // delta time. once again kept the same so it looks cleaner
    int t; //interval that you will be increasing your time by
    float n = 10; //given mass of substance

    for (t=0; t < NPOINTS; t++){ // our loop that iterates to 100 pts based on the define
       
        x[t]= t * dt; // x-axis variable t * 0.01

        y[t] = n; // y-axis which runs the function "nuclear_decay" -- reference above using the subroutine defined

	//cout << n << "," << x[t] << "," << y[t] << endl;
	// ^^ this here is used to debug meaning, check, if all the variables
	// come out right, I have been having problems in the beginning so this
	// let me print out my 3 variables to make sure thats where the problem
	// actually was

        n = nuclear_decay(dt, tau, n); //this redefines n. you could do n = y[t] but I decided this is how I was going to do it.
       
    }
	
	TGraph *gr = new TGraph(NPOINTS, x, y); //graphs the x array and y array in the pointer *gr
    
	gr->Draw("AP*"); //draws the gr pointer

	gr->GetXaxis()->SetTitle("Time (s)"); //sets title for x-axis
	gr->GetYaxis()->SetTitle("Mass (g)"); //sets title for y-axis

        TF1 *f =new TF1("function","10*exp(-x/1)",0,10); //creates the nuclear decay function based on the actual result
    
       f->SetLineColor(4); 
    //^^ set color of line, not neccessary but nice
    
        f->Draw("same"); //redraws the graph with the actual function
        theApp.Run();
    
    return 0;


    // You could also do this using float *x = new float(n) and  
    // float *y = new float(n), benefits of this dynamic allocations
    // what we did is called static allocation, so if you ever surpassed 100 you
    // break your code. The option above lets you pick an n and if n is 1000
    // thats how many bits it will allocate. 
}

