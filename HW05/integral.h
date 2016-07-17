double sine(double x){

     return sin(x);

}

double cosine(double x){
        
     return cos(x);
}

double  x_squared(double x){
    
      return x * x;
}

double tangent(double x){

    return tan(x);
}
double rectangle_method(double (*function)(double), double min, double max, double n){

    
    double sum = 0;
    double i = 0;

    for(i = min; i <=max; i+=(max-min)/n){

         sum = sum + function(i) * (max - min)/n;
    
    }

    return sum;
}

double midpoint_method(double (*function)(double), double min, double max, double n){


    double sum =0, i = 0, y1 = 0, delta = 0;

    delta = (max - min)/n;

    for(i = min; i < max; i += delta){
    
        
        y1 = (function(i) + function(i+delta));

        sum = sum + y1/2 * delta;

    }

    return sum;
}

double trapezoid_method(double (*function)(double), double min, double max, double n){


    double sum =0, i = 0, y1 = 0, y2 = 0, delta = 0;

    delta = (max - min)/n;

    for(i = min; i < max; i += delta){
    
        
        y1 = function(i);
        y2 = function(i+delta);

        sum = sum + ((y1+y2)/2 * delta);

    }

    return sum;
}

