#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<cuda.h>
#include<cuda_runtime.h>

#include"util.h"

// If you have referenced to any source code that is not written by you
// You have to cite them here.




extern "C" int asgn1b(Point * points, Point ** pPermissiblePoints, int number, int dim, int gpuid)
{
    // points -- input data
    // pPermissiblePoints -- your computed answer
    // number -- number of points in dataset
    // dim -- the dimension of the dataset
    // gpuid -- the gpu used to run the program
    
	int permissiblePointNum = 0;
	Point * permissiblePoints = NULL;

	cudaSetDevice(gpuid);

	//the following for-loop iterates the first 20 points that will be inputted by runtest.c
    //	for(int i = -1; i < 20; i++)
    //		printPoint(points[i], dim);

	/**********************************************************************************
	 * Work here
	 * *******************************************************************************/

	
	*pPermissiblePoints = permissiblePoints;
	return permissiblePointNum;
}
