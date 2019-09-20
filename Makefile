INC = -I/usr/local/include -I/usr/local/cuda/include/
LIB = -L/user/local/lib -L/usr/local/cuda/lib64/
NVCC = /usr/local/cuda/bin/nvcc
LIBS = -lcunit -lcudart -lcublas

all: runtest.c util.c asgn1b.cu
	$(NVCC) runtest.c util.c asgn1b.cu $(INC) $(LIB) $(LIBS) -o runtest 

clean:
	rm -rf runtest 


