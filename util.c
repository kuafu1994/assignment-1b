//
// Created by Zhang Pengfei on 10/1/2017.
//

#include<stdio.h>
#include<stdlib.h>
#include"util.h"


static float* generate_indep(int dim);
static float* generate_anti(int dim, float arg);
static float random_normal(float med, float var) ;
static float random_peak(float min, float max, int dim);
static float random_equal(float min, float max);
static int is_vector_ok(int dim, float *x);
extern int iter;

Point* generateDataset(int number, int dim, float arg, int seed) {

    Point * points = (Point*)malloc(sizeof(Point) * number);
	if(points == NULL)
	{
		printf("Cannot allocate memory for points.\n");
		return NULL;
	}
    int i, j;
	srand((unsigned int)seed);
    printf("\nGenerating %d-dimension point dataset, number of points in dataset = %d\n", dim, number);
	for(i = 0; i < number; i++) {
		points[i].ID = i + 1;
		points[i].values = generate_anti(dim, arg);
		if(points[i].values == NULL)
			return NULL;
	}
    
    return points;
}

static float* generate_anti(int dim, float arg) {
    float *x = (float*) malloc(sizeof(float) * dim);
	if(x == NULL)
	{
		printf("Cannot allocate memory for values of Point\n");
		return NULL;
	}
    do{
        int d;
        float v = random_normal(0.5, arg);
        float l = v <= 0.5 ? v : 1.0 - v;

        for(d = 0; d < dim; d++)
            x[d] = v;
        for(d = 0; d < dim; d++){
            float h = random_equal(-l, l);
            x[d] += h;
            x[(d + 1) % dim] -= h;
        }
    } while(!is_vector_ok(dim, x));

    return x;
}

static float random_normal(float med, float var) {
    return random_peak(med - var, med+var, 12);
}

static float random_peak(float min, float max, int dim) {
    int d;
    float sum = 0.0;

    for(d = 0; d < dim; d++) {
        sum += random_equal(0,1);
    }

    sum /= dim;
    return sum * (max - min) + min;
}

static int is_vector_ok(int dim, float *x){
    while(dim--){
        if(*x < 0.0 || *x > 1.0)
            return 0;
        x++;
    }

    return 1;
}




static float random_equal(float min, float max){
    float x = (float) rand() / RAND_MAX;
    return x * (max - min) + min;
}


void printPoint(Point a,int dim){
    printf("%d:", a.ID);
    int i;
    for(i = 0; i < dim-1; i++) {
        printf("%f,", a.values[i]);
        fflush(stdout);
    }
    printf("%f\n", a.values[dim-1]);
}

int cmpID(const void *a, const void *b){
    return (*(Point*) a).ID - (*(Point*)b).ID;
}

void resetEnvironment(Point* points, int number){
    qsort(points, number, sizeof(Point), cmpID);
}
